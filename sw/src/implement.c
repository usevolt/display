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
#include "settings_impl_hydout.h"

#define this 	((implement_st*)me)



void implement_set(hcu_impls_e implement) {
	if (implement < HCU_IMPLEMENT_COUNT) {
		hcu_set_implement(implement);
		// update network since valve settings might have changed
		network_update(&dspl.network);
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
				.max_speed_p = 50,
				.max_speed_n = 50,
				.min_speed_p = 0,
				.min_speed_n = 0,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.rotator = {
				.name = STR_SETTINGS_UW180S_BUTTONROTATOR,
				.setter = &hcu_set_rotator_params,
				.max_speed_p = 900,
				.max_speed_n = 900,
				.min_speed_p = 300,
				.min_speed_n = 300,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.saw = {
				.name = STR_SETTINGS_UW180S_BUTTONSAW,
				.setter = &icu_set_saw_params,
				.max_speed_p = 20,
				.max_speed_n = 70,
				.min_speed_p = 0,
				.min_speed_n = 0,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.tilt = {
				.name = STR_SETTINGS_UW180S_BUTTONTILT,
				.setter = &icu_set_tilt_params,
				.max_speed_p = 20,
				.max_speed_n = 20,
				.min_speed_p = 0,
				.min_speed_n = 0,
				.acc = 100,
				.dec = 100,
				.invert = true,
				.assembly_invert = false
		},
		.feedopen = {
				.name = STR_SETTINGS_UW180S_BUTTONFEEDOPEN,
				.setter = &icu_set_feedopen_params,
				.max_speed_p = 80,
				.max_speed_n = 80,
				.min_speed_p = 0,
				.min_speed_n = 0,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.feed = {
				.name = STR_SETTINGS_UW180S_BUTTONFEED,
				.setter = &icu_set_feed_params,
				.max_speed_p = 100,
				.max_speed_n = 100,
				.min_speed_p = 0,
				.min_speed_n = 0,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.all_open = {
				.name = STR_SETTINGS_UW180S_BUTTONALLOPEN,
				.setter = &icu_set_allopen_params,
				.max_speed_p = 100,
				.max_speed_n = 100,
				.min_speed_p = 0,
				.min_speed_n = 0,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.impl1 = {
				.name = STR_SETTINGS_UW180S_BUTTONIMPL1,
				.setter = &hcu_set_impl1_params,
				.max_speed_p = 2000,
				.max_speed_n = 2000,
				.min_speed_p = 300,
				.min_speed_n = 300,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		.impl2 = {
				.name = STR_SETTINGS_UW180S_BUTTONIMPL2,
				.setter = &hcu_set_impl2_params,
				.max_speed_p = 2000,
				.max_speed_n = 2000,
				.min_speed_p = 300,
				.min_speed_n = 300,
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
		.blades_grab_time = 60,
		.tiltfloat_enable = 1,
		.tilt_onthumb = 0,
		.max_width_mm = 250,
		.min_width_mm = 40
};


void uw180s_init(uw180s_st *this) {
	implement_init(this, &uw180s);
	valve_init(&this->all_open, &uw180s.all_open);
	valve_init(&this->bladesopen, &uw180s.bladesopen);
	valve_init(&this->feed, &uw180s.feed);
	valve_init(&this->feedopen, &uw180s.feedopen);
	valve_init(&this->impl1, &uw180s.impl1);
	valve_init(&this->impl2, &uw180s.impl2);
	valve_init(&this->rotator, &uw180s.rotator);
	valve_init(&this->saw, &uw180s.saw);
	valve_init(&this->tilt, &uw180s.tilt);
}



void uw50_init(uw50_st *this) {
	implement_init(this, &uw50);
	valve_init(&this->saw, &uw50.saw);
	valve_init(&this->tilt, &uw50.tilt);
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
				.name = STR_SETTINGS_UW180S_BUTTONSAW,
				.setter = &hcu_set_impl2_params,
				.max_speed_p = 1200,
				.min_speed_p = 300,
				.max_speed_n = 1200,
				.min_speed_n = 300,
				.invert = false,
				.assembly_invert = false,
				.acc = 10,
				.dec = 10
		},
		.tilt = {
				.name = STR_SETTINGS_UW180S_BUTTONTILT,
				.setter = &hcu_set_rotator_params,
				.max_speed_p = 1200,
				.min_speed_p = 300,
				.max_speed_n = 1200,
				.min_speed_n = 300,
				.invert = false,
				.assembly_invert = false,
				.acc = 10,
				.dec = 10
		}
};


void uw100_init(uw100_st *this) {
	implement_init(this, &uw100);
	valve_init(&this->open, &uw100.open);
	valve_init(&this->rotator, &uw100.rotator);
}


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
				.name = STR_SETTINGS_UW100_BUTTONROTATOR,
				.setter = &hcu_set_rotator_params,
				.max_speed_p = 900,
				.min_speed_p = 300,
				.max_speed_n = 900,
				.min_speed_n = 300,
				.invert = false,
				.assembly_invert = false,
				.acc = 100,
				.dec = 100
		},
		.open = {
				.name = STR_SETTINGS_UW100_BUTTONOPENCLOSE,
				.setter = &hcu_set_impl1_params,
				.max_speed_p = 1200,
				.min_speed_p = 300,
				.max_speed_n = 1200,
				.min_speed_n = 300,
				.invert = false,
				.assembly_invert = false,
				.acc = 100,
				.dec = 100
		},
		.impl2 = {
				.name = STR_SETTINGS_UW180S_BUTTONIMPL2,
				.setter = &hcu_set_impl2_params,
				.max_speed_p = 1200,
				.min_speed_p = 300,
				.max_speed_n = 1200,
				.min_speed_n = 300,
				.invert = false,
				.assembly_invert = false,
				.acc = 100,
				.dec = 100
		}
};



void hydout_init(hydout_st *this) {
	implement_init(this, &hydout);
	valve_init(&this->impl2, &hydout.impl2);
}


const implement_callbs_st hydout_callbacks = {
		.dasboard_step = dashboard_uw100_step,
		.dashboard_show = dashboard_uw100_show,
		.settings_step = settings_impl_hydout_step,
		.settings_show = settings_impl_hydout_show
};

const hydout_st hydout = {
		.super = {
				.name = "Hydraulic out",
				.callbacks = &hydout_callbacks,
		},
		.impl2 = {
				.name = STR_SETTINGS_UW180S_BUTTONIMPL2,
				.setter = &hcu_set_impl2_params,
				.max_speed_p = 2000,
				.min_speed_p = 300,
				.max_speed_n = 2000,
				.min_speed_n = 300,
				.invert = false,
				.assembly_invert = false,
				.acc = 100,
				.dec = 100
		}
};





