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



void implement_set(impl_type_e implement) {
	if (implement < IMPL_COUNT) {
		dspl.user->active_implement = implement;

		if (implement == IMPL_UW180S) {
			dspl.user->implement = (void*) &dspl.user->uw180s;
		}
		else if (implement == IMPL_UW100) {
			dspl.user->implement = (void*) &dspl.user->uw100;
		}
		else if (implement == IMPL_UW50) {
			dspl.user->implement = (void*) &dspl.user->uw50;
		}
		ecu_set_implement(implement);
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
		.delimbers = {
				.max_speed_p = 500,
				.max_speed_n = 500,
				.invert = false
		},
		.rotator = {
				.max_speed_p = 500,
				.max_speed_n = 500,
				.invert = false
		},
		.saw = {
				.max_speed_p = 600,
				.max_speed_n = 350,
				.invert = false
		},
		.tilt = {
				.max_speed_p = 350,
				.max_speed_n = 350,
				.invert = false
		},
		.wheels = {
				.max_speed_p = 600,
				.max_speed_n = 600,
				.invert = false
		},
		.wheels_feed = {
				.max_speed_p = 850,
				.max_speed_n = 850,
				.invert = false
		},
		.mb_enabled = true,
		.len_calib = 66,
		.vol_calib = 0,
		.log_len1 = 310,
		.log_len2 = 500,
		.roller_grab_time = 400,
		.blades_grab_time = 300
};


void uw180s_init(uw180s_st *this) {
	implement_init(this, &uw180s);
	ecu_set_uw180s_log_length(this->log_len1);
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





