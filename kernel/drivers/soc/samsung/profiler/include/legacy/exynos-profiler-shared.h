/* exynos-profiler-shared.h
 *
 * Copyright (C) 2020 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com
 *
 * EXYNOS - Header file for Exynos Multi IP Governor support
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __EXYNOS_PROFILER_SHARED_H
#define __EXYNOS_PROFILER_SHARED_H

#include <exynos-profiler-if.h>

/* Shared Data between profiler modules */
struct profile_sharing_data {
	s32	monitor;

	s64	profile_time_ms;
	s64     frame_done_time_us;
	s64     frame_vsync_time_us;
	u64	profile_frame_cnt;
	u64	profile_frame_vsync_cnt;
	u64	profile_fence_cnt;
	s64	profile_fence_time_us;
	s32	user_target_fps;
	s32     frame_cnt_by_swap;
	u64     delta_ms_by_swap;

	/* Domain common data */
	s32	max_freq[NUM_OF_DOMAIN];
	s32	min_freq[NUM_OF_DOMAIN];
	s32	freq[NUM_OF_DOMAIN];
	u64	dyn_power[NUM_OF_DOMAIN];
	u64	st_power[NUM_OF_DOMAIN];
	s32	temp[NUM_OF_DOMAIN];
	s32	active_pct[NUM_OF_DOMAIN];

	/* CPU domain private data */
	s32	cpu_active_pct[NUM_OF_CPU_DOMAIN][MAXNUM_OF_CPU];

	/* GPU domain private data */
	u64	cputracer;
	u32	swapcaller_id;
	u32	reserved_gpu1;
	u64	reserved_gpu2;

	/* GPU RenderingTime */
	u64     rtimes[NUM_OF_TIMEINFO];
	u16     pid_list[NUM_OF_PID];

	/* MIF domain private data */
	u64	stats0_sum;
	u64	stats0_ratio;
	u64	stats0_avg;
	u64	stats1_sum;
	u64	stats1_ratio;
	u64	stats2_sum;
	u64	stats2_ratio;
	u64	llc_status;
	s32	mif_pm_qos_cur_freq;
};

struct tunable_sharing_data {
	s32	monitor;
	s32	profile_only;
	s32	window_period;
	s32	window_number;
	s32	active_pct_thr;
	s32	valid_freq_delta_pct;
	s32	min_sensitivity;
	s32	cpu_bottleneck_thr;
	s32	mif_bottleneck_thr;
	s32	gpu_bottleneck_thr;
	s32	version;
	s32	frame_src;
	s32	max_fps;
	s32	dt_ctrl_en;
	s32	dt_over_thr;
	s32	dt_under_thr;
	s32	dt_up_step;
	s32	dt_down_step;
	s32	dpat_upper_thr;
	s32	dpat_lower_thr;
	s32	dpat_lower_cnt_thr;
	s32	dpat_up_step;
	s32	dpat_down_step;
	s32	inc_perf_temp_thr;
	s32	inc_perf_power_thr;
	s32	dyn_mo_control;

	s32	inc_perf_thr;
	s32	dec_perf_thr;

	/* Domain common data */
	bool	enabled[NUM_OF_DOMAIN];
	s32	freq_table[NUM_OF_DOMAIN][MAXNUM_OF_DVFS];
	s32	freq_table_cnt[NUM_OF_DOMAIN];
	s32	max_margin[NUM_OF_DOMAIN];
	s32	min_margin[NUM_OF_DOMAIN];
	s32	margin_up_step[NUM_OF_DOMAIN];
	s32	margin_down_step[NUM_OF_DOMAIN];
	s32	margin_default_step[NUM_OF_DOMAIN];
	s32	minlock_low_limit[NUM_OF_DOMAIN];
	s32	maxlock_high_limit[NUM_OF_DOMAIN];

	/* CPU domain private data */
	s32	first_cpu[NUM_OF_CPU_DOMAIN];
	s32	num_of_cpu[NUM_OF_CPU_DOMAIN];
	s32	asv_ids[NUM_OF_CPU_DOMAIN];
	s32	hp_minlock_low_limit[NUM_OF_CPU_DOMAIN];
	s32	lp_minlock_low_limit[NUM_OF_CPU_DOMAIN];

	/* GPU domain private data */
	u64	gpu_hw_status;
	u64	reserved_gpu1;
	u64	reserved_gpu2;

	/* MIF domain private data */
	s32	stats0_mode_min_freq;
	u64	stats0_sum_thr;
	u64	stats0_updown_delta_pct_thr;
	s32	mif_hp_minlock_low_limit;

	/* minlock mode data */
	s32	hp_minlock_fps_delta_pct_thr;
	s32	hp_minlock_power_upper_thr;
	s32	hp_minlock_power_lower_thr;

	s32	runtime_thr[6];

	/* Render-Time Based Control */
	s32     pid_cpu[3];
	s32     pid_gpu[3];
	s32     pid_util[3];
	s32	pid_util_max[NUM_OF_DOMAIN];
	s32	pid_util_min[NUM_OF_DOMAIN];
	s32	pid_util_lpmax[NUM_OF_DOMAIN];
	s32	pid_util_lpmin[NUM_OF_DOMAIN];
};

struct delta_sharing_data {
	s32	id;
	s32	freq_delta_pct;
	u32	freq;
	u64	dyn_power;
	u64	st_power;
};


/*
 * 1st argument is profiler-id & op-code in set_margin_store
 * |				|     OPCODE	| IP-ID	|
 * 31				11		3	0
 */
#define IP_ID_MASK	0xF
#define OP_CODE_MASK	0xFF
#define OP_CODE_SHIFT	0x4
enum control_op_code {
	OP_INVALID = 0,
	OP_PM_QOS_MAX = 1,
	OP_PM_QOS_MIN = 2,
	OP_MARGIN = 3,
	OP_MO = 4,
	OP_LLC = 5,
	OP_RTP_TARGETFRAMETIME = 6,
	OP_RTP_TARGETTIMEMARGIN = 7,
	OP_RTP_UTIL_MARGIN = 8,
	OP_RTP_DECON_TIME = 9,
	OP_RTP_COMBCTRL = 10,
	OP_CPUTRACER_SIZE = 11,
};

#endif /* EXYNOS_PROFILER_SHARED_H */
