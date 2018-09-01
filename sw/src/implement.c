/*
 * implement.c
 *
 *  Created on: Nov 3, 2016
 *      Author: usevolt
 */


#include "implement.h"
#include "main.h"
#include "dashboard_generic.h"
#include "dashboard_uw180s.h"
#include "dashboard_uw100.h"
#include "dashboard_uw50.h"
#include "settings_impl_uw180s.h"
#include "settings_impl_uw50.h"
#include "settings_impl_uw100.h"

#define this 	((implement_st*)me)



void implement_set(hcu_impls_e implement) {
	if (implement < HCU_IMPLEMENT_COUNT) {
		dspl.user->active_implement = implement;

		if (implement == HCU_IMPLEMENT_UW180S) {
			dspl.user->implement = (void*) &dspl.user->uw180s;
		}
		else if (implement == HCU_IMPLEMENT_UW100) {
			dspl.user->implement = (void*) &dspl.user->uw100;
		}
		else if (implement == HCU_IMPLEMENT_UW50) {
			dspl.user->implement = (void*) &dspl.user->uw50;
		}
		hcu_set_implement(implement);
	}
	else {
		printf("Invalid implement type %u\n", implement);
	}
}




void implement_init(void *me, const void *initializer) {
	this->name = ((implement_st*)initializer)->name;
	this->callbacks = ((implement_st*)initializer)->callbacks;
}

#undef this

const implement_callbs_st uw180s_callbacks = {
		.dasboard_step = dashboard_uw180s_step,
		.dashboard_show = dashboard_uw180s_show,
		.settings_step = settings_impl_uw180s_step,
		.settings_show = settings_impl_uw180s_show
};


#define LOG_TYPE_INIT(x)	{\
			.length_mm = 3000, \
			.name = "" \
	} ,\


const uw180s_st uw180s = {
		.super = {
				.name = "UW180s",
				.callbacks = &uw180s_callbacks,
		},
		.bladesopen = {
				.name = STR_SETTINGS_UW180S_BUTTONBLADESOPEN,
				.setter = &icu_set_bladeopen_params,
				.max_speed_p = 500,
				.max_speed_n = 500,
				.min_speed_p = 80,
				.min_speed_n = 80,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.rotator = {
				.name = STR_SETTINGS_UW180S_BUTTONROTATOR,
				.setter = &hcu_set_rotator_params,
				.max_speed_p = 500,
				.max_speed_n = 500,
				.min_speed_p = 80,
				.min_speed_n = 80,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.saw = {
				.name = STR_SETTINGS_UW180S_BUTTONSAW,
				.setter = &icu_set_saw_params,
				.max_speed_p = 600,
				.max_speed_n = 350,
				.min_speed_p = 80,
				.min_speed_n = 80,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.tilt = {
				.name = STR_SETTINGS_UW180S_BUTTONTILT,
				.setter = &icu_set_tilt_params,
				.max_speed_p = 350,
				.max_speed_n = 350,
				.min_speed_p = 80,
				.min_speed_n = 80,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.feedopen = {
				.name = STR_SETTINGS_UW180S_BUTTONFEEDOPEN,
				.setter = &icu_set_feedopen_params,
				.max_speed_p = 600,
				.max_speed_n = 600,
				.min_speed_p = 80,
				.min_speed_n = 80,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.feed = {
				.name = STR_SETTINGS_UW180S_BUTTONFEED,
				.setter = &icu_set_feed_params,
				.max_speed_p = 850,
				.max_speed_n = 850,
				.min_speed_p = 80,
				.min_speed_n = 80,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.all_open = {
				.name = STR_SETTINGS_UW180S_BUTTONALLOPEN,
				.setter = &icu_set_allopen_params,
				.max_speed_p = 850,
				.max_speed_n = 850,
				.min_speed_p = 80,
				.min_speed_n = 80,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.impl1 = {
				.name = STR_SETTINGS_UW180S_BUTTONIMPL1,
				.setter = &hcu_set_impl1_params,
				.max_speed_p = 850,
				.max_speed_n = 850,
				.min_speed_p = 80,
				.min_speed_n = 80,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.impl2 = {
				.name = STR_SETTINGS_UW180S_BUTTONIMPL2,
				.setter = &hcu_set_impl2_params,
				.max_speed_p = 850,
				.max_speed_n = 850,
				.min_speed_p = 80,
				.min_speed_n = 80,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.len_enabled = true,
		.width_enabled = true,
		.vol_enabled = true,
		.len_calib = 66,
		.vol_calib = 0,
		.log_len1 = 310,
		.log_len2 = 500,
		.roller_grab_time = 400,
		.blades_grab_time = 300
};


void uw180s_init(uw180s_st *this) {
	implement_init(this, &uw180s);
}



const implement_callbs_st uw50_callbacks = {
		.dasboard_step = dashboard_uw50_step,
		.dashboard_show = dashboard_uw50_show,
		.settings_step = settings_impl_uw50_step,
		.settings_show = settings_impl_uw50_show
};

const uw50_st uw50 = {
		.super = {
				.name = "UW50",
				.callbacks = &uw50_callbacks,
		},
		.saw = {
				.max_speed_p = 600,
				.max_speed_n = 600,
				.invert = false,
				.acc = 10,
				.dec = 10
		},
		.tilt = {
				.max_speed_p = 600,
				.max_speed_n = 600,
				.invert = false,
				.acc = 10,
				.dec = 10
		}
};


const implement_callbs_st uw100_callbacks = {
		.dasboard_step = dashboard_uw100_step,
		.dashboard_show = dashboard_uw100_show,
		.settings_step = settings_impl_uw100_step,
		.settings_show = settings_impl_uw100_show
};

const uw100_st uw100 = {
		.super = {
				.name = "UW100",
				.callbacks = &uw100_callbacks,
		},
		.rotator = {
				.max_speed_p = 300,
				.max_speed_n = 300,
				.invert = false,
				.acc = 100,
				.dec = 100
		},
		.open = {
				.max_speed_p = 600,
				.max_speed_n = 600,
				.invert = false,
				.acc = 100,
				.dec = 100
		}
};





