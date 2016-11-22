/*
 * implement.c
 *
 *  Created on: Nov 3, 2016
 *      Author: usevolt
 */


#include "implement.h"
#include "main.h"

#if !GENERIC_IMPLEMENT_COUNT
#error "Generic implement count should be non-zero!"
#endif


const generic_implement_st generic_implement = {
			.super = {
					.name = "implement",
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


const uw180s_st uw180s = {
		.super = {
				.name = "UW180s",
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


const uw40_st uw40 = {
		.super = {
				.name = "UW40",
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



