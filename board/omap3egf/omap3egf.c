/*
 * (C) Copyright 2006
 * Texas Instruments, <www.ti.com>
 * Jian Zhang <jzhang@ti.com>
 * Richard Woodruff <r-woodruff2@ti.com>
 * (C) Copyright 2011
 * Elettronica GF S.r.l, <www.elettronicagf.it>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <command.h>
#include <part.h>
#include <fat.h>
#include <asm/arch/cpu.h>
#include <asm/arch/bits.h>
#include <asm/arch/gpio.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/sys_info.h>
#include <asm/arch/clocks.h>
#include <asm/arch/mem.h>
#include <i2c.h>
#include "./muxtool/pinmux_1st_stage.h"
#include "./muxtool/pinmux_som336.h"

#ifdef CFG_3430SDRAM_DDR
void config_3430sdram_ddr(void);
#endif

void set_muxconf_complete(void);
void set_muxconf_just_to_load_eeprom(void);

#define CORE_DPLL_PARAM_M2	0x09
#define CORE_DPLL_PARAM_M	0x360
#define CORE_DPLL_PARAM_N	0xC


/* CPU types */
#define CPU_DM37XX	0x1
#define CPU_OMAP35XX	0x2

/* EEPROM */
#define EEPROM_I2C_BUS 2


/* SOM CODE */
#define REV_STR_TO_REV_CODE(REV_STRING) \
	(\
	(((REV_STRING[3]-'0')*1000 + (REV_STRING[4]-'0')*100+(REV_STRING[5]-'0')*10 + (REV_STRING[6]-'0')) << 16)|\
	((REV_STRING[8]-'A') << 8)|\
	((REV_STRING[9]-'0')*10 + (REV_STRING[10]-'0'))\
	)

#define SOM_REV_CODE(REV1,REV2,REV3)\
	((REV1<<16) | ((REV2-'A') << 8) |  REV3)

#define REV_NOT_PROGRAMMED  SOM_REV_CODE(((0xFF-'0')*1000 + (0xFF-'0')*100+(0xFF-'0')*10 + 0xff-'0'),'A',0xFF)

#define N_REVISIONS	4
char* revision_strings[N_REVISIONS]={
		"JSF0336_A01",
		"JSF0336_B01",
		"JSF0336_C01",
		"JSF0336_D01",
};

#define REV_336_A01  SOM_REV_CODE(336,'A',1)
#define REV_336_B01  SOM_REV_CODE(336,'B',1)
#define REV_336_C01  SOM_REV_CODE(336,'C',1)
#define REV_336_D01  SOM_REV_CODE(336,'D',1)


#define SOM_REVISION_LEN  12  /* termination character included. ex: JSC0336_A02*/


/* SDRAM CONSTANTS */
#define MICRON1	1	/* MT46H64M32LFMA_6 256 MB only BANK 0 */
#define SDRAM_DEFAULT	MICRON1



/*MICRON1 MT46H64M32LFMA_6*/
#define SDRC_MDCFG_0_DDR_EGF_MICRON1	(0x03588019|B_ALL)

#define EGF_SDRC_SHARING			0x00000100
#define EGF_SDRC_RFR_CTRL_200MHz	0x0005e601  /* 7.8us/5ns - 50=0x5e6 */
#define EGF_MICRON1_TDAL   6
#define EGF_MICRON1_TDPL   3
#define EGF_MICRON1_TRRD   2
#define EGF_MICRON1_TRCD   3
#define EGF_MICRON1_TRP    3
#define EGF_MICRON1_TRAS   7
#define EGF_MICRON1_TRC   10
#define EGF_MICRON1_TRFC  12
#define EGF_MICRON1_V_ACTIMA ((EGF_MICRON1_TRFC << 27) | (EGF_MICRON1_TRC << 22) | (EGF_MICRON1_TRAS << 18) \
		| (EGF_MICRON1_TRP << 15) | (EGF_MICRON1_TRCD << 12) |(EGF_MICRON1_TRRD << 9) | \
		(EGF_MICRON1_TDPL << 6) | (EGF_MICRON1_TDAL))
#define EGF_MICRON1_TWTR   1
#define EGF_MICRON1_TCKE   1
#define EGF_MICRON1_TXP    1
#define EGF_MICRON1_XSR    19
#define EGF_MICRON1_V_ACTIMB ((EGF_MICRON1_TCKE << 12) | (EGF_MICRON1_XSR << 0)) | \
				(EGF_MICRON1_TXP << 8) | (EGF_MICRON1_TWTR << 16)

#define BYPASS_REVISION_CHECK   -1

static __u32 egf_som_code;

/* Used to index into DPLL parameter tables */
struct dpll_param {
	unsigned int m;
	unsigned int n;
	unsigned int fsel;
	unsigned int m2;
};

typedef struct dpll_param dpll_param;

/* Following functions are exported from lowlevel_init.S */
extern dpll_param *get_mpu_dpll_param(void);
extern dpll_param *get_iva_dpll_param(void);
extern dpll_param *get_core_dpll_param(void);
extern dpll_param *get_per_dpll_param(void);

#define __raw_readl(a)		(*(volatile unsigned int *)(a))
#define __raw_writel(v, a)	(*(volatile unsigned int *)(a) = (v))
#define __raw_readw(a)		(*(volatile unsigned short *)(a))
#define __raw_writew(v, a)	(*(volatile unsigned short *)(a) = (v))

/*******************************************************
 * Routine: delay
 * Description: spinning delay to use before udelay works
 ******************************************************/
static inline void delay(unsigned long loops)
{
	__asm__ volatile ("1:\n" "subs %0, %1, #1\n"
			  "bne 1b":"=r" (loops):"0"(loops));
}

void udelay (unsigned long usecs) {
	delay(usecs);
}

void init_board_gpios(void)
{
	switch(egf_som_code){
		case REV_336_A01:
		case REV_336_C01:
		case REV_336_D01:
			/* Leave tvp5150 enable and reset pins in a consistent state */
			omap_request_gpio(163);
			omap_request_gpio(164);
			omap_set_gpio_direction(163,0);
			omap_set_gpio_direction(164,0);
			omap_set_gpio_dataout(163,1);
			omap_set_gpio_dataout(164,0);
			break;
			break;
		case REV_NOT_PROGRAMMED:
		default:
			return;
	}
	return;
}

/*****************************************
 * Routine: board_init
 * Description: Early hardware init.
 *****************************************/
int board_init(void)
{
	printf("Board init...\n");
	set_muxconf_complete();
	config_3430sdram_ddr();
	init_board_gpios();
	return 0;
}

/*************************************************************
 *  get_device_type(): tell if GP/HS/EMU/TST
 *************************************************************/
u32 get_device_type(void)
{
	int mode;
	mode = __raw_readl(CONTROL_STATUS) & (DEVICE_MASK);
	return mode >>= 8;
}

/************************************************
 * get_sysboot_value(void) - return SYS_BOOT[4:0]
 ************************************************/
u32 get_sysboot_value(void)
{
	int mode;
	mode = __raw_readl(CONTROL_STATUS) & (SYSBOOT_MASK);
	return mode;
}

/*************************************************************
 * Routine: get_mem_type(void) - returns the kind of memory connected
 * to GPMC that we are trying to boot form. Uses SYS BOOT settings.
 *************************************************************/
u32 get_mem_type(void)
{
	return GPMC_NONE;


}
static __u32 get_som_code(void)
{
	__u8 som_revision[SOM_REVISION_LEN];
	u32 som_code;
	int i;
	i2c_set_bus_num(EEPROM_I2C_BUS);
	printf("SOM REVISION=");
	for(i=0; i<SOM_REVISION_LEN-1; i++){
		if(i2c_read_byte_16bitoffset(0x50, i, &som_revision[i])){
			printf("\nEEPROM16 read Error\n");
		}
		else{
			printf("%c",som_revision[i]);
		}
	}
	som_revision[SOM_REVISION_LEN-1]=0; /* add termination character */
	printf("\n");
	som_code = REV_STR_TO_REV_CODE(som_revision);
	printf("HASH=%x\n",som_code);
	return som_code;
}
static void write_revision_to_eeprom(char* rev)
{
	int i;
	int ret;
	for(i=0; i< SOM_REVISION_LEN-1;i++){
		if((ret=i2c_write_byte_16bitoffset(0x50, i, rev[i]))){
					printf("EEPROM16 write Error %d %d\n",i, ret);
					hang();
		}
		udelay(10000000);
	}
	/* add newline character */
	if((ret=i2c_write_byte_16bitoffset(0x50, SOM_REVISION_LEN-1, '\n'))){
				printf("EEPROM16 write Error %d %d\n",i, ret);
				hang();
	}
}
static int select_revision_from_menu()
{
	int i;
	unsigned char c;
	int nrev;
	/* empty serial input fifo */
	if (serial_data_present_in_read_buffer())
		c = serial_getc();

	while (1) {
		printf("\n\n\n\n");
		for (i = 0; i < N_REVISIONS; i++) {
			printf("%d) %s [%x] \n", i+1, revision_strings[i],REV_STR_TO_REV_CODE(revision_strings[i]));
		}
		printf("%d) BYPASS CHECK\n", N_REVISIONS+1);
		printf("SELECT ITEM (1-%d)\n", N_REVISIONS+1);
		c = serial_getc();
		nrev = c - '1';
		if(nrev <  0 ||  nrev > N_REVISIONS )
			continue;
		else if (nrev==N_REVISIONS)
			return BYPASS_REVISION_CHECK;
		else {
			write_revision_to_eeprom(revision_strings[nrev]);
			return 0;
		}
	}



}
/* Check module revision from eeprom. If not found ask
 * the user to select from menu the right hw version
 */
int load_revision(void)
{

	while (1) {
		egf_som_code = get_som_code();
		switch (egf_som_code) {
		case REV_336_A01:
		case REV_336_B01:
		case REV_336_C01:
		case REV_336_D01:
			printf("SOM VALIDATED\n");
			return 0;
		case REV_NOT_PROGRAMMED:
		default:
			printf("EEPROM NOT PROGRAMMED!\n");
			if(select_revision_from_menu() == BYPASS_REVISION_CHECK)
				return 0;
			else
				continue;
		}
	}
	return 0;
}

u32 get_sdram_type(void)
{
	switch(egf_som_code){
	case REV_336_A01:
	case REV_336_B01:
	case REV_336_C01:
	case REV_336_D01:
		return MICRON1;
		break;
	case REV_NOT_PROGRAMMED:
	default:
		return SDRAM_DEFAULT;
	}
}

/******************************************
 * get_cpu_rev(void) - extract version info
 ******************************************/
u32 get_cpu_rev(void)
{
	u32 cpuid = 0;
	/* On ES1.0 the IDCODE register is not exposed on L4
	 * so using CPU ID to differentiate
	 * between ES2.0 and ES1.0.
	 */
	__asm__ __volatile__("mrc p15, 0, %0, c0, c0, 0":"=r" (cpuid));
	if ((cpuid  & 0xf) == 0x0)
		return CPU_3430_ES1;
	else
		return CPU_3430_ES2;

}

/******************************************
 * cpu_is_3410(void) - returns true for 3410
 ******************************************/
u32 cpu_is_3410(void)
{
	int status;
	if (get_cpu_rev() < CPU_3430_ES2) {
		return 0;
	} else {
		/* read scalability status and return 1 for 3410*/
		status = __raw_readl(CONTROL_SCALABLE_OMAP_STATUS);
		/* Check whether MPU frequency is set to 266 MHz which
		 * is nominal for 3410. If yes return true else false
		 */
		if (((status >> 8) & 0x3) == 0x2)
			return 1;
		else
			return 0;
	}
}

/******************************************
 * gfsom336 cpu identify
 * returns cpu model mounted on board
 ******************************************/
int gfsom_cpu_type(void)
{
	u32 revision;
	revision = __raw_readl(CONTROL_IDCODE);
	revision = revision & 0x0FFFFFFF;
	if (revision == 0xB89102F) {
		return CPU_DM37XX;
	} else {
		return CPU_OMAP35XX;
	}
}

/*****************************************************************
 * sr32 - clear & set a value in a bit range for a 32 bit address
 *****************************************************************/
void sr32(u32 addr, u32 start_bit, u32 num_bits, u32 value)
{
	u32 tmp, msk = 0;
	msk = 1 << num_bits;
	--msk;
	tmp = __raw_readl(addr) & ~(msk << start_bit);
	tmp |= value << start_bit;
	__raw_writel(tmp, addr);
}

/*********************************************************************
 * wait_on_value() - common routine to allow waiting for changes in
 *   volatile regs.
 *********************************************************************/
u32 wait_on_value(u32 read_bit_mask, u32 match_value, u32 read_addr, u32 bound)
{
	u32 i = 0, val;
	do {
		++i;
		val = __raw_readl(read_addr) & read_bit_mask;
		if (val == match_value)
			return 1;
		if (i == bound)
			return 0;
	} while (1);
}

#ifdef CFG_3430SDRAM_DDR
void config_3430sdram_ddr(void)
{
	switch (get_sdram_type()) {
	case  MICRON1:

	/* reset sdrc controller */
		__raw_writel(SOFTRESET, SDRC_SYSCONFIG);
		wait_on_value(BIT0, BIT0, SDRC_STATUS, 12000000);
		__raw_writel(0, SDRC_SYSCONFIG);

		/* setup sdrc to ball mux */
		__raw_writel(EGF_SDRC_SHARING, SDRC_SHARING);

		__raw_writel(0x2, SDRC_CS_CFG);
		/* 256MB/bank */
		__raw_writel(SDRC_MDCFG_0_DDR_EGF_MICRON1, SDRC_MCFG_0);
		__raw_writel(SDRC_MDCFG_0_DDR_EGF_MICRON1, SDRC_MCFG_1);
		__raw_writel(EGF_MICRON1_V_ACTIMA, SDRC_ACTIM_CTRLA_0);
		__raw_writel(EGF_MICRON1_V_ACTIMB, SDRC_ACTIM_CTRLB_0);
		__raw_writel(EGF_MICRON1_V_ACTIMA, SDRC_ACTIM_CTRLA_1);
		__raw_writel(EGF_MICRON1_V_ACTIMB, SDRC_ACTIM_CTRLB_1);
		__raw_writel(SDP_3430_SDRC_RFR_CTRL_200MHz, SDRC_RFR_CTRL_0);
		__raw_writel(SDP_3430_SDRC_RFR_CTRL_200MHz, SDRC_RFR_CTRL_1);

		__raw_writel(SDP_SDRC_POWER_POP, SDRC_POWER);

		/* init sequence for mDDR/mSDR using manual commands (DDR is different) */
		__raw_writel(CMD_NOP, SDRC_MANUAL_0);
		__raw_writel(CMD_NOP, SDRC_MANUAL_1);

		delay(5000);

		__raw_writel(CMD_PRECHARGE, SDRC_MANUAL_0);
		__raw_writel(CMD_PRECHARGE, SDRC_MANUAL_1);

		__raw_writel(CMD_AUTOREFRESH, SDRC_MANUAL_0);
		__raw_writel(CMD_AUTOREFRESH, SDRC_MANUAL_1);

		__raw_writel(CMD_AUTOREFRESH, SDRC_MANUAL_0);
		__raw_writel(CMD_AUTOREFRESH, SDRC_MANUAL_1);

		/* set mr0 */
		__raw_writel(SDP_SDRC_MR_0_DDR, SDRC_MR_0);
		__raw_writel(SDP_SDRC_MR_0_DDR, SDRC_MR_1);

		/* set up dll */
		__raw_writel(SDP_SDRC_DLLAB_CTRL, SDRC_DLLA_CTRL);
		delay(0x2000); /* give time to lock */
		break;
	default:
		printf("RAM NOT SUPPORTED!\n");
		hang();
	}
}
#endif /* CFG_3430SDRAM_DDR */

/*************************************************************
 * get_sys_clk_speed - determine reference oscillator speed
 *  based on known 32kHz clock and gptimer.
 *************************************************************/
u32 get_osc_clk_speed(void)
{
	u32 start, cstart, cend, cdiff, cdiv, val;

	val = __raw_readl(PRM_CLKSRC_CTRL);

	if (val & SYSCLKDIV_2)
		cdiv = 2;
	else
		cdiv = 1;

	/* enable timer2 */
	val = __raw_readl(CM_CLKSEL_WKUP) | BIT0;
	__raw_writel(val, CM_CLKSEL_WKUP);	/* select sys_clk for GPT1 */

	/* Enable I and F Clocks for GPT1 */
	val = __raw_readl(CM_ICLKEN_WKUP) | BIT0 | BIT2;
	__raw_writel(val, CM_ICLKEN_WKUP);
	val = __raw_readl(CM_FCLKEN_WKUP) | BIT0;
	__raw_writel(val, CM_FCLKEN_WKUP);

	__raw_writel(0, OMAP34XX_GPT1 + TLDR);		/* start counting at 0 */
	__raw_writel(GPT_EN, OMAP34XX_GPT1 + TCLR);	/* enable clock */
	/* enable 32kHz source */
	/* enabled out of reset */
	/* determine sys_clk via gauging */

	start = 20 + __raw_readl(S32K_CR);	/* start time in 20 cycles */
	while (__raw_readl(S32K_CR) < start) ;	/* dead loop till start time */
	cstart = __raw_readl(OMAP34XX_GPT1 + TCRR);	/* get start sys_clk count */
	while (__raw_readl(S32K_CR) < (start + 20)) ;	/* wait for 40 cycles */
	cend = __raw_readl(OMAP34XX_GPT1 + TCRR);	/* get end sys_clk count */
	cdiff = cend - cstart;	/* get elapsed ticks */
	cdiff *= cdiv;

	/* based on number of ticks assign speed */
	if (cdiff > 19000)
		return S38_4M;
	else if (cdiff > 15200)
		return S26M;
	else if (cdiff > 13000)
		return S24M;
	else if (cdiff > 9000)
		return S19_2M;
	else if (cdiff > 7600)
		return S13M;
	else
		return S12M;
}

/******************************************************************************
 * get_sys_clkin_sel() - returns the sys_clkin_sel field value based on
 *   -- input oscillator clock frequency.
 *
 *****************************************************************************/
void get_sys_clkin_sel(u32 osc_clk, u32 *sys_clkin_sel)
{
	if (osc_clk == S38_4M)
		*sys_clkin_sel = 4;
	else if (osc_clk == S26M)
		*sys_clkin_sel = 3;
	else if (osc_clk == S19_2M)
		*sys_clkin_sel = 2;
	else if (osc_clk == S13M)
		*sys_clkin_sel = 1;
	else if (osc_clk == S12M)
		*sys_clkin_sel = 0;
}

/******************************************************************************
 * prcm_init() - inits clocks for PRCM as defined in clocks.h
 *   -- called from SRAM, or Flash (using temp SRAM stack).
 *****************************************************************************/
void prcm_init(void)
{
	u32 osc_clk = 0, sys_clkin_sel;
	dpll_param *dpll_param_p;
	u32 clk_index, sil_index;

	/* Gauge the input clock speed and find out the sys_clkin_sel
	 * value corresponding to the input clock.
	 */
	osc_clk = get_osc_clk_speed();
	get_sys_clkin_sel(osc_clk, &sys_clkin_sel);

	sr32(PRM_CLKSEL, 0, 3, sys_clkin_sel);	/* set input crystal speed */

	/* If the input clock is greater than 19.2M always divide/2 */
	if (sys_clkin_sel > 2) {
		sr32(PRM_CLKSRC_CTRL, 6, 2, 2);	/* input clock divider */
		clk_index = sys_clkin_sel / 2;
	} else {
		sr32(PRM_CLKSRC_CTRL, 6, 2, 1);	/* input clock divider */
		clk_index = sys_clkin_sel;
	}

	sr32(PRM_CLKSRC_CTRL, 0, 2, 0);/* Bypass mode: T2 inputs a square clock */

	/* The DPLL tables are defined according to sysclk value and
	 * silicon revision. The clk_index value will be used to get
	 * the values for that input sysclk from the DPLL param table
	 * and sil_index will get the values for that SysClk for the
	 * appropriate silicon rev.
	 */
	sil_index = get_cpu_rev() - 1;

	/* Unlock MPU DPLL (slows things down, and needed later) */
	sr32(CM_CLKEN_PLL_MPU, 0, 3, PLL_LOW_POWER_BYPASS);
	wait_on_value(BIT0, 0, CM_IDLEST_PLL_MPU, LDELAY);

	/* Getting the base address of Core DPLL param table */
	dpll_param_p = (dpll_param *) get_core_dpll_param();
	/* Moving it to the right sysclk and ES rev base */
	dpll_param_p = dpll_param_p + 3 * clk_index + sil_index;
	/* CORE DPLL */
	/* sr32(CM_CLKSEL2_EMU) set override to work when asleep */
	sr32(CM_CLKEN_PLL, 0, 3, PLL_FAST_RELOCK_BYPASS);
	wait_on_value(BIT0, 0, CM_IDLEST_CKGEN, LDELAY);

	 /* For 3430 ES1.0 Errata 1.50, default value directly doesnt
	work. write another value and then default value. */
	sr32(CM_CLKSEL1_EMU, 16, 5, CORE_M3X2 + 1);     /* m3x2 */
	sr32(CM_CLKSEL1_EMU, 16, 5, CORE_M3X2);	/* m3x2 */
	sr32(CM_CLKSEL1_PLL, 27, 2, dpll_param_p->m2);	/* Set M2 */
	sr32(CM_CLKSEL1_PLL, 16, 11, dpll_param_p->m);	/* Set M */
	sr32(CM_CLKSEL1_PLL, 8, 7, dpll_param_p->n);	/* Set N */
	sr32(CM_CLKSEL1_PLL, 6, 1, 0);	/* 96M Src */
	sr32(CM_CLKSEL_CORE, 8, 4, CORE_SSI_DIV);	/* ssi */
	sr32(CM_CLKSEL_CORE, 4, 2, CORE_FUSB_DIV);	/* fsusb */
	sr32(CM_CLKSEL_CORE, 2, 2, CORE_L4_DIV);	/* l4 */
	sr32(CM_CLKSEL_CORE, 0, 2, CORE_L3_DIV);	/* l3 */
	sr32(CM_CLKSEL_GFX, 0, 3, GFX_DIV);	/* gfx */
	sr32(CM_CLKSEL_WKUP, 1, 2, WKUP_RSM);	/* reset mgr */
	sr32(CM_CLKEN_PLL, 4, 4, dpll_param_p->fsel);	/* FREQSEL */
	sr32(CM_CLKEN_PLL, 0, 3, PLL_LOCK);	/* lock mode */
	wait_on_value(BIT0, 1, CM_IDLEST_CKGEN, LDELAY);

	/* Getting the base address to PER  DPLL param table */
	dpll_param_p = (dpll_param *) get_per_dpll_param();
	/* Moving it to the right sysclk base */
	dpll_param_p = dpll_param_p + clk_index;
	/* PER DPLL */
	sr32(CM_CLKEN_PLL, 16, 3, PLL_STOP);
	wait_on_value(BIT1, 0, CM_IDLEST_CKGEN, LDELAY);
	sr32(CM_CLKSEL1_EMU, 24, 5, PER_M6X2);	/* set M6 */
	sr32(CM_CLKSEL_CAM, 0, 5, PER_M5X2);	/* set M5 */
	sr32(CM_CLKSEL_DSS, 0, 5, PER_M4X2);	/* set M4 */
	sr32(CM_CLKSEL_DSS, 8, 5, PER_M3X2);	/* set M3 */

	if (gfsom_cpu_type() == CPU_DM37XX) {
	        sr32(CM_CLKSEL3_PLL, 0, 5, CORE_DPLL_PARAM_M2);   /* set M2 */
	        sr32(CM_CLKSEL2_PLL, 8, 11, CORE_DPLL_PARAM_M);   /* set m */
	        sr32(CM_CLKSEL2_PLL, 0, 7, CORE_DPLL_PARAM_N);    /* set n */
	} else {
		sr32(CM_CLKSEL3_PLL, 0, 5, dpll_param_p->m2);	/* set M2 */
		sr32(CM_CLKSEL2_PLL, 8, 11, dpll_param_p->m);	/* set m */
		sr32(CM_CLKSEL2_PLL, 0, 7, dpll_param_p->n);	/* set n */
	}

	sr32(CM_CLKEN_PLL, 20, 4, dpll_param_p->fsel);	/* FREQSEL */
	sr32(CM_CLKEN_PLL, 16, 3, PLL_LOCK);	/* lock mode */
	wait_on_value(BIT1, 2, CM_IDLEST_CKGEN, LDELAY);

	/* Getting the base address to MPU DPLL param table */
	dpll_param_p = (dpll_param *) get_mpu_dpll_param();

	/* Moving it to the right sysclk and ES rev base */
	dpll_param_p = dpll_param_p + 3 * clk_index + sil_index;

	/* MPU DPLL (unlocked already) */
	sr32(CM_CLKSEL2_PLL_MPU, 0, 5, dpll_param_p->m2);	/* Set M2 */
	sr32(CM_CLKSEL1_PLL_MPU, 8, 11, dpll_param_p->m);	/* Set M */
	sr32(CM_CLKSEL1_PLL_MPU, 0, 7, dpll_param_p->n);	/* Set N */
	sr32(CM_CLKEN_PLL_MPU, 4, 4, dpll_param_p->fsel);	/* FREQSEL */
	sr32(CM_CLKEN_PLL_MPU, 0, 3, PLL_LOCK);	/* lock mode */
	wait_on_value(BIT0, 1, CM_IDLEST_PLL_MPU, LDELAY);

	/* Getting the base address to IVA DPLL param table */
	dpll_param_p = (dpll_param *) get_iva_dpll_param();
	/* Moving it to the right sysclk and ES rev base */
	dpll_param_p = dpll_param_p + 3 * clk_index + sil_index;
	/* IVA DPLL (set to 12*20=240MHz) */
	sr32(CM_CLKEN_PLL_IVA2, 0, 3, PLL_STOP);
	wait_on_value(BIT0, 0, CM_IDLEST_PLL_IVA2, LDELAY);
	sr32(CM_CLKSEL2_PLL_IVA2, 0, 5, dpll_param_p->m2);	/* set M2 */
	sr32(CM_CLKSEL1_PLL_IVA2, 8, 11, dpll_param_p->m);	/* set M */
	sr32(CM_CLKSEL1_PLL_IVA2, 0, 7, dpll_param_p->n);	/* set N */
	sr32(CM_CLKEN_PLL_IVA2, 4, 4, dpll_param_p->fsel);	/* FREQSEL */
	sr32(CM_CLKEN_PLL_IVA2, 0, 3, PLL_LOCK);	/* lock mode */
	wait_on_value(BIT0, 1, CM_IDLEST_PLL_IVA2, LDELAY);

	/* Set up GPTimers to sys_clk source only */
	sr32(CM_CLKSEL_PER, 0, 8, 0xff);
	sr32(CM_CLKSEL_WKUP, 0, 1, 1);

	delay(5000);
}

/*****************************************
 * Routine: secure_unlock
 * Description: Setup security registers for access
 * (GP Device only)
 *****************************************/
void secure_unlock(void)
{
	/* Permission values for registers -Full fledged permissions to all */
#define UNLOCK_1 0xFFFFFFFF
#define UNLOCK_2 0x00000000
#define UNLOCK_3 0x0000FFFF
	/* Protection Module Register Target APE (PM_RT) */
	__raw_writel(UNLOCK_1, RT_REQ_INFO_PERMISSION_1);
	__raw_writel(UNLOCK_1, RT_READ_PERMISSION_0);
	__raw_writel(UNLOCK_1, RT_WRITE_PERMISSION_0);
	__raw_writel(UNLOCK_2, RT_ADDR_MATCH_1);

	__raw_writel(UNLOCK_3, GPMC_REQ_INFO_PERMISSION_0);
	__raw_writel(UNLOCK_3, GPMC_READ_PERMISSION_0);
	__raw_writel(UNLOCK_3, GPMC_WRITE_PERMISSION_0);

	__raw_writel(UNLOCK_3, OCM_REQ_INFO_PERMISSION_0);
	__raw_writel(UNLOCK_3, OCM_READ_PERMISSION_0);
	__raw_writel(UNLOCK_3, OCM_WRITE_PERMISSION_0);
	__raw_writel(UNLOCK_2, OCM_ADDR_MATCH_2);

	/* IVA Changes */
	__raw_writel(UNLOCK_3, IVA2_REQ_INFO_PERMISSION_0);
	__raw_writel(UNLOCK_3, IVA2_READ_PERMISSION_0);
	__raw_writel(UNLOCK_3, IVA2_WRITE_PERMISSION_0);

	__raw_writel(UNLOCK_1, SMS_RG_ATT0);	/* SDRC region 0 public */
}

/**********************************************************
 * Routine: try_unlock_sram()
 * Description: If chip is GP type, unlock the SRAM for
 *  general use.
 ***********************************************************/
void try_unlock_memory(void)
{
	int mode;

	/* if GP device unlock device SRAM for general use */
	/* secure code breaks for Secure/Emulation device - HS/E/T */
	mode = get_device_type();
	if (mode == GP_DEVICE)
		secure_unlock();
	return;
}

/**********************************************************
 * Routine: s_init
 * Description: Does early system init of muxing and clocks.
 * - Called at time when only stack is available.
 **********************************************************/

void s_init(void)
{
	watchdog_init();
#ifdef CONFIG_3430_AS_3410
	/* setup the scalability control register for
	 * 3430 to work in 3410 mode
	 */
	__raw_writel(0x5ABF, CONTROL_SCALABLE_OMAP_OCP);
#endif
	try_unlock_memory();
	set_muxconf_just_to_load_eeprom();
	delay(100);
	per_clocks_enable();
	prcm_init();
}

/*******************************************************
 * Routine: misc_init_r
 * Description: Init ethernet (done here so udelay works)
 ********************************************************/
int misc_init_r(void)
{
	int rev;
	rev = gfsom_cpu_type();
	switch (rev) {
	case CPU_DM37XX:
		printf("eGF SOM - DM37XX board\n");
		break;
	case CPU_OMAP35XX:
		printf("eGF SOM - OMAP35XX board\n");
		break;
	default:
		printf("eGF SOM unknown cpu");
	}

	get_sdram_type();

	return 0;
}

/******************************************************
 * Routine: wait_for_command_complete
 * Description: Wait for posting to finish on watchdog
 ******************************************************/
void wait_for_command_complete(unsigned int wd_base)
{
	int pending = 1;
	do {
		pending = __raw_readl(wd_base + WWPS);
	} while (pending);
}

/****************************************
 * Routine: watchdog_init
 * Description: Shut down watch dogs
 *****************************************/
void watchdog_init(void)
{
	/* There are 3 watch dogs WD1=Secure, WD2=MPU, WD3=IVA. WD1 is
	 * either taken care of by ROM (HS/EMU) or not accessible (GP).
	 * We need to take care of WD2-MPU or take a PRCM reset.  WD3
	 * should not be running and does not generate a PRCM reset.
	 */
	sr32(CM_FCLKEN_WKUP, 5, 1, 1);
	sr32(CM_ICLKEN_WKUP, 5, 1, 1);
	wait_on_value(BIT5, 0x20, CM_IDLEST_WKUP, 5);	/* some issue here */

	__raw_writel(WD_UNLOCK1, WD2_BASE + WSPR);
	wait_for_command_complete(WD2_BASE);
	__raw_writel(WD_UNLOCK2, WD2_BASE + WSPR);
}

/**********************************************
 * Routine: dram_init
 * Description: sets uboots idea of sdram size
 **********************************************/
int dram_init(void)
{
	return 0;
}

/*****************************************************************
 * Routine: peripheral_enable
 * Description: Enable the clks & power for perifs (GPT2, UART1,...)
 ******************************************************************/
void per_clocks_enable(void)
{
	/* Enable GP2 timer. */
	sr32(CM_CLKSEL_PER, 0, 1, 0x1);	/* GPT2 = sys clk */
	sr32(CM_ICLKEN_PER, 3, 1, 0x1);	/* ICKen GPT2 */
	sr32(CM_FCLKEN_PER, 3, 1, 0x1);	/* FCKen GPT2 */

#ifdef CFG_NS16550
	/* UART1 clocks */
	sr32(CM_FCLKEN1_CORE, 13, 1, 0x1);
	sr32(CM_ICLKEN1_CORE, 13, 1, 0x1);

	/* UART 3 Clocks */
	sr32(CM_FCLKEN_PER, 11, 1, 0x1);
	sr32(CM_ICLKEN_PER, 11, 1, 0x1);

#endif

#ifdef CONFIG_DRIVER_OMAP34XX_I2C
	/* Turn on all 3 I2C clocks */
	sr32(CM_FCLKEN1_CORE, 15, 3, 0x7);
	sr32(CM_ICLKEN1_CORE, 15, 3, 0x7);	/* I2C1,2,3 = on */
#endif

	/* Enable the ICLK for 32K Sync Timer as its used in udelay */
	sr32(CM_ICLKEN_WKUP, 2, 1, 0x1);

	sr32(CM_FCLKEN_IVA2, 0, 32, FCK_IVA2_ON);
	sr32(CM_FCLKEN1_CORE, 0, 32, FCK_CORE1_ON);
	sr32(CM_ICLKEN1_CORE, 0, 32, ICK_CORE1_ON);
	sr32(CM_ICLKEN2_CORE, 0, 32, ICK_CORE2_ON);
	sr32(CM_FCLKEN_WKUP, 0, 32, FCK_WKUP_ON);
	sr32(CM_ICLKEN_WKUP, 0, 32, ICK_WKUP_ON);
	sr32(CM_FCLKEN_DSS, 0, 32, FCK_DSS_ON);
	sr32(CM_ICLKEN_DSS, 0, 32, ICK_DSS_ON);
	sr32(CM_FCLKEN_CAM, 0, 32, FCK_CAM_ON);
	sr32(CM_ICLKEN_CAM, 0, 32, ICK_CAM_ON);
	sr32(CM_FCLKEN_PER, 0, 32, FCK_PER_ON);
	sr32(CM_ICLKEN_PER, 0, 32, ICK_PER_ON);

	/* Enable GPIO5 clocks for blinky LEDs */
	sr32(CM_FCLKEN_PER, 16, 1, 0x1);	/* FCKen GPIO5 */
	sr32(CM_ICLKEN_PER, 16, 1, 0x1);	/* ICKen GPIO5 */

	delay(1000);
}


void set_muxconf_just_to_load_eeprom(void)
{
	MUX_1ST_STAGE()
}

void set_muxconf_complete(void)
{
	switch (egf_som_code) {
	case REV_336_A01:
	case REV_336_B01:
	case REV_336_C01:
	case REV_336_D01:
		MUX_SOM336()
		break;
	default:
		printf("No Muxing Info!\n");
	}
}

/**********************************************************
 * Routine: nand+_init
 * Description: Set up nand for nand and jffs2 commands
 *********************************************************/

int nand_init(void)
{
	return 0;
}



/* optionally do something like blinking LED */
void board_hang(void)
{
	while (1);
}

/******************************************************************************
 * Dummy function to handle errors for EABI incompatibility
 *****************************************************************************/
void raise(void)
{
}

/******************************************************************************
 * Dummy function to handle errors for EABI incompatibility
 *****************************************************************************/
void abort(void)
{
}
