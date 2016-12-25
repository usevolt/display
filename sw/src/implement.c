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
#include "dashboard_uw50.h"
#include "settings_impl_generic.h"
#include "settings_impl_uw180s.h"
#include "settings_impl_uw50.h"

#if !GENERIC_IMPLEMENT_COUNT
#error "Generic implement count should be non-zero!"
#endif

#define this 	((implement_st*)me)



void implement_init(void *me, const void *initializer) {
	this->name = ((implement_st*)initializer)->name;
	for (int16_t i = 0; i < IMPLEMENT_VALVE_COUNT; i++) {
		valve_init(&this->valves[i], &((implement_st*)initializer)->valves[i]);
	}
	this->callbacks = ((implement_st*)initializer)->callbacks;
}

const implement_callbs_st generic_callbacks = {
		.dashboard_show = dashboard_generic_show,
		.dasboard_step = dashboard_generic_step,
		.settings_show = settings_impl_generic_show,
		.settings_step = settings_impl_generic_step
};

const generic_implement_st generic_implement = {
			.super = {
					.name = "implement",
					.callbacks = &generic_callbacks,
					.valves = {
							{
									.name = "Main",
									.min_speed_p = 250,
									.max_speed_p = 800,
									.min_speed_n = 230,
									.min_speed_p = 760,
									.acc = 100,
									.dec = 100,
									.invert = false

							},
							{
									.name = "Rotator",
									.min_speed_p = 250,
									.max_speed_p = 800,
									.min_speed_n = 230,
									.min_speed_p = 760,
									.acc = 100,
									.dec = 100,
									.invert = false

							},
							{
									.name = "Tilt",
									.min_speed_p = 250,
									.max_speed_p = 800,
									.min_speed_n = 230,
									.min_speed_p = 760,
									.acc = 100,
									.dec = 100,
									.invert = false

							}
					}
			}
};


const implement_callbs_st uw180s_callbacks = {
		.dasboard_step = dashboard_uw180s_step,
		.dashboard_show = dashboard_uw180s_show,
		.settings_step = settings_impl_uw180s_step,
		.settings_show = settings_impl_uw180s_show
};

const uw180s_st uw180s = {
		.super = {
				.name = "UW180s",
				.callbacks = &uw180s_callbacks,
				.valves = {
						{
								.name = "Main",
								.min_speed_p = 250,
								.max_speed_p = 800,
								.min_speed_n = 230,
								.min_speed_p = 760,
								.acc = 100,
								.dec = 100,
								.invert = false

						},
						{
								.name = "Rotator",
								.min_speed_p = 250,
								.max_speed_p = 800,
								.min_speed_n = 230,
								.min_speed_p = 760,
								.acc = 100,
								.dec = 100,
								.invert = false

						},
						{
								.name = "Tilt",
								.min_speed_p = 250,
								.max_speed_p = 800,
								.min_speed_n = 230,
								.min_speed_p = 760,
								.acc = 100,
								.dec = 100,
								.invert = false

						}
				}
		},
		.delimbers = {
				.max_speed_p = 600,
				.max_speed_n = 600,
				.invert = false
		},
		.rotator = {
				.max_speed_p = 300,
				.max_speed_n = 300,
				.invert = false
		},
		.saw = {
				.max_speed_p = 600,
				.max_speed_n = 600,
				.invert = false
		},
		.tilt = {
				.max_speed_p = 600,
				.max_speed_n = 600,
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
		}
};


const implement_callbs_st uw50_callbacks = {
		.dasboard_step = dashboard_uw50_step,
		.dashboard_show = dashboard_uw50_show,
		.settings_step = settings_impl_uw50_step,
		.settings_show = settings_impl_uw50_show
};

const uw50_st uw50 = {
		.super = {
				.name = "UW40",
				.callbacks = &uw50_callbacks,
				.valves = {
						{
								.name = "Main",
								.min_speed_p = 250,
								.max_speed_p = 800,
								.min_speed_n = 230,
								.min_speed_p = 760,
								.acc = 100,
								.dec = 100,
								.invert = false

						},
						{
								.name = "Rotator",
								.min_speed_p = 250,
								.max_speed_p = 800,
								.min_speed_n = 230,
								.min_speed_p = 760,
								.acc = 100,
								.dec = 100,
								.invert = false

						},
						{
								.name = "Tilt",
								.min_speed_p = 250,
								.max_speed_p = 800,
								.min_speed_n = 230,
								.min_speed_p = 760,
								.acc = 100,
								.dec = 100,
								.invert = false

						}
				}
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



