/*
 * vehicle.c
 *
 *  Created on: Nov 1, 2016
 *      Author: usevolt
 */


#include "vehicle.h"
#include "network.h"





#if FM

const valve_st vehicle_valves[BASE_VALVE_COUNT] = {
		{
				.name = "Boom Lift",
				.setter = ecu_set_boom_lift_params,
				.min_speed_p = 230,
				.max_speed_p = 730,
				.min_speed_n = 280,
				.max_speed_n = 715,
				.acc = 40,
				.dec = 46,
				.invert = false
		},
		{
				.name = "Boom Fold",
				.setter = ecu_set_boom_fold_params,
				.min_speed_p = 260,
				.max_speed_p = 720,
				.min_speed_n = 290,
				.max_speed_n = 720,
				.acc = 40,
				.dec = 40,
				.invert = false
		},
		{
				.name = "Boom Turn",
				.setter = ecu_set_boom_rotate_params,
				.min_speed_p = 240,
				.max_speed_p = 570,
				.min_speed_n = 240,
				.max_speed_n = 570,
				.acc = 100,
				.dec = 40,
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
				.min_speed_p = 230,
				.max_speed_p = 700,
				.min_speed_n = 230,
				.max_speed_n = 700,
				.acc = 100,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Left Leg",
				.setter = ecu_set_left_leg_params,
				.min_speed_p = 300,
				.max_speed_p = 850,
				.min_speed_n = 300,
				.max_speed_n = 850,
				.acc = 40,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Right Leg",
				.setter = ecu_set_right_leg_params,
				.min_speed_p = 300,
				.max_speed_p = 850,
				.min_speed_n = 300,
				.max_speed_n = 850,
				.acc = 40,
				.dec = 100,
				.invert = false
		}
};

#elif LM


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
				.name = "Boom Telescope",
				.setter = ecu_set_boom_telescope_params,
				.min_speed_p = 160,
				.max_speed_p = 600,
				.min_speed_n = 273,
				.max_speed_n = 600,
				.acc = 25,
				.dec = 30,
				.invert = false
		},
		{
				.name = "Drive Front",
				.setter = ecu_set_drivefront_params,
				.min_speed_p = 230,
				.max_speed_p = 890,
				.min_speed_n = 230,
				.max_speed_n = 890,
				.acc = 30,
				.dec = 25,
				.invert = false
		},
		{
				.name = "Drive Back",
				.setter = ecu_set_driveback_params,
				.min_speed_p = 230,
				.max_speed_p = 890,
				.min_speed_n = 230,
				.max_speed_n = 890,
				.acc = 30,
				.dec = 25,
				.invert = false
		},
		{
				.name = "Steer Front",
				.setter = ecu_set_steerfront_params,
				.min_speed_p = 300,
				.max_speed_p = 700,
				.min_speed_n = 300,
				.max_speed_n = 700,
				.acc = 100,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Steer Back",
				.setter = ecu_set_steerback_params,
				.min_speed_p = 300,
				.max_speed_p = 700,
				.min_speed_n = 300,
				.max_speed_n = 700,
				.acc = 100,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Left Leg",
				.setter = ecu_set_left_leg_params,
				.min_speed_p = 300,
				.max_speed_p = 850,
				.min_speed_n = 300,
				.max_speed_n = 850,
				.acc = 40,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Right Leg",
				.setter = ecu_set_right_leg_params,
				.min_speed_p = 300,
				.max_speed_p = 850,
				.min_speed_n = 300,
				.max_speed_n = 850,
				.acc = 40,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Cabin Rotate",
				.setter = ecu_set_cab_rot_params,
				.min_speed_p = 300,
				.max_speed_p = 500,
				.min_speed_n = 300,
				.max_speed_n = 500,
				.acc = 30,
				.dec = 30,
				.invert = false
		}
};

#elif CM


const valve_st vehicle_valves[BASE_VALVE_COUNT] = {
		{
				.name = "Boom Lift",
				.setter = ecu_set_boom_lift_params,
				.min_speed_p = 250,
				.max_speed_p = 730,
				.min_speed_n = 270,
				.max_speed_n = 715,
				.acc = 40,
				.dec = 46,
				.invert = false
		},
		{
				.name = "Boom Fold",
				.setter = ecu_set_boom_fold_params,
				.min_speed_p = 230,
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
				.min_speed_p = 220,
				.max_speed_p = 600,
				.min_speed_n = 200,
				.max_speed_n = 600,
				.acc = 25,
				.dec = 30,
				.invert = false
		},
//		{
//				.name = "Boom Telescope",
//				.setter = ecu_set_boom_telescope_params,
//				.min_speed_p = 160,
//				.max_speed_p = 600,
//				.min_speed_n = 273,
//				.max_speed_n = 600,
//				.acc = 25,
//				.dec = 30,
//				.invert = false
//		},
		{
				.name = "Drive Front",
				.setter = ecu_set_drivefront_params,
				.min_speed_p = 140,
				.max_speed_p = 1000,
				.min_speed_n = 140,
				.max_speed_n = 1000,
				.acc = 60,
				.dec = 20,
				.invert = false
		},
		{
				.name = "Drive Back",
				.setter = ecu_set_driveback_params,
				.min_speed_p = 140,
				.max_speed_p = 1000,
				.min_speed_n = 140,
				.max_speed_n = 1000,
				.acc = 60,
				.dec = 20,
				.invert = false
		},
		{
				.name = "Steer",
				.setter = ecu_set_steer_params,
				.min_speed_p = 300,
				.max_speed_p = 700,
				.min_speed_n = 300,
				.max_speed_n = 700,
				.acc = 100,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Telescope",
				.setter = ecu_set_telescope_params,
				.min_speed_p = 300,
				.max_speed_p = 700,
				.min_speed_n = 300,
				.max_speed_n = 700,
				.acc = 100,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Left Leg",
				.setter = ecu_set_left_leg_params,
				.min_speed_p = 300,
				.max_speed_p = 1000,
				.min_speed_n = 300,
				.max_speed_n = 1000,
				.acc = 40,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Right Leg",
				.setter = ecu_set_right_leg_params,
				.min_speed_p = 300,
				.max_speed_p = 1000,
				.min_speed_n = 300,
				.max_speed_n = 1000,
				.acc = 40,
				.dec = 100,
				.invert = false
		},
		{
				.name = "Cabin Rotate",
				.setter = ecu_set_cab_rot_params,
				.min_speed_p = 190,
				.max_speed_p = 500,
				.min_speed_n = 190,
				.max_speed_n = 500,
				.acc = 30,
				.dec = 20,
				.invert = false
		}
};

#endif


