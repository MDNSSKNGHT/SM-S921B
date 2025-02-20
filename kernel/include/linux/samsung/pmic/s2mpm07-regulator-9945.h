/*
 * s2mpm07-private.h - Voltage regulator driver for the S2MPM07
 *
 *  Copyright (C) 2023 Samsung Electrnoics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __LINUX_MFD_S2MPM07_REGULATOR_H
#define __LINUX_MFD_S2MPM07_REGULATOR_H
#include <linux/i2c.h>

#if IS_ENABLED(CONFIG_S2MPM07_ADC)
#include <linux/iio/iio.h>
#include <linux/iio/machine.h>
#include <linux/iio/driver.h>
#include <linux/iio/consumer.h>
#endif

/* RF slave id */
enum s2mpm07_sid {
	RF_ID = 0x02,
};

/* base address */
enum s2mpm07_base_addr {
	VGPIO_ADDR = 0x00,
	COM_ADDR = 0x03,
	PMIC1_ADDR = 0x05,
	CLOSE1_ADDR = 0x0E,
	ADC_ADDR = 0x0A,
	GPIO_ADDR = 0x0B,
	TEMP_ADDR = 0x0C,
};

#define S2MPM07_REG_INVALID             (0xFF)

/* VGPIO ADDRESS (0x00) */
#define S2MPM07_REG_REG0		0x00
#define S2MPM07_REG_PSI			0x01
#define S2MPM07_REG_VGI0		0x02
#define S2MPM07_REG_VGI1		0x03
#define S2MPM07_REG_VGI2		0x04
#define S2MPM07_REG_VGI3		0x05
#define S2MPM07_REG_VGI4		0x06
#define S2MPM07_REG_VGI5		0x07
#define S2MPM07_REG_VGI6		0x08
#define S2MPM07_REG_VGI7		0x09
#define S2MPM07_REG_VGI8		0x0A
#define S2MPM07_REG_VGI9		0x0B
#define S2MPM07_REG_VGI10		0x0C
#define S2MPM07_REG_VGI11		0x0D
#define S2MPM07_REG_VGI12		0x0E
#define S2MPM07_REG_VGI13		0x0F
#define S2MPM07_REG_VGI14		0x10
#define S2MPM07_REG_VGI15		0x11
#define S2MPM07_REG_VGI16		0x12
#define S2MPM07_REG_VGI17		0x13
#define S2MPM07_REG_VGI18		0x14

/* COMMON ADDRESS (0x03) */
#define S2MPM07_REG_VGPIO_REG0_1	0x00
#define S2MPM07_REG_VGPIO_REG0_2	0x01
#define S2MPM07_REG_CHIP_ID		0x0E
#define S2MPM07_REG_SPMI_CFG1		0x0F
#define S2MPM07_REG_SPMI_CFG2		0x10
#define S2MPM07_REG_SPMI_CFG3		0x11
#define S2MPM07_REG_COM_CTRL1		0x12
#define S2MPM07_REG_COM_CTRL2		0x13
#define S2MPM07_REG_COM_CTRL3		0x14
#define S2MPM07_REG_DUMP_CTRL		0x15
#define S2MPM07_REG_TX_MASK		0x16
#define S2MPM07_REG_IRQ			0x17
#define S2MPM07_REG_COM_CTRL4		0x18
#define S2MPM07_REG_COM_CLK_ON		0x19
#define S2MPM07_REG_COM_CLK_OFF		0x1A
#define S2MPM07_REG_COM_OM		0x1B
#define S2MPM07_REG_COM_OTP_TEST	0x1C
#define S2MPM07_REG_COM_OTP_ADRL	0x1D
#define S2MPM07_REG_COM_OTP_ADRH	0x1E
#define S2MPM07_REG_COM_OTP_DATA	0x1F
#define S2MPM07_REG_COM_MONSEL1		0x20
#define S2MPM07_REG_COM_MONSEL2		0x21
#define S2MPM07_REG_COM_MONRD1		0x22
#define S2MPM07_REG_COM_MONRD2		0x23
#define S2MPM07_REG_COM_CCD		0x24
#define S2MPM07_REG_CHECKSUM_DATA	0x25
#define S2MPM07_REG_CHECKSUM_REF	0x26
#define S2MPM07_REG_CHECKSUM_RESULT	0x27
#define S2MPM07_REG_BUCK_OM		0x28
#define S2MPM07_REG_BUCK_MON_SEL	0x29
#define S2MPM07_REG_BUCK_MON_EN1	0x2A

/* CHIP ID MASK */
#define S2MPM07_CHIP_ID_MASK			(0xFF)
#define S2MPM07_CHIP_ID_HW_MASK			(0x0F)
#define S2MPM07_CHIP_ID_SW_MASK			(0xF0)

/* TX_MASK MASK */
#define S2MPM07_GPIO_IRQM_MASK			(1 << 2)
#define S2MPM07_ADC_IRQM_MASK			(1 << 1)
#define S2MPM07_PM_IRQM_MASK			(1 << 0)

/* IRQ MASK */
#define S2MPM07_GPIO_IRQ			(1 << 2)
#define S2MPM07_ADC_IRQ				(1 << 1)
#define S2MPM07_PM_IRQ				(1 << 0)

/* PMIC 1 ADDRESS (0x05) */
#define S2MPM07_REG_INT1		0x00
#define S2MPM07_REG_INT2		0x01
#define S2MPM07_REG_INT3		0x02
#define S2MPM07_REG_INT1M		0x03
#define S2MPM07_REG_INT2M		0x04
#define S2MPM07_REG_INT3M		0x05
#define S2MPM07_REG_STATUS1		0x06
#define S2MPM07_REG_STATUS2		0x07
#define S2MPM07_REG_OFFSRC1_CUR		0x08
#define S2MPM07_REG_OFFSRC2_CUR		0x09
#define S2MPM07_REG_OFFSRC1_OLD1	0x0A
#define S2MPM07_REG_OFFSRC2_OLD1	0x0B
#define S2MPM07_REG_OFFSRC1_OLD2	0x0C
#define S2MPM07_REG_OFFSRC2_OLD2	0x0D

#define S2MPM07_REG_CTRL1		0x17
#define S2MPM07_REG_CTRL2		0x18
#define S2MPM07_REG_CTRL3		0x19
#define S2MPM07_REG_ETC_OTP1		0x1A
#define S2MPM07_REG_ETC_OTP2		0x1B
#define S2MPM07_REG_UVLO_OTP		0x1C
#define S2MPM07_REG_CFG_PM		0x1D
#define S2MPM07_REG_TIME_CTRL		0x1E
#define S2MPM07_REG_BUCK1R_CTRL		0x1F
#define S2MPM07_REG_BUCK1R_OUT1		0x20
#define S2MPM07_REG_BUCK1R_OUT2		0x21
#define S2MPM07_REG_BUCK1R_OUT3		0x22
#define S2MPM07_REG_BUCK1R_OUT4		0x23
#define S2MPM07_REG_BUCK1R_DVS		0x24
#define S2MPM07_REG_BUCK1R_OCP		0x25
#define S2MPM07_REG_BUCK1R_AVP		0x26
#define S2MPM07_REG_BUCK_SR1R_CTRL	0x27
#define S2MPM07_REG_BUCK_SR1R_OUT1	0x28
#define S2MPM07_REG_BUCK_SR1R_OUT2	0x29
#define S2MPM07_REG_BUCK_SR1R_DVS	0x2A
#define S2MPM07_REG_BUCK_SR1R_OCP	0x2B
#define S2MPM07_REG_DVS_LDO8_CTRL	0x2C
#define S2MPM07_REG_DVS_LDO_OFFSET1	0x2D
#define S2MPM07_REG_DVS_LDO_RAMP	0x2E
#define S2MPM07_REG_LDO1R_CTRL		0x2F
#define S2MPM07_REG_LDO1R_OUT		0x30
#define S2MPM07_REG_LDO2R_CTRL		0x31
#define S2MPM07_REG_LDO2R_OUT1		0x32
#define S2MPM07_REG_LDO2R_OUT2		0x33
#define S2MPM07_REG_LDO2R_OUT3		0x34
#define S2MPM07_REG_LDO2R_OUT4		0x35
#define S2MPM07_REG_LDO3R_CTRL		0x36
#define S2MPM07_REG_LDO3R_OUT		0x37
#define S2MPM07_REG_LDO4R_CTRL		0x38
#define S2MPM07_REG_LDO4R_OUT		0x39
#define S2MPM07_REG_LDO5R_CTRL		0x3A
#define S2MPM07_REG_LDO5R_OUT		0x3B
#define S2MPM07_REG_LDO6R_CTRL		0x3C
#define S2MPM07_REG_LDO7R_CTRL		0x3D
#define S2MPM07_REG_LDO7R_OUT		0x3E
#define S2MPM07_REG_LDO8R_CTRL		0x3F
#define S2MPM07_REG_LDO8R_OUT		0x40
#define S2MPM07_REG_LDO9R_CTRL		0x41
#define S2MPM07_REG_LDO9R_OUT		0x42
#define S2MPM07_REG_LDO10R_CTRL		0x43
#define S2MPM07_REG_LDO11R_CTRL		0x44
#define S2MPM07_REG_LDO12R_CTRL		0x45
#define S2MPM07_REG_LDO12R_OUT		0x46
#define S2MPM07_REG_LDO13R_CTRL		0x47
#define S2MPM07_REG_LDO13R_OUT		0x48
#define S2MPM07_REG_LDO14R_CTRL		0x49
#define S2MPM07_REG_LDO14R_OUT		0x4A
#define S2MPM07_REG_LDO15R_CTRL		0x4B
#define S2MPM07_REG_LDO15R_OUT		0x4C
#define S2MPM07_REG_LDO16R_CTRL		0x4D
#define S2MPM07_REG_LDO17R_CTRL		0x4E
#define S2MPM07_REG_LDO18R_CTRL		0x4F
#define S2MPM07_REG_LDO19R_CTRL		0x50
#define S2MPM07_REG_LDO20R_CTRL		0x51
#define S2MPM07_REG_LDO21R_CTRL		0x52
#define S2MPM07_REG_LDO22R_CTRL		0x53
#define S2MPM07_REG_LDO23R_CTRL		0x54
#define S2MPM07_REG_LDO_DSCH1		0x55
#define S2MPM07_REG_LDO_DSCH2		0x56
#define S2MPM07_REG_LDO_DSCH3		0x57
#define S2MPM07_REG_LDO_2INP		0x57

/* PMIC 1 mask */
#define BUCK_RAMP_MASK			(0x03)
#define BUCK_RAMP_UP_SHIFT		6

/* S2MPM07 regulator ids */
enum s2mpm07_regulators {
	S2MPM07_BUCK1,
	S2MPM07_BUCK_SR1,
	//S2MPM07_LDO1,
	//S2MPM07_LDO2,
	//S2MPM07_LDO3,
	//S2MPM07_LDO4,
	//S2MPM07_LDO5,
	//S2MPM07_LDO6,
	//S2MPM07_LDO7,
	//S2MPM07_LDO8,
	//S2MPM07_LDO9,
	//S2MPM07_LDO10,
	S2MPM07_LDO11,
	//S2MPM07_LDO12,
	//S2MPM07_LDO13,
	//S2MPM07_LDO14,
	//S2MPM07_LDO15,
	//S2MPM07_LDO16,
	//S2MPM07_LDO17,
	S2MPM07_LDO18,
	S2MPM07_LDO19,
	//S2MPM07_LDO20,
	//S2MPM07_LDO21,
	S2MPM07_REG_MAX,
};

/* BUCKs 1R */
#define S2MPM07_BUCK_MIN1	300000
#define S2MPM07_BUCK_STEP1	6250
/* BUCKs SR1R */
#define S2MPM07_BUCK_MIN2	300000
#define S2MPM07_BUCK_STEP2	6250
/* (LV) NLDOs -> L1R, L2R, L3R, L4R, L5R, L7R, L8R, L9R, L12R, L13R, L14R, L15R */
#define S2MPM07_LDO_MIN1	300000
#define S2MPM07_LDO_STEP1	6250
/* (IV) PLDOs -> L6R, L10R, L16R, L17R */
#define S2MPM07_LDO_MIN2	1500000
#define S2MPM07_LDO_STEP2	12500
/* (MV) PLDOs L11R, L18R, L19R, L20R, L21R, L22R, L23R */
#define S2MPM07_LDO_MIN3	1800000
#define S2MPM07_LDO_STEP3	25000

/* LDO/BUCK output voltage control */
#define S2MPM07_LDO_VSEL_MASK1	0xFF	/* LDO_OUT  */
#define S2MPM07_LDO_VSEL_MASK2	0x3F	/* LDO_CTRL */
#define S2MPM07_BUCK_VSEL_MASK	0xFF	/* BUCK_OUT */
#define S2MPM07_BUCK_N_VOLTAGES (S2MPM07_BUCK_VSEL_MASK + 1)

/* Buck/LDO Enable control [7:6] */
#define S2MPM07_ENABLE_SHIFT	0x06
#define S2MPM07_ENABLE_MASK	(0x03 << S2MPM07_ENABLE_SHIFT)
#define SEL_VGPIO_ON		(0x01 << S2MPM07_ENABLE_SHIFT)

/* soft start time */
#define S2MPM07_ENABLE_TIME_LDO		128
#define S2MPM07_ENABLE_TIME_BUCK	130
#define S2MPM07_ENABLE_TIME_BUCK_SR	130

#define S2MPM07_REGULATOR_MAX (S2MPM07_REG_MAX)

enum s2mpm07_irq_source {
	S2MPM07_PMIC_INT1 = 0,
	S2MPM07_PMIC_INT2,
	S2MPM07_PMIC_INT3,
	S2MPM07_IRQ_GROUP_NR,
};

#define S2MPM07_NUM_IRQ_PMIC_REGS	3

enum s2mpm07_irq {
	/* PMIC */
	S2MPM07_PMIC_IRQ_PWRONF_INT1,
	S2MPM07_PMIC_IRQ_PWRONR_INT1,
	S2MPM07_PMIC_IRQ_120C_INT1,
	S2MPM07_PMIC_IRQ_140C_INT1,
	S2MPM07_PMIC_IRQ_TSD_INT1,
	S2MPM07_PMIC_IRQ_WTSR_INT1,
	S2MPM07_PMIC_IRQ_WRSTB_INT1,

	S2MPM07_PMIC_IRQ_OCP_B1R_INT2,
	S2MPM07_PMIC_IRQ_OCP_SR1R_INT2,
	S2MPM07_PMIC_IRQ_OI_SR1R_INT2,
	S2MPM07_PMIC_IRQ_OVP_INT2,
	S2MPM07_PMIC_IRQ_BUCK_AUTO_EXIT_INT2,

	S2MPM07_PMIC_IRQ_OI_LDO20R_INT3,
	S2MPM07_PMIC_IRQ_OI_LDO21R_INT3,
	S2MPM07_PMIC_IRQ_TX_TRAN_FAIL_INT3,
	S2MPM07_PMIC_IRQ_CHECKSUM_INT3,
	S2MPM07_PMIC_IRQ_PARITY_ERR0_INT3,
	S2MPM07_PMIC_IRQ_PARITY_ERR1_INT3,
	S2MPM07_PMIC_IRQ_PARITY_ERR2_INT3,
	S2MPM07_PMIC_IRQ_PARITY_ERR3_INT3,

	S2MPM07_IRQ_NR,
};

enum sec_device_type {
	S2MPM07X,
};

struct s2mpm07_dev {
	struct device *dev;
	struct s2mpm07_platform_data *pdata;
	struct i2c_client *com;
	struct i2c_client *vgpio;
	struct i2c_client *pmic1;
	struct i2c_client *close1;
	struct i2c_client *adc_i2c;
	struct i2c_client *gpio;
	struct mutex i2c_lock;
	struct mutex irqlock;
	struct apm_ops *ops;

	bool wakeup;
	int type;
	int device_type;

	/* pmic VER/REV register */
	uint8_t pmic_rev;	/* pmic Rev */
};

enum s2mpm07_types {
	TYPE_S2MPM07,
};

/* S2MPM07 shared i2c API function */
extern int s2mpm07_read_reg(struct i2c_client *i2c, uint8_t reg, uint8_t *dest);
extern int s2mpm07_bulk_read(struct i2c_client *i2c, uint8_t reg, int count,
				uint8_t *buf);
extern int s2mpm07_write_reg(struct i2c_client *i2c, uint8_t reg, uint8_t value);
extern int s2mpm07_bulk_write(struct i2c_client *i2c, uint8_t reg, int count,
				uint8_t *buf);
extern int s2mpm07_write_word(struct i2c_client *i2c, uint8_t reg, uint16_t value);
extern int s2mpm07_read_word(struct i2c_client *i2c, uint8_t reg);
extern int s2mpm07_update_reg(struct i2c_client *i2c, uint8_t reg, uint8_t val, uint8_t mask);
#endif /* __LINUX_MFD_S2MPM07_REGULATOR_H */
