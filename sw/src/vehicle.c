/*
 * vehicle.c
 *
 *  Created on: Nov 1, 2016
 *      Author: usevolt
 */


#include "vehicle.h"


const valve_st vehicle_valves[BASE_VALVE_COUNT] = {
		{
				.name = "Boom Lift",
				.min_speed_p = 250,
				.max_speed_p = 800,
				.min_speed_n = 230,
				.min_speed_n = 760,
				.acc = 40,
				.dec = 30,
				.invert = false
		},
		{
				.name = "Boom Fold",
				.min_speed_p = 250,
				.max_speed_p = 800,
				.min_speed_n = 250,
				.max_speed_n = 800,
				.acc = 40,
				.dec = 30,
				.invert = false
		},
		{
				.name = "Boom Turn",
				.min_speed_p = 230,
				.max_speed_p = 600,
				.min_speed_n = 230,
				.max_speed_n = 600,
				.acc = 40,
				.dec = 30,
				.invert = false
		},
		{
				.name = "Drive",
				.min_speed_p = 230,
				.max_speed_p = 800,
				.min_speed_n = 230,
				.max_speed_n = 800,
				.acc = 30,
				.dec = 20,
				.invert = false
		},
		{
				.name = "Steer",
				.min_speed_p = 230,
				.max_speed_p = 600,
				.min_speed_n = 230,
				.max_speed_n = 600,
				.acc = 40,
				.dec = 30,
				.invert = false
		},
		{
				.name = "Left Leg",
				.min_speed_p = 230,
				.max_speed_p = 600,
				.min_speed_n = 230,
				.max_speed_n = 600,
				.acc = 40,
				.dec = 30,
				.invert = false
		},
		{
				.name = "Right Leg",
				.min_speed_p = 230,
				.max_speed_p = 600,
				.min_speed_n = 230,
				.max_speed_n = 600,
				.acc = 40,
				.dec = 30,
				.invert = false
		}
};


