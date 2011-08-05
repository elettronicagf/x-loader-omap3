/*
* (C) Copyright 2011
* Texas Instruments, <www.ti.com>
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

#ifndef _PINMUX_H_
#define _PINMUX_H_

/*
 * M0 - Mux mode 0
 * M1 - Mux mode 1
 * M2 - Mux mode 2
 * M3 - Mux mode 3
 * M4 - Mux mode 4
 * M5 - Mux mode 5
 * M6 - Mux mode 6
 * M7 - Mux mode 7
 * IDIS - Input disabled
 * IEN - Input enabled
 * PD - Active-mode pull-down enabled
 * PU - Active-mode pull-up enabled
 * PI - Active-mode pull inhibited
 * SB_LOW - Standby mode configuration: Output low-level
 * SB_HI - Standby mode configuration: Output high-level
 * SB_HIZ - Standby mode configuration: Output hi-impedence
 * SB_PD - Standby mode pull-down enabled
 * SB_PU - Standby mode pull-up enabled
 * WKEN - Wakeup input enabled
 */

#define MUX_EVM() \
MUX_VAL(CONTROL_PADCONF_GPIO_112, (IEN | PI | SB_HIZ | M4 )) /* gpio_112 */\
MUX_VAL(CONTROL_PADCONF_GPIO_113, (IEN | PI | SB_HIZ | M4 )) /* gpio_113 */\
MUX_VAL(CONTROL_PADCONF_GPIO_114, (IEN | PI | SB_HIZ | WKEN | M4 )) /* gpio_114 */\
MUX_VAL(CONTROL_PADCONF_GPIO_115, (IEN | PU | SB_HIZ | M4 )) /* gpio_115 */\
MUX_VAL(CONTROL_PADCONF_CAM_D0, (IEN | PI | SB_HIZ | M0 )) /* cam_d0 */\
MUX_VAL(CONTROL_PADCONF_CAM_D1, (IEN | PI | SB_HIZ | M0 )) /* cam_d1 */\
MUX_VAL(CONTROL_PADCONF_CAM_D2, (IEN | PI | SB_HIZ | M0 )) /* cam_d2 */\
MUX_VAL(CONTROL_PADCONF_CAM_D3, (IEN | PI | SB_HIZ | M0 )) /* cam_d3 */\
MUX_VAL(CONTROL_PADCONF_CAM_D4, (IEN | PI | SB_HIZ | M0 )) /* cam_d4 */\
MUX_VAL(CONTROL_PADCONF_CAM_D5, (IEN | PI | SB_HIZ | M0 )) /* cam_d5 */\
MUX_VAL(CONTROL_PADCONF_CAM_D6, (IEN | PI | SB_HIZ | M0 )) /* cam_d6 */\
MUX_VAL(CONTROL_PADCONF_CAM_D7, (IEN | PI | SB_HIZ | M0 )) /* cam_d7 */\
MUX_VAL(CONTROL_PADCONF_CAM_D8, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D9, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D10, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_D11, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_FLD, (IDIS | PD | M4 )) /* gpio_98 */\
MUX_VAL(CONTROL_PADCONF_CAM_HS, (IEN | PU | SB_HIZ | M4 )) /* gpio_94 */\
MUX_VAL(CONTROL_PADCONF_CAM_PCLK, (IEN | PU | SB_HIZ | M0 )) /* cam_pclk */\
MUX_VAL(CONTROL_PADCONF_CAM_STROBE, (IEN | PD | SB_HIZ | SB_PD | M4 )) /* gpio_126 */\
MUX_VAL(CONTROL_PADCONF_CAM_VS, (IEN | PU | SB_HIZ | SB_PU | M0 )) /* cam_vs */\
MUX_VAL(CONTROL_PADCONF_CAM_WEN, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_XCLKA, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_CAM_XCLKB, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_DSS_ACBIAS, (IDIS | PD | M0 )) /* dss_acbias */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA0, (IDIS | PD | M0 )) /* dss_data0 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA1, (IDIS | PD | M0 )) /* dss_data1 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA2, (IDIS | PD | M0 )) /* dss_data2 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA3, (IDIS | PD | M0 )) /* dss_data3 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA4, (IDIS | PD | M0 )) /* dss_data4 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA5, (IDIS | PD | M0 )) /* dss_data5 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA6, (IDIS | PD | M0 )) /* dss_data6 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA7, (IDIS | PD | M0 )) /* dss_data7 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA8, (IDIS | PD | M0 )) /* dss_data8 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA9, (IDIS | PD | M0 )) /* dss_data9 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA10, (IDIS | PD | M0 )) /* dss_data10 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA11, (IDIS | PD | M0 )) /* dss_data11 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA12, (IDIS | PD | M0 )) /* dss_data12 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA13, (IDIS | PD | M0 )) /* dss_data13 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA14, (IDIS | PD | M0 )) /* dss_data14 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA15, (IDIS | PD | M0 )) /* dss_data15 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA16, (IDIS | PD | M0 )) /* dss_data16 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA17, (IDIS | PD | M0 )) /* dss_data17 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA18, (IDIS | PD | M0 )) /* dss_data18 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA19, (IDIS | PD | M0 )) /* dss_data19 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA20, (IDIS | PU | M0 )) /* dss_data20 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA21, (IDIS | PD | M0 )) /* dss_data21 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA22, (IDIS | PD | M0 )) /* dss_data22 */\
MUX_VAL(CONTROL_PADCONF_DSS_DATA23, (IDIS | PD | M0 )) /* dss_data23 */\
MUX_VAL(CONTROL_PADCONF_DSS_HSYNC, (IDIS | PU | M0 )) /* dss_hsync */\
MUX_VAL(CONTROL_PADCONF_DSS_PCLK, (IDIS | PU | M0 )) /* dss_pclk */\
MUX_VAL(CONTROL_PADCONF_DSS_VSYNC, (IDIS | PU | M0 )) /* dss_vsync */\
MUX_VAL(CONTROL_PADCONF_ETK_CLK_ES2, (IEN | PI | SB_HIZ | M2 )) /* mmc3_clk */\
MUX_VAL(CONTROL_PADCONF_ETK_CTL_ES2, (IEN | PI | SB_HIZ | M2 )) /* mmc3_cmd */\
MUX_VAL(CONTROL_PADCONF_ETK_D0_ES2, (IDIS | PU | M7 )) /* hw_dbg2 */\
MUX_VAL(CONTROL_PADCONF_ETK_D1_ES2, (IDIS | PU | M7 )) /* hw_dbg3 */\
MUX_VAL(CONTROL_PADCONF_ETK_D2_ES2, (IDIS | PI | M4 )) /* gpio_16 */\
MUX_VAL(CONTROL_PADCONF_ETK_D3_ES2, (IEN | PI | SB_HIZ | M2 )) /* mmc3_dat3 */\
MUX_VAL(CONTROL_PADCONF_ETK_D4_ES2, (IEN | PI | SB_HIZ | M2 )) /* mmc3_dat0 */\
MUX_VAL(CONTROL_PADCONF_ETK_D5_ES2, (IEN | PI | SB_HIZ | M2 )) /* mmc3_dat1 */\
MUX_VAL(CONTROL_PADCONF_ETK_D6_ES2, (IEN | PI | SB_HIZ | M2 )) /* mmc3_dat2 */\
MUX_VAL(CONTROL_PADCONF_ETK_D7_ES2, (IEN | PD | SB_HI | M4 )) /* gpio_21 */\
MUX_VAL(CONTROL_PADCONF_ETK_D8_ES2, (IDIS | PD | M1 )) /* sys_drm_msecure */\
MUX_VAL(CONTROL_PADCONF_ETK_D9_ES2, (IDIS | PI | SB_LOW | M4 )) /* gpio_23 */\
MUX_VAL(CONTROL_PADCONF_ETK_D10_ES2, (IEN | PD | M3 )) /* hsusb2_clk */\
MUX_VAL(CONTROL_PADCONF_ETK_D11_ES2, (IDIS | PD | M3 )) /* hsusb2_stp */\
MUX_VAL(CONTROL_PADCONF_ETK_D12_ES2, (IEN | PD | M3 )) /* hsusb2_dir */\
MUX_VAL(CONTROL_PADCONF_ETK_D13_ES2, (IEN | PD | M3 )) /* hsusb2_nxt */\
MUX_VAL(CONTROL_PADCONF_ETK_D14_ES2, (IEN | PD | M3 )) /* hsusb2_data0 */\
MUX_VAL(CONTROL_PADCONF_ETK_D15_ES2, (IEN | PD | M3 )) /* hsusb2_data1 */\
MUX_VAL(CONTROL_PADCONF_GPMC_A1, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A2, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A3, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A4, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A5, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A6, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A7, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A8, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A9, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_A10, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_CLK, (IEN | PI | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_D0, (IEN | PU | M0 )) /* gpmc_d0 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D1, (IEN | PU | M0 )) /* gpmc_d1 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D2, (IEN | PU | M0 )) /* gpmc_d2 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D3, (IEN | PU | M0 )) /* gpmc_d3 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D4, (IEN | PU | M0 )) /* gpmc_d4 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D5, (IEN | PU | M0 )) /* gpmc_d5 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D6, (IEN | PU | M0 )) /* gpmc_d6 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D7, (IEN | PU | M0 )) /* gpmc_d7 */\
MUX_VAL(CONTROL_PADCONF_GPMC_D8, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_D9, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_D10, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_D11, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_D12, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_D13, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_D14, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_D15, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NADV_ALE, (IDIS | PI | M0 )) /* gpmc_nadv_ale */\
MUX_VAL(CONTROL_PADCONF_GPMC_NBE0_CLE, (IEN | PI | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NBE1, (IEN | PD | M4 )) /* gpio_61 */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS0, (IDIS | PI | M0 )) /* gpmc_ncs0 */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS1, (IEN | PI | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS2, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS3, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS4, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS5, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS6, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NCS7, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_NOE, (IDIS | PI | M0 )) /* gpmc_noe */\
MUX_VAL(CONTROL_PADCONF_GPMC_NWE, (IDIS | PI | M0 )) /* gpmc_nwe */\
MUX_VAL(CONTROL_PADCONF_GPMC_NWP, (IEN | PI | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_WAIT0, (IEN | PU | M0 )) /* gpmc_wait0 */\
MUX_VAL(CONTROL_PADCONF_GPMC_WAIT1, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_WAIT2, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_GPMC_WAIT3, (IEN | PU | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_HDQ_SIO, (IEN | PU | M0 )) /* hdq_sio */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_CLK, (IEN | PD | M0 )) /* hsusb0_clk */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA0, (IEN | PD | M0 )) /* hsusb0_data0 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA1, (IEN | PD | M0 )) /* hsusb0_data1 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA2, (IEN | PD | M0 )) /* hsusb0_data2 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA3, (IEN | PD | M0 )) /* hsusb0_data3 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA4, (IEN | PD | M0 )) /* hsusb0_data4 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA5, (IEN | PD | M0 )) /* hsusb0_data5 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA6, (IEN | PD | M0 )) /* hsusb0_data6 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DATA7, (IEN | PD | M0 )) /* hsusb0_data7 */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_DIR, (IEN | PD | M0 )) /* hsusb0_dir */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_NXT, (IEN | PD | M0 )) /* hsusb0_nxt */\
MUX_VAL(CONTROL_PADCONF_HSUSB0_STP, (IDIS | PU | M0 )) /* hsusb0_stp */\
MUX_VAL(CONTROL_PADCONF_I2C1_SCL, (IEN | PU | M0 )) /* i2c1_scl */\
MUX_VAL(CONTROL_PADCONF_I2C1_SDA, (IEN | PU | M0 )) /* i2c1_sda */\
MUX_VAL(CONTROL_PADCONF_I2C2_SCL, (IEN | PU | M0 )) /* i2c2_scl */\
MUX_VAL(CONTROL_PADCONF_I2C2_SDA, (IEN | PU | M0 )) /* i2c2_sda */\
MUX_VAL(CONTROL_PADCONF_I2C3_SCL, (IEN | PU | M0 )) /* i2c3_scl */\
MUX_VAL(CONTROL_PADCONF_I2C3_SDA, (IEN | PU | M0 )) /* i2c3_sda */\
MUX_VAL(CONTROL_PADCONF_I2C4_SCL, (IEN | PU | M0 )) /* i2c4_scl */\
MUX_VAL(CONTROL_PADCONF_I2C4_SDA, (IEN | PU | M0 )) /* i2c4_sda */\
MUX_VAL(CONTROL_PADCONF_JTAG_EMU0, (IEN | PU | M0 )) /* jtag_emu0 */\
MUX_VAL(CONTROL_PADCONF_JTAG_EMU1, (IEN | PU | M0 )) /* jtag_emu1 */\
MUX_VAL(CONTROL_PADCONF_JTAG_nTRST, (IEN | PD | M0 )) /* jtag_ntrst */\
MUX_VAL(CONTROL_PADCONF_JTAG_TCK, (IEN | PD | M0 )) /* jtag_tck */\
MUX_VAL(CONTROL_PADCONF_JTAG_TDI, (IEN | PU | M0 )) /* jtag_tdi */\
MUX_VAL(CONTROL_PADCONF_JTAG_TDO, (IDIS | PI | M0 )) /* jtag_tdo */\
MUX_VAL(CONTROL_PADCONF_JTAG_TMS, (IEN | PU | M0 )) /* jtag_tms_tmsc */\
MUX_VAL(CONTROL_PADCONF_MCBSP_CLKS, (IEN | PD | M0 )) /* mcbsp_clks */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_CLKR, (IEN | PD | M0 )) /* mcbsp1_clkr */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_CLKX, (IEN | PD | M0 )) /* mcbsp1_clkx */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_DR, (IEN | PD | M0 )) /* mcbsp1_dr */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_DX, (IDIS | PD | M0 )) /* mcbsp1_dx */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_FSR, (IEN | PD | M0 )) /* mcbsp1_fsr */\
MUX_VAL(CONTROL_PADCONF_MCBSP1_FSX, (IEN | PD | M0 )) /* mcbsp1_fsx */\
MUX_VAL(CONTROL_PADCONF_MCBSP2_CLKX, (IEN | PD | M0 )) /* mcbsp2_clkx */\
MUX_VAL(CONTROL_PADCONF_MCBSP2_DR, (IEN | PD | M0 )) /* mcbsp2_dr */\
MUX_VAL(CONTROL_PADCONF_MCBSP2_DX, (IDIS | PD | M0 )) /* mcbsp2_dx */\
MUX_VAL(CONTROL_PADCONF_MCBSP2_FSX, (IEN | PD | M0 )) /* mcbsp2_fsx */\
MUX_VAL(CONTROL_PADCONF_MCBSP3_CLKX, (IDIS | PU | SB_HIZ | M4 )) /* gpio_142 */\
MUX_VAL(CONTROL_PADCONF_MCBSP3_DR, (IDIS | PU | SB_HIZ | M4 )) /* gpio_141 */\
MUX_VAL(CONTROL_PADCONF_MCBSP3_DX, (IDIS | PU | SB_HIZ | M4 )) /* gpio_140 */\
MUX_VAL(CONTROL_PADCONF_MCBSP3_FSX, (IEN | PU | SB_HIZ | M4 )) /* gpio_143 */\
MUX_VAL(CONTROL_PADCONF_MCBSP4_CLKX, (IDIS | PU | M4 )) /* gpio_152 */\
MUX_VAL(CONTROL_PADCONF_MCBSP4_DR, (IDIS | PU | SB_PU | M4 )) /* gpio_153 */\
MUX_VAL(CONTROL_PADCONF_MCBSP4_DX, (IEN | PD | SB_HIZ | SB_PD | M4 )) /* gpio_154 */\
MUX_VAL(CONTROL_PADCONF_MCBSP4_FSX, (IDIS | PD | M4 )) /* gpio_155 */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_CLK, (IEN | PD | M0 )) /* mcspi1_clk */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_CS0, (IEN | PU | M0 )) /* mcspi1_cs0 */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_CS1, (IDIS | PU | M0 )) /* mcspi1_cs1 */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_CS2, (IDIS | PU | M0 )) /* mcspi1_cs2 */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_CS3, (IEN | PU | M3 )) /* hsusb2_data2 */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_SIMO, (IEN | PD | M0 )) /* mcspi1_simo */\
MUX_VAL(CONTROL_PADCONF_MCSPI1_SOMI, (IEN | PD | M0 )) /* mcspi1_somi */\
MUX_VAL(CONTROL_PADCONF_MCSPI2_CLK, (IDIS | PD | M3 )) /* hsusb2_data7 */\
MUX_VAL(CONTROL_PADCONF_MCSPI2_CS0, (IDIS | PU | M3 )) /* hsusb2_data6 */\
MUX_VAL(CONTROL_PADCONF_MCSPI2_CS1, (IEN | PD | M3 )) /* hsusb2_data3 */\
MUX_VAL(CONTROL_PADCONF_MCSPI2_SIMO, (IEN | PD | M3 )) /* hsusb2_data4 */\
MUX_VAL(CONTROL_PADCONF_MCSPI2_SOMI, (IDIS | PD | M3 )) /* hsusb2_data5 */\
MUX_VAL(CONTROL_PADCONF_MMC1_CLK, (IEN | PU | M0 )) /* mmc1_clk IMPORTANTISSIMI I PULL-UP */\
MUX_VAL(CONTROL_PADCONF_MMC1_CMD, (IEN | PU | M0 )) /* mmc1_cmd IMPORTANTISSIMI I PULL-UP */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT0, (IEN | PU | M0 )) /* mmc1_dat0 IMPORTANTISSIMI I PULL-UP */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT1, (IEN | PU | M0 )) /* mmc1_dat1 IMPORTANTISSIMI I PULL-UP */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT2, (IEN | PU | M0 )) /* mmc1_dat2 IMPORTANTISSIMI I PULL-UP */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT3, (IEN | PU | M0 )) /* mmc1_dat3 IMPORTANTISSIMI I PULL-UP */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT4, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT5, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT6, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MMC1_DAT7, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MMC2_CLK, (IEN | PD | M0 )) /* mmc2_clk */\
MUX_VAL(CONTROL_PADCONF_MMC2_CMD, (IEN | PU | M0 )) /* mmc2_cmd */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT0, (IEN | PU | M0 )) /* mmc2_dat0 */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT1, (IEN | PU | M0 )) /* mmc2_dat1 */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT2, (IEN | PU | M0 )) /* mmc2_dat2 */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT3, (IEN | PU | M0 )) /* mmc2_dat3 */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT4, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT5, (IEN | PD | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT6, (IEN | PD | M4 )) /* gpio_138 */\
MUX_VAL(CONTROL_PADCONF_MMC2_DAT7, (IEN | PD | M1 )) /* mmc2_clkin */\
MUX_VAL(CONTROL_PADCONF_SDRC_CKE0, (IDIS | PI | M0 )) /* sdrc_cke0 */\
MUX_VAL(CONTROL_PADCONF_SDRC_CKE1, (IDIS | PI | M0 )) /* sdrc_cke1 */\
MUX_VAL(CONTROL_PADCONF_SDRC_CLK, (IEN | PI | M0 )) /* sdrc_clk */\
MUX_VAL(CONTROL_PADCONF_SDRC_D0, (IEN | PI | M0 )) /* sdrc_d0 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D1, (IEN | PI | M0 )) /* sdrc_d1 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D2, (IEN | PI | M0 )) /* sdrc_d2 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D3, (IEN | PI | M0 )) /* sdrc_d3 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D4, (IEN | PI | M0 )) /* sdrc_d4 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D5, (IEN | PI | M0 )) /* sdrc_d5 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D6, (IEN | PI | M0 )) /* sdrc_d6 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D7, (IEN | PI | M0 )) /* sdrc_d7 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D8, (IEN | PI | M0 )) /* sdrc_d8 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D9, (IEN | PI | M0 )) /* sdrc_d9 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D10, (IEN | PI | M0 )) /* sdrc_d10 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D11, (IEN | PI | M0 )) /* sdrc_d11 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D12, (IEN | PI | M0 )) /* sdrc_d12 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D13, (IEN | PI | M0 )) /* sdrc_d13 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D14, (IEN | PI | M0 )) /* sdrc_d14 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D15, (IEN | PI | M0 )) /* sdrc_d15 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D16, (IEN | PI | M0 )) /* sdrc_d16 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D17, (IEN | PI | M0 )) /* sdrc_d17 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D18, (IEN | PI | M0 )) /* sdrc_d18 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D19, (IEN | PI | M0 )) /* sdrc_d19 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D20, (IEN | PI | M0 )) /* sdrc_d20 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D21, (IEN | PI | M0 )) /* sdrc_d21 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D22, (IEN | PI | M0 )) /* sdrc_d22 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D23, (IEN | PI | M0 )) /* sdrc_d23 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D24, (IEN | PI | M0 )) /* sdrc_d24 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D25, (IEN | PI | M0 )) /* sdrc_d25 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D26, (IEN | PI | M0 )) /* sdrc_d26 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D27, (IEN | PI | M0 )) /* sdrc_d27 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D28, (IEN | PI | M0 )) /* sdrc_d28 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D29, (IEN | PI | M0 )) /* sdrc_d29 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D30, (IEN | PI | M0 )) /* sdrc_d30 */\
MUX_VAL(CONTROL_PADCONF_SDRC_D31, (IEN | PI | M0 )) /* sdrc_d31 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DQS0, (IEN | PI | M0 )) /* sdrc_dqs0 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DQS1, (IEN | PI | M0 )) /* sdrc_dqs1 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DQS2, (IEN | PI | M0 )) /* sdrc_dqs2 */\
MUX_VAL(CONTROL_PADCONF_SDRC_DQS3, (IEN | PI | M0 )) /* sdrc_dqs3 */\
MUX_VAL(CONTROL_PADCONF_SYS_32K, (IEN | PI | M0 )) /* sys_32k */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT0, (IEN | PI | M4 )) /* gpio_2 */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT1, (IEN | PI | M4 )) /* gpio_3 */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT2, (IEN | PI | M4 )) /* gpio_4 */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT3, (IEN | PI | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT4, (IEN | PI | M4 )) /* gpio_6 */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT5, (IEN | PI | M4 )) /* gpio_7 */\
MUX_VAL(CONTROL_PADCONF_SYS_BOOT6, (IEN | PI | M7 )) /* safe_mode */\
MUX_VAL(CONTROL_PADCONF_SYS_CLKOUT1, (IEN | PU | SB_HIZ | SB_PU | M4 )) /* gpio_10 */\
MUX_VAL(CONTROL_PADCONF_SYS_CLKOUT2, (IEN | PU | SB_HIZ | SB_PU | M4 )) /* gpio_186 */\
MUX_VAL(CONTROL_PADCONF_SYS_CLKREQ, (IEN | PI | M0 )) /* sys_clkreq */\
MUX_VAL(CONTROL_PADCONF_SYS_NIRQ, (IEN | PU | M0 )) /* sys_nirq */\
MUX_VAL(CONTROL_PADCONF_SYS_NRESWARM, (IEN | PU | M0 )) /* sys_nreswarm */\
MUX_VAL(CONTROL_PADCONF_SYS_OFF_MODE, (IDIS | PD | M0 )) /* sys_off_mode */\
MUX_VAL(CONTROL_PADCONF_UART1_CTS, (IEN | PD | M0 )) /* uart1_cts */\
MUX_VAL(CONTROL_PADCONF_UART1_RTS, (IDIS | PD | M0 )) /* uart1_rts */\
MUX_VAL(CONTROL_PADCONF_UART1_RX, (IEN | PD | M0 )) /* uart1_rx */\
MUX_VAL(CONTROL_PADCONF_UART1_TX, (IDIS | PD | M0 )) /* uart1_tx */\
MUX_VAL(CONTROL_PADCONF_UART2_CTS, (IEN | PU | M0 )) /* uart2_cts */\
MUX_VAL(CONTROL_PADCONF_UART2_RTS, (IDIS | PU | M0 )) /* uart2_rts */\
MUX_VAL(CONTROL_PADCONF_UART2_RX, (IEN | PU | M0 )) /* uart2_rx */\
MUX_VAL(CONTROL_PADCONF_UART2_TX, (IDIS | PU | M0 )) /* uart2_tx */\
MUX_VAL(CONTROL_PADCONF_UART3_CTS_RCTX, (IEN | PU | SB_HIZ | SB_PU | M4 )) /* gpio_163 */\
MUX_VAL(CONTROL_PADCONF_UART3_RTS_SD, (IEN | PU | SB_PU | M4 )) /* gpio_164 */\
MUX_VAL(CONTROL_PADCONF_UART3_RX_IRRX, (IEN | PU | M0 )) /* uart3_rx_irrx */\
MUX_VAL(CONTROL_PADCONF_UART3_TX_IRTX, (IDIS | PU | M0 )) /* uart3_tx_irtx */\

#endif
