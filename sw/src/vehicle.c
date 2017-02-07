/*
 * vehicle.c
 *
 *  Created on: Nov 1, 2016
 *      Author: usevolt
 */


#include "vehicle.h"
#include "network.h"






const valve_st vehicle_valves[BASE_VALVE_COUNT] = {
		{
				.name = "Boom Lift",
				.setter = ecu_set_boom_lift_params,
				.min_speed_p = 285,
				.max_speed_p = 730,
				.min_speed_n = 200,
				.max_speed_n = 715,
				.acc = 40,
				.dec = 46,
				.invert = false
		},
		{
				.name = "Boom Fold",
				.setter = ecu_set_boom_fold_params,
				.min_speed_p = 300,
				.max_speed_p = 720,
				.min_speed_n = 257,
				.max_speed_n = 720,
				.acc = 40,
				.dec = 40,
				.invert = false
		},
		{
				.name = "Boom Turn",
				.setter = ecu_set_boom_rotate_params,
				.min_speed_p = 160,
				.max_speed_p = 600,
				.min_speed_n = 273,
				.max_speed_n = 600,
				.acc = 25,
				.dec = 30,
				.invert = false
		},
		{
				.name = "Drive",
				.setter = ecu_set_drive_params,
				.min_speed_p = 230,
				.max_speed_p = 890,
				.min_speed_n = 230,
				.max_speed_n = 890,
				.acc = 30,
				.dec = 25,
				.invert = false
		},
		{
				.name = "Steer",
				.setter = ecu_set_steer_params,
				.min_speed_p = 300,
				.max_speed_p = 500,
				.min_speed_n = 300,
				.max_speed_n = 500,
				.acc = 100,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Left Leg",
				.setter = ecu_set_left_leg_params,
				.min_speed_p = 300,
				.max_speed_p = 700,
				.min_speed_n = 300,
				.max_speed_n = 700,
				.acc = 40,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Right Leg",
				.setter = ecu_set_right_leg_params,
				.min_speed_p = 300,
				.max_speed_p = 700,
				.min_speed_n = 300,
				.max_speed_n = 700,
				.acc = 40,
				.dec = 100,
				.invert = false
		}
};




