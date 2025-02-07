/*
 * sec-auth-ds28e30.h - header file of authon driver
 *
 * Copyright (C) 2023 Samsung Electronics Co.Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#ifndef __SEC_AUTH_DS28E30_H__
#define __SEC_AUTH_DS28E30_H__

#define CounterValue_MSB	0x01
#define CounterValue_2LSB	0x86
#define CounterValue_LSB	0xA0

#define SEC_AUTH_RETRY		(10)
#define HOUR_SEC			(3600)
#define HOUR_NS				(3600000000000)   /* ((u64)HOUR_SEC * 1000000000) */
#define DAY_NS				(86400000000000)  /* ((u64)(24) * HOUR_NS) */
#define MAX_WORK_DELAY		(HOUR_SEC)
#define MAX_DECR_LOOP		(5)

ssize_t sec_auth_show_attrs(struct device *dev,
				struct device_attribute *attr, char *buf);

ssize_t sec_auth_store_attrs(struct device *dev,
				struct device_attribute *attr,
				const char *buf, size_t count);

#define SEC_AUTH_ATTR(_name)				\
{							\
	.attr = {.name = #_name, .mode = 0664},	\
	.show = sec_auth_show_attrs,			\
	.store = sec_auth_store_attrs,			\
}
enum {
	PRESENCE = 0,
	BATT_AUTH,
	DECREMENT_COUNTER,
	FIRST_USE_DATE,
	USE_DATE_WLOCK,
	BATT_DISCHARGE_LEVEL,
	BATT_FULL_STATUS_USAGE,
	BSOH,
	BSOH_RAW,
	QR_CODE,
	ASOC,
	CAP_NOM,
	CAP_MAX,
	BATT_THM_MIN,
	BATT_THM_MAX,
	UNSAFETY_TEMP,
	VBAT_OVP,
	RECHARGING_COUNT,
	SAFETY_TIMER,
	DROP_SENSOR,
	SYNC_BUF_MEM,
	FAI_EXPIRED,
	BATT_HEATMAP,
#ifdef SEC_AUTH_DEBUG
	GPIO_STATE,
	GPIO_DIRECTION,
	CHECK_OW_READ,
	CHECK_ROM_MAN,
	CHECK_SYSPUB_X,
	CHECK_SYSPUB_Y,
	PAGE_DATA_BUF,
	PAGE_DATA_MEM,
	PAGE_BUF_INIT,
	PAGE_DIRTY_STATUS,
	PAGE_LOCK_STATUS,
	CHECK_CERTI_CONST,
	CHECK_ECDSA_CERTI,
	CONFIGURE_PARAM,
	WORK_START,
	AUTH_CPU_FREQ,
	AUTH_DEV_FREQ,
#endif
	AUTH_SYSFS_MAX,
};

typedef struct sec_auth_ds28e30_platform_data {
	int swi_gpio;
	struct gpio_desc *swi_gpio_desc;
	struct gpio_chip *swi_gpio_chip;
	unsigned int base_phys_addr_and_size[2];
	unsigned int control_and_data_offset[2];
	unsigned int control_and_data_bit[2];
	void *gpio_ctrl_reg;	// set input,ouptut
	void *gpio_data_reg;	// set High,low
	spinlock_t swi_lock;
} sec_auth_ds28e30_platform_data_t;

struct sec_auth_ds28e30_data {
	struct device *dev;
	sec_auth_ds28e30_platform_data_t *pdata;
	struct power_supply	*psy_sec_auth;
	struct mutex sec_auth_mutex;
	struct workqueue_struct *sec_auth_poll_wqueue;
	struct delayed_work sec_auth_poll_work;
	u64 sync_time;
};

#endif  /* __SEC_AUTH_DS28E30_H__ */
