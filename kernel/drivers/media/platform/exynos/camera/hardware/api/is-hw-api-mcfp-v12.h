// SPDX-License-Identifier: GPL-2.0
/*
 * Samsung Exynos SoC series Pablo driver
 *
 * MCFP HW control APIs
 *
 * Copyright (C) 2022 Samsung Electronics Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef IS_HW_API_MCFP_V12_0_H
#define IS_HW_API_MCFP_V12_0_H

/* v12 is copied from v11 */
#include "is-hw-api-mcfp-v11.h"

void mcfp_hw_s_hf_otf(struct pablo_mmio *base, u32 set_id, u32 enable);
void mcfp_hw_s_hf_input_size(struct pablo_mmio *base, u32 set_id, u32 width, u32 height);

#endif
