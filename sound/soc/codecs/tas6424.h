// SPDX-License-Identifier: GPL-2.0
/*
 * ALSA SoC Texas Instruments TAS6424 Quad-Channel Audio Amplifier
 *
 * Copyright (C) 2016-2017 Texas Instruments Incorporated - http://www.ti.com/
 *	Author: Andreas Dannenberg <dannenberg@ti.com>
 *	Andrew F. Davis <afd@ti.com>
 */

#ifndef __TAS6424_H__
#define __TAS6424_H__

#define TAS6424_RATES (SNDRV_PCM_RATE_44100 | \
		       SNDRV_PCM_RATE_48000 | \
		       SNDRV_PCM_RATE_96000)

#define TAS6424_FORMATS (SNDRV_PCM_FMTBIT_S16_LE | \
			 SNDRV_PCM_FMTBIT_S24_LE)

/* Register Address Map */
#define TAS6424_MODE_CTRL		0x00
#define TAS6424_MISC_CTRL1		0x01
#define TAS6424_MISC_CTRL2		0x02
#define TAS6424_SAP_CTRL		0x03
#define TAS6424_CH_STATE_CTRL		0x04
#define TAS6424_CH1_VOL_CTRL		0x05
#define TAS6424_CH2_VOL_CTRL		0x06
#define TAS6424_CH3_VOL_CTRL		0x07
#define TAS6424_CH4_VOL_CTRL		0x08
#define TAS6424_DC_DIAG_CTRL1		0x09
#define TAS6424_DC_DIAG_CTRL2		0x0a
#define TAS6424_DC_DIAG_CTRL3		0x0b
#define TAS6424_DC_LOAD_DIAG_REP12	0x0c
#define TAS6424_DC_LOAD_DIAG_REP34	0x0d
#define TAS6424_DC_LOAD_DIAG_REPLO	0x0e
#define TAS6424_CHANNEL_STATE		0x0f
#define TAS6424_CHANNEL_FAULT		0x10
#define TAS6424_GLOB_FAULT1		0x11
#define TAS6424_GLOB_FAULT2		0x12
#define TAS6424_WARN			0x13
#define TAS6424_PIN_CTRL		0x14
#define TAS6424_AC_DIAG_CTRL1		0x15
#define TAS6424_AC_DIAG_CTRL2		0x16
#define TAS6424_AC_LOAD_DIAG_REP1	0x17
#define TAS6424_AC_LOAD_DIAG_REP2	0x18
#define TAS6424_AC_LOAD_DIAG_REP3	0x19
#define TAS6424_AC_LOAD_DIAG_REP4	0x1a
#define TAS6424_MISC_CTRL3		0x21
#define TAS6424_CLIP_CTRL		0x22
#define TAS6424_CLIP_WINDOW		0x23
#define TAS6424_CLIP_WARN		0x24
#define TAS6424_CBC_STAT		0x25
#define TAS6424_MISC_CTRL4		0x26
#define TAS6424_MAX			TAS6424_MISC_CTRL4

/* TAS6424_MODE_CTRL_REG */
#define TAS6424_RESET			BIT(7)

/* TAS6424_SAP_CTRL_REG */
#define TAS6424_SAP_RATE_MASK		GENMASK(7, 6)
#define TAS6424_SAP_RATE_44100		(0x00 << 6)
#define TAS6424_SAP_RATE_48000		(0x01 << 6)
#define TAS6424_SAP_RATE_96000		(0x02 << 6)
#define TAS6424_SAP_TDM_SLOT_LAST	BIT(5)
#define TAS6424_SAP_TDM_SLOT_SZ_16	BIT(4)
#define TAS6424_SAP_TDM_SLOT_SWAP	BIT(3)
#define TAS6424_SAP_FMT_MASK		GENMASK(2, 0)
#define TAS6424_SAP_RIGHTJ_24		(0x00 << 0)
#define TAS6424_SAP_RIGHTJ_20		(0x01 << 0)
#define TAS6424_SAP_RIGHTJ_18		(0x02 << 0)
#define TAS6424_SAP_RIGHTJ_16		(0x03 << 0)
#define TAS6424_SAP_I2S			(0x04 << 0)
#define TAS6424_SAP_LEFTJ		(0x05 << 0)
#define TAS6424_SAP_DSP			(0x06 << 0)

/* TAS6424_CH_STATE_CTRL_REG */
#define TAS6424_CH1_STATE_MASK		GENMASK(7, 6)
#define TAS6424_CH1_STATE_PLAY		(0x00 << 6)
#define TAS6424_CH1_STATE_HIZ		(0x01 << 6)
#define TAS6424_CH1_STATE_MUTE		(0x02 << 6)
#define TAS6424_CH1_STATE_DIAG		(0x03 << 6)
#define TAS6424_CH2_STATE_MASK		GENMASK(5, 4)
#define TAS6424_CH2_STATE_PLAY		(0x00 << 4)
#define TAS6424_CH2_STATE_HIZ		(0x01 << 4)
#define TAS6424_CH2_STATE_MUTE		(0x02 << 4)
#define TAS6424_CH2_STATE_DIAG		(0x03 << 4)
#define TAS6424_CH3_STATE_MASK		GENMASK(3, 2)
#define TAS6424_CH3_STATE_PLAY		(0x00 << 2)
#define TAS6424_CH3_STATE_HIZ		(0x01 << 2)
#define TAS6424_CH3_STATE_MUTE		(0x02 << 2)
#define TAS6424_CH3_STATE_DIAG		(0x03 << 2)
#define TAS6424_CH4_STATE_MASK		GENMASK(1, 0)
#define TAS6424_CH4_STATE_PLAY		(0x00 << 0)
#define TAS6424_CH4_STATE_HIZ		(0x01 << 0)
#define TAS6424_CH4_STATE_MUTE		(0x02 << 0)
#define TAS6424_CH4_STATE_DIAG		(0x03 << 0)
#define TAS6424_ALL_STATE_PLAY		(TAS6424_CH1_STATE_PLAY | \
					 TAS6424_CH2_STATE_PLAY | \
					 TAS6424_CH3_STATE_PLAY | \
					 TAS6424_CH4_STATE_PLAY)
#define TAS6424_ALL_STATE_HIZ		(TAS6424_CH1_STATE_HIZ | \
					 TAS6424_CH2_STATE_HIZ | \
					 TAS6424_CH3_STATE_HIZ | \
					 TAS6424_CH4_STATE_HIZ)
#define TAS6424_ALL_STATE_MUTE		(TAS6424_CH1_STATE_MUTE | \
					 TAS6424_CH2_STATE_MUTE | \
					 TAS6424_CH3_STATE_MUTE | \
					 TAS6424_CH4_STATE_MUTE)
#define TAS6424_ALL_STATE_DIAG		(TAS6424_CH1_STATE_DIAG | \
					 TAS6424_CH2_STATE_DIAG | \
					 TAS6424_CH3_STATE_DIAG | \
					 TAS6424_CH4_STATE_DIAG)

/* TAS6424_DC_DIAG_CTRL1 */
#define TAS6424_LDGBYPASS_SHIFT		0
#define TAS6424_LDGBYPASS_MASK		BIT(TAS6424_LDGBYPASS_SHIFT)

/* TAS6424_GLOB_FAULT1_REG */
#define TAS6424_FAULT_OC_CH1		BIT(7)
#define TAS6424_FAULT_OC_CH2		BIT(6)
#define TAS6424_FAULT_OC_CH3		BIT(5)
#define TAS6424_FAULT_OC_CH4		BIT(4)
#define TAS6424_FAULT_DC_CH1		BIT(3)
#define TAS6424_FAULT_DC_CH2		BIT(2)
#define TAS6424_FAULT_DC_CH3		BIT(1)
#define TAS6424_FAULT_DC_CH4		BIT(0)

/* TAS6424_GLOB_FAULT1_REG */
#define TAS6424_FAULT_CLOCK		BIT(4)
#define TAS6424_FAULT_PVDD_OV		BIT(3)
#define TAS6424_FAULT_VBAT_OV		BIT(2)
#define TAS6424_FAULT_PVDD_UV		BIT(1)
#define TAS6424_FAULT_VBAT_UV		BIT(0)

/* TAS6424_GLOB_FAULT2_REG */
#define TAS6424_FAULT_OTSD		BIT(4)
#define TAS6424_FAULT_OTSD_CH1		BIT(3)
#define TAS6424_FAULT_OTSD_CH2		BIT(2)
#define TAS6424_FAULT_OTSD_CH3		BIT(1)
#define TAS6424_FAULT_OTSD_CH4		BIT(0)

/* TAS6424_WARN_REG */
#define TAS6424_WARN_VDD_UV		BIT(6)
#define TAS6424_WARN_VDD_POR		BIT(5)
#define TAS6424_WARN_VDD_OTW		BIT(4)
#define TAS6424_WARN_VDD_OTW_CH1	BIT(3)
#define TAS6424_WARN_VDD_OTW_CH2	BIT(2)
#define TAS6424_WARN_VDD_OTW_CH3	BIT(1)
#define TAS6424_WARN_VDD_OTW_CH4	BIT(0)

/* TAS6424_MISC_CTRL3_REG */
#define TAS6424_CLEAR_FAULT		BIT(7)
#define TAS6424_PBTL_CH_SEL		BIT(6)
#define TAS6424_MASK_CBC_WARN		BIT(5)
#define TAS6424_MASK_VDD_UV		BIT(4)
#define TAS6424_OTSD_AUTO_RECOVERY	BIT(3)

#endif /* __TAS6424_H__ */
