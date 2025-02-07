/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Samsung Exynos SoC series Sensor driver
 *
 *
 * Copyright (c) 2016 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef IS_CIS_IMX374_H
#define IS_CIS_IMX374_H

#include "is-cis.h"

/* FIXME */
#define SENSOR_IMX374_MAX_WIDTH		(3976 + 0)
#define SENSOR_IMX374_MAX_HEIGHT		(2736 + 0)

#define SENSOR_IMX374_FINE_INTEGRATION_TIME_MIN                0x100
#define SENSOR_IMX374_FINE_INTEGRATION_TIME_MAX                0x100
#define SENSOR_IMX374_COARSE_INTEGRATION_TIME_MIN              0x4
#define SENSOR_IMX374_COARSE_INTEGRATION_TIME_MAX_MARGIN       0x10

#define USE_GROUP_PARAM_HOLD	(0)

enum sensor_imx374_mode_enum {
	SENSOR_IMX374_3648x2736_30FPS = 0,
	SENSOR_IMX374_3968x2232_30FPS,
	SENSOR_IMX374_3968x2232_60FPS,
	SENSOR_IMX374_1984x1120_30FPS,
	SENSOR_IMX374_1984x1120_120FPS,
	SENSOR_IMX374_1824x1368_30FPS,
	SENSOR_IMX374_912x684_120FPS,
	SENSOR_IMX374_MODE_MAX
};

struct sensor_imx374_private_data {
	const struct sensor_regs global;
};

struct sensor_imx374_private_runtime {
	unsigned int lte_vsync;
};

static const struct sensor_reg_addr sensor_imx374_reg_addr = {
	.fll = 0x0340,
	.fll_shifter = 0x0702,
	.cit = 0x0202,
	.cit_shifter = 0x0704,
	.again = 0x0204,
	.dgain = 0x020E,
	.group_param_hold = 0x0104,
};

#endif
