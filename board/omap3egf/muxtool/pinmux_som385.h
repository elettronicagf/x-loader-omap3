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

#ifndef _PINMUX_SOM385_H_
#define _PINMUX_SOM385_H_

#include <asm/arch/mux.h>
#ifndef MUX_VAL
#define 	MUX_VAL(OFFSET,VALUE)\
		__raw_writew((VALUE), OMAP34XX_CTRL_BASE + (OFFSET));

#define		CP(x)	(CONTROL_PADCONF_##x)
#endif

/*
 * IEN  - Input Enable
 * IDIS - Input Disable
 * PTD  - Pull type Down
 * PTU  - Pull type Up
 * DIS  - Pull type selection is inactive
 * EN   - Pull type selection is active
 * M0   - Mode 0
 * The commented string gives the final mux configuration for that pin
 */


#define MUX_SOM385() \
 MUX_VAL(CP(SDRC_D0),		(IEN  | PTD | DIS | M0)) /*SDRC_D0*/\
 MUX_VAL(CP(SDRC_D1),		(IEN  | PTD | DIS | M0)) /*SDRC_D1*/\
 MUX_VAL(CP(SDRC_D2),		(IEN  | PTD | DIS | M0)) /*SDRC_D2*/\
 MUX_VAL(CP(SDRC_D3),		(IEN  | PTD | DIS | M0)) /*SDRC_D3*/\
 MUX_VAL(CP(SDRC_D4),		(IEN  | PTD | DIS | M0)) /*SDRC_D4*/\
 MUX_VAL(CP(SDRC_D5),		(IEN  | PTD | DIS | M0)) /*SDRC_D5*/\
 MUX_VAL(CP(SDRC_D6),		(IEN  | PTD | DIS | M0)) /*SDRC_D6*/\
 MUX_VAL(CP(SDRC_D7),		(IEN  | PTD | DIS | M0)) /*SDRC_D7*/\
 MUX_VAL(CP(SDRC_D8),		(IEN  | PTD | DIS | M0)) /*SDRC_D8*/\
 MUX_VAL(CP(SDRC_D9),		(IEN  | PTD | DIS | M0)) /*SDRC_D9*/\
 MUX_VAL(CP(SDRC_D10),		(IEN  | PTD | DIS | M0)) /*SDRC_D10*/\
 MUX_VAL(CP(SDRC_D11),		(IEN  | PTD | DIS | M0)) /*SDRC_D11*/\
 MUX_VAL(CP(SDRC_D12),		(IEN  | PTD | DIS | M0)) /*SDRC_D12*/\
 MUX_VAL(CP(SDRC_D13),		(IEN  | PTD | DIS | M0)) /*SDRC_D13*/\
 MUX_VAL(CP(SDRC_D14),		(IEN  | PTD | DIS | M0)) /*SDRC_D14*/\
 MUX_VAL(CP(SDRC_D15),		(IEN  | PTD | DIS | M0)) /*SDRC_D15*/\
 MUX_VAL(CP(SDRC_D16),		(IEN  | PTD | DIS | M0)) /*SDRC_D16*/\
 MUX_VAL(CP(SDRC_D17),		(IEN  | PTD | DIS | M0)) /*SDRC_D17*/\
 MUX_VAL(CP(SDRC_D18),		(IEN  | PTD | DIS | M0)) /*SDRC_D18*/\
 MUX_VAL(CP(SDRC_D19),		(IEN  | PTD | DIS | M0)) /*SDRC_D19*/\
 MUX_VAL(CP(SDRC_D20),		(IEN  | PTD | DIS | M0)) /*SDRC_D20*/\
 MUX_VAL(CP(SDRC_D21),		(IEN  | PTD | DIS | M0)) /*SDRC_D21*/\
 MUX_VAL(CP(SDRC_D22),		(IEN  | PTD | DIS | M0)) /*SDRC_D22*/\
 MUX_VAL(CP(SDRC_D23),		(IEN  | PTD | DIS | M0)) /*SDRC_D23*/\
 MUX_VAL(CP(SDRC_D24),		(IEN  | PTD | DIS | M0)) /*SDRC_D24*/\
 MUX_VAL(CP(SDRC_D25),		(IEN  | PTD | DIS | M0)) /*SDRC_D25*/\
 MUX_VAL(CP(SDRC_D26),		(IEN  | PTD | DIS | M0)) /*SDRC_D26*/\
 MUX_VAL(CP(SDRC_D27),		(IEN  | PTD | DIS | M0)) /*SDRC_D27*/\
 MUX_VAL(CP(SDRC_D28),		(IEN  | PTD | DIS | M0)) /*SDRC_D28*/\
 MUX_VAL(CP(SDRC_D29),		(IEN  | PTD | DIS | M0)) /*SDRC_D29*/\
 MUX_VAL(CP(SDRC_D30),		(IEN  | PTD | DIS | M0)) /*SDRC_D30*/\
 MUX_VAL(CP(SDRC_D31),		(IEN  | PTD | DIS | M0)) /*SDRC_D31*/\
 MUX_VAL(CP(SDRC_CLK),		(IEN  | PTD | DIS | M0)) /*SDRC_CLK*/\
 MUX_VAL(CP(SDRC_DQS0),		(IEN  | PTD | DIS | M0)) /*SDRC_DQS0*/\
 MUX_VAL(CP(SDRC_DQS1),		(IEN  | PTD | DIS | M0)) /*SDRC_DQS1*/\
 MUX_VAL(CP(SDRC_DQS2),		(IEN  | PTD | DIS | M0)) /*SDRC_DQS2*/\
 MUX_VAL(CP(SDRC_DQS3),		(IEN  | PTD | DIS | M0)) /*SDRC_DQS3*/\
 /*DSS*/\
 MUX_VAL(CP(DSS_PCLK),		(IDIS | PTD | DIS | M0)) /*DSS_PCLK*/\
 MUX_VAL(CP(DSS_HSYNC),		(IDIS | PTD | DIS | M0)) /*DSS_HSYNC*/\
 MUX_VAL(CP(DSS_VSYNC),		(IDIS | PTD | DIS | M0)) /*DSS_VSYNC*/\
 MUX_VAL(CP(DSS_ACBIAS),	(IDIS | PTD | DIS | M0)) /*DSS_ACBIAS*/\
 MUX_VAL(CP(DSS_DATA0),		(IDIS | PTD | DIS | M0)) /*DSS_DATA0*/\
 MUX_VAL(CP(DSS_DATA1),		(IDIS | PTD | DIS | M0)) /*DSS_DATA1*/\
 MUX_VAL(CP(DSS_DATA2),		(IDIS | PTD | DIS | M0)) /*DSS_DATA2*/\
 MUX_VAL(CP(DSS_DATA3),		(IDIS | PTD | DIS | M0)) /*DSS_DATA3*/\
 MUX_VAL(CP(DSS_DATA4),		(IDIS | PTD | DIS | M0)) /*DSS_DATA4*/\
 MUX_VAL(CP(DSS_DATA5),		(IDIS | PTD | DIS | M0)) /*DSS_DATA5*/\
 MUX_VAL(CP(DSS_DATA6),		(IDIS | PTD | DIS | M0)) /*DSS_DATA6*/\
 MUX_VAL(CP(DSS_DATA7),		(IDIS | PTD | DIS | M0)) /*DSS_DATA7*/\
 MUX_VAL(CP(DSS_DATA8),		(IDIS | PTD | DIS | M0)) /*DSS_DATA8*/\
 MUX_VAL(CP(DSS_DATA9),		(IDIS | PTD | DIS | M0)) /*DSS_DATA9*/\
 MUX_VAL(CP(DSS_DATA10),	(IDIS | PTD | DIS | M0)) /*DSS_DATA10*/\
 MUX_VAL(CP(DSS_DATA11),	(IDIS | PTD | DIS | M0)) /*DSS_DATA11*/\
 MUX_VAL(CP(DSS_DATA12),	(IDIS | PTD | DIS | M0)) /*DSS_DATA12*/\
 MUX_VAL(CP(DSS_DATA13),	(IDIS | PTD | DIS | M0)) /*DSS_DATA13*/\
 MUX_VAL(CP(DSS_DATA14),	(IDIS | PTD | DIS | M0)) /*DSS_DATA14*/\
 MUX_VAL(CP(DSS_DATA15),	(IDIS | PTD | DIS | M0)) /*DSS_DATA15*/\
 MUX_VAL(CP(DSS_DATA16),	(IDIS | PTD | DIS | M0)) /*DSS_DATA16*/\
 MUX_VAL(CP(DSS_DATA17),	(IDIS | PTD | DIS | M0)) /*DSS_DATA17*/\
 MUX_VAL(CP(DSS_DATA18),	(IDIS | PTD | DIS | M0)) /*DSS_DATA18*/\
 MUX_VAL(CP(DSS_DATA19),	(IDIS | PTD | DIS | M0)) /*DSS_DATA19*/\
 MUX_VAL(CP(DSS_DATA20),	(IDIS | PTD | DIS | M0)) /*DSS_DATA20*/\
 MUX_VAL(CP(DSS_DATA21),	(IDIS | PTD | DIS | M0)) /*DSS_DATA21*/\
 MUX_VAL(CP(DSS_DATA22),	(IDIS | PTD | DIS | M0)) /*DSS_DATA22*/\
 MUX_VAL(CP(DSS_DATA23),	(IDIS | PTD | DIS | M0)) /*DSS_DATA23*/\
 /*CAMERA*/\
 MUX_VAL(CP(CAM_HS),		(IEN  | PTU | EN  | M4)) /*CAM_HS */\
 MUX_VAL(CP(CAM_VS),		(IEN  | PTU | EN  | M0)) /*CAM_VS */\
 MUX_VAL(CP(CAM_XCLKA),		(IDIS | PTD | DIS | M4)) /*GPIO_96 USB_HOST_nEN abilita alimentazione alle porte HS USB2 e FS USB3*/\
 MUX_VAL(CP(CAM_PCLK),		(IEN  | PTU | EN  | M0)) /*CAM_PCLK*/\
 MUX_VAL(CP(CAM_FLD),		(IDIS | PTD | DIS | M4)) /*GPIO_98 Non usiamo il segnale FID del TVP5150*/\
 MUX_VAL(CP(CAM_D0),		(IEN  | PTD | DIS | M0)) /*CAM_D0*/\
 MUX_VAL(CP(CAM_D1),		(IEN  | PTD | DIS | M0)) /*CAM_D1*/\
 MUX_VAL(CP(CAM_D2),		(IEN  | PTD | DIS | M0)) /*CAM_D2*/\
 MUX_VAL(CP(CAM_D3),		(IEN  | PTD | DIS | M0)) /*CAM_D3*/\
 MUX_VAL(CP(CAM_D4),		(IEN  | PTD | DIS | M0)) /*CAM_D4*/\
 MUX_VAL(CP(CAM_D5),		(IEN  | PTD | DIS | M0)) /*CAM_D5*/\
 MUX_VAL(CP(CAM_D6),		(IEN  | PTD | DIS | M0)) /*CAM_D6*/\
 MUX_VAL(CP(CAM_D7),		(IEN  | PTD | DIS | M0)) /*CAM_D7*/\
 MUX_VAL(CP(CAM_D8),		(IEN  | PTD | EN  | M4)) /*GPIO_107 EEPROM_WP_107*/\
 MUX_VAL(CP(CAM_D9),		(IDIS | PTD | DIS | M4)) /*GPIO_108 MCSPI1-0_select*/\
 MUX_VAL(CP(CAM_D10),		(IEN  | PTU | EN  | M4)) /*GPIO_109 USB_HOST_nFAULT errore su alimentazione HS USB2 e FS USB3 */\
 MUX_VAL(CP(CAM_D11),		(IDIS | PTD | DIS | M4)) /*GPIO_110 HSUSB2_nRESET */\
 MUX_VAL(CP(CAM_XCLKB),		(IEN  | PTU | EN  | M4)) /*GPIO_111 USB_HOST_SOFTCON Segnale SOFTCON del TUSB2551 transceiver*/\
 MUX_VAL(CP(CAM_WEN),		(IEN  | PTD | DIS | M7)) /*Disconnesso */\
 MUX_VAL(CP(CAM_STROBE),	(IEN  | PTD | EN  | M4)) /*GPIO_126 TVP5150_IRQ_1V8*/\
 MUX_VAL(CP(CSI2_DX0),		(IEN  | PTU | DIS | M4)) /*GPIO_112 verso CPLD*/\
 MUX_VAL(CP(CSI2_DY0),		(IEN  | PTU | EN  | M4)) /*GPIO_113 da/verso CPLD*/\
 MUX_VAL(CP(CSI2_DX1),		(IEN  | PTU | DIS  | M4)) /*GPIO_114 nPEN_IRQ_1V8*/\
 MUX_VAL(CP(CSI2_DY1),		(IEN  | PTU | EN  | M4)) /*GPIO_115 da/verso CPLD*/\
 /*Expansion card */\
 MUX_VAL(CP(MMC1_CLK),		(IDIS | PTU | EN  | M0)) /*MMC1_CLK*/\
 MUX_VAL(CP(MMC1_CMD),		(IEN  | PTU | EN  | M0)) /*MMC1_CMD*/\
 MUX_VAL(CP(MMC1_DAT0),		(IEN  | PTU | EN  | M0)) /*MMC1_DAT0*/\
 MUX_VAL(CP(MMC1_DAT1),		(IEN  | PTU | EN  | M0)) /*MMC1_DAT1*/\
 MUX_VAL(CP(MMC1_DAT2),		(IEN  | PTU | EN  | M0)) /*MMC1_DAT2*/\
 MUX_VAL(CP(MMC1_DAT3),		(IEN  | PTU | EN  | M0)) /*MMC1_DAT3*/\
 MUX_VAL(CP(MMC1_DAT4),		(IEN  | PTU | EN  | M7)) /*Non Connesso su Explor*/\
 MUX_VAL(CP(MMC1_DAT5),		(IEN  | PTU | EN  | M7)) /*Non Connesso su Explor*/\
 MUX_VAL(CP(MMC1_DAT6),		(IEN  | PTU | EN  | M7)) /*Non Connesso su Explor*/\
 MUX_VAL(CP(MMC1_DAT7),		(IEN  | PTU | EN  | M7)) /*Non Connesso su Explor*/\
 /*MMC2  */\
 MUX_VAL(CP(MMC2_CLK),		(IEN | PTU | EN  | M0)) /*MMC2_CLK*/ \
 MUX_VAL(CP(MMC2_CMD),		(IEN  | PTU | EN  | M0)) /*MMC2_CMD */\
 MUX_VAL(CP(MMC2_DAT0),		(IEN  | PTU | EN  | M0)) /*MMC2_DAT0 */\
 MUX_VAL(CP(MMC2_DAT1),		(IEN  | PTU | EN  | M0)) /*MMC2_DAT1 */\
 MUX_VAL(CP(MMC2_DAT2),		(IEN  | PTU | EN  | M0)) /*MMC2_DAT2 */\
 MUX_VAL(CP(MMC2_DAT3),		(IEN  | PTU | EN  | M0)) /*MMC2_DAT3 */\
 MUX_VAL(CP(MMC2_DAT4),		(IEN  | PTU | EN  | M4)) /*GPIO_136 TASTO F1*/\
 MUX_VAL(CP(MMC2_DAT5),		(IEN  | PTU | EN  | M4)) /*GPIO_137 TASTO F2*/\
 MUX_VAL(CP(MMC2_DAT6),		(IDIS | PTU | EN  | M4)) /*GPIO_138 power off verso CPLD */\
 MUX_VAL(CP(MMC2_DAT7),		(IEN  | PTD | DIS | M1)) /*MMC2_CLKIN */\
 /*Uart 2*/\
 MUX_VAL(CP(UART2_TX),		(IDIS| PTD | DIS| M0)) /*UART2_TX */\
 MUX_VAL(CP(UART2_RTS),		(IDIS| PTD | DIS| M0)) /*UART2_RTS*/\
 MUX_VAL(CP(UART2_CTS),		(IEN | PTU | EN| M0)) /*UART2_CTS*/\
 MUX_VAL(CP(UART2_RX),		(IEN | PTD | DIS| M0)) /*UART2_RX*/\
 /*Uart 1 */\
 MUX_VAL(CP(UART1_TX),		(IDIS | PTD | DIS | M0)) /*UART1_TX*/\
 MUX_VAL(CP(UART1_RTS),		(IDIS | PTD | DIS | M0)) /*UART1_RTS*/ \
 MUX_VAL(CP(UART1_CTS),		(IEN  | PTU | EN | M0)) /*UART1_CTS*/ \
 MUX_VAL(CP(UART1_RX),		(IEN  | PTD | DIS | M0)) /*UART1_RX*/\
 /*Serial Interface*/\
 MUX_VAL(CP(UART3_CTS_RCTX),	(IEN  | PTU | EN  | M4)) /*GPIO163 MEMS_INT2 */\
 MUX_VAL(CP(UART3_RTS_SD),	(IEN  | PTU | EN  | M4)) /*GPIO164 MEMS_INT1 */\
 MUX_VAL(CP(UART3_RX_IRRX),	(IEN  | PTD | DIS | M0)) /*UART3_RX_IRRX*/\
 MUX_VAL(CP(UART3_TX_IRTX),	(IDIS | PTD | DIS | M0)) /*UART3_TX_IRTX*/\
 MUX_VAL(CP(HSUSB0_CLK),	(IEN  | PTD | DIS | M0)) /*HSUSB0_CLK*/\
 MUX_VAL(CP(HSUSB0_STP),	(IDIS | PTU | EN  | M0)) /*HSUSB0_STP*/\
 MUX_VAL(CP(HSUSB0_DIR),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DIR*/\
 MUX_VAL(CP(HSUSB0_NXT),	(IEN  | PTD | DIS | M0)) /*HSUSB0_NXT*/\
 MUX_VAL(CP(HSUSB0_DATA0),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA0*/\
 MUX_VAL(CP(HSUSB0_DATA1),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA1*/\
 MUX_VAL(CP(HSUSB0_DATA2),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA2*/\
 MUX_VAL(CP(HSUSB0_DATA3),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA3*/\
 MUX_VAL(CP(HSUSB0_DATA4),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA4*/\
 MUX_VAL(CP(HSUSB0_DATA5),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA5*/\
 MUX_VAL(CP(HSUSB0_DATA6),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA6*/\
 MUX_VAL(CP(HSUSB0_DATA7),	(IEN  | PTD | DIS | M0)) /*HSUSB0_DATA7*/\
 MUX_VAL(CP(I2C1_SCL),		(IEN  | PTU | EN  | M0)) /*I2C1_SCL*/\
 MUX_VAL(CP(I2C1_SDA),		(IEN  | PTU | EN  | M0)) /*I2C1_SDA*/\
 MUX_VAL(CP(I2C2_SCL),		(IEN  | PTU | EN  | M0)) /*I2C2_SCL*/\
 MUX_VAL(CP(I2C2_SDA),		(IEN  | PTU | EN  | M0)) /*I2C2_SDA*/\
 MUX_VAL(CP(I2C3_SCL),		(IEN  | PTU | EN  | M0)) /*I2C3_SCL*/\
 MUX_VAL(CP(I2C3_SDA),		(IEN  | PTU | EN  | M0)) /*I2C3_SDA*/\
 MUX_VAL(CP(I2C4_SCL),		(IEN  | PTU | EN  | M0)) /*I2C4_SCL*/\
 MUX_VAL(CP(I2C4_SDA),		(IEN  | PTU | EN  | M0)) /*I2C4_SDA*/\
 MUX_VAL(CP(ETK_D10_ES2),	(IDIS | PTD | DIS | M3)) /*HSUSB2_CLK*/\
 MUX_VAL(CP(ETK_D11_ES2),	(IDIS | PTD | DIS | M3)) /*HSUSB2_STP*/\
 MUX_VAL(CP(ETK_D12_ES2),	(IEN  | PTD | EN  | M3)) /*HSUSB2_DIR*/\
 MUX_VAL(CP(ETK_D13_ES2),	(IEN  | PTD | EN  | M3)) /*HSUSB2_NXT*/\
 MUX_VAL(CP(ETK_D14_ES2),	(IEN  | PTD | EN  | M3)) /*HSUSB2_DATA0*/\
 MUX_VAL(CP(ETK_D15_ES2),	(IEN  | PTD | EN  | M3)) /*HSUSB2_DATA1*/\
 /*Control and debug */\
 MUX_VAL(CP(SYS_32K),		(IEN  | PTD | DIS | M0)) /*SYS_32K*/\
 MUX_VAL(CP(SYS_CLKREQ),	(IEN  | PTU | EN  | M4)) /*GPIO_1 POP_INT0 (se connesso su PCB)*/\
 MUX_VAL(CP(SYS_BOOT0),		(IDIS | PTD | DIS | M4)) /*GPIO_2*/\
 MUX_VAL(CP(SYS_BOOT1),		(IEN  | PTD | DIS | M4)) /*GPIO_3*/\
 MUX_VAL(CP(SYS_BOOT2),		(IDIS | PTD | DIS | M4)) /*GPIO_4*/\
 MUX_VAL(CP(SYS_BOOT3),		(IEN  | PTD | DIS | M4)) /*GPIO_5*/\
 MUX_VAL(CP(SYS_BOOT4),		(IEN  | PTD | DIS | M4)) /*GPIO_6*/\
 MUX_VAL(CP(SYS_BOOT5),		(IEN  | PTD | DIS | M4)) /*GPIO_7*/\
 MUX_VAL(CP(SYS_BOOT6),		(IEN  | PTD | DIS | M4)) /*SYS_BOOT6*/ \
 MUX_VAL(CP(SYS_OFF_MODE),	(IEN  | PTD | DIS | M0)) /*SYS_OFF_MODE*/\
 MUX_VAL(CP(SYS_CLKOUT1),	(IEN  | PTU | EN  | M4)) /*GPIO_10 POP_TMP (se connesso su PCB)*/\
 MUX_VAL(CP(SYS_CLKOUT2),	(IEN  | PTU | EN  | M4)) /*GPIO_186 POP_INT1 (se connesso su PCB)*/\
 MUX_VAL(CP(ETK_CLK_ES2),	(IEN  | PTU | DIS | M2)) /*MMC3_CLK*/\
 MUX_VAL(CP(ETK_CTL_ES2),	(IEN  | PTU | DIS | M2)) /*MMC3_CMD*/\
 MUX_VAL(CP(ETK_D0_ES2),	(IEN  | PTD | DIS | M7)) /*Unused*/\
 MUX_VAL(CP(ETK_D1_ES2),	(IEN  | PTD | DIS | M7)) /*Unused*/\
 MUX_VAL(CP(ETK_D2_ES2),	(IDIS | PTD | DIS | M4)) /*GPIO 16*/\
 MUX_VAL(CP(ETK_D3_ES2),	(IEN  | PTU | DIS | M2)) /*MMC3_DAT3*/\
 MUX_VAL(CP(ETK_D4_ES2),	(IEN  | PTU | DIS | M2)) /*MMC3_DAT0*/\
 MUX_VAL(CP(ETK_D5_ES2),	(IEN  | PTU | DIS | M2)) /*MMC3_DAT1*/\
 MUX_VAL(CP(ETK_D6_ES2),	(IEN  | PTU | DIS | M2)) /*MMC3_DAT2*/\
 MUX_VAL(CP(ETK_D7_ES2),	(IDIS | PTU | EN  | M4)) /*GPIO_21 - nRESET_TSC_1V8*/\
 MUX_VAL(CP(ETK_D8_ES2),	(IDIS | PTU | EN  | M3)) /* HSUSB1_DIR   CONTROLLARE */\
 MUX_VAL(CP(ETK_D9_ES2),	(IEN  | PTU | DIS | M4)) /*MMC3_ENABLED*/
#endif
