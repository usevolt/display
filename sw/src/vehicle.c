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
				.name = STR_SETTINGS_VALVES_TREEBOOMLIFT,
				.setter = hcu_set_boom_lift_params,
				.min_speed_p = 110,
				.max_speed_p = 630,
				.min_speed_n = 110,
				.max_speed_n = 630,
				.acc = 40,
				.dec = 46,
				.invert = false,
				.assembly_invert = true
		},
		{
				.name = STR_SETTINGS_VALVES_TREEBOOMFOLD,
				.setter = hcu_set_boom_fold_params,
				.min_speed_p = 100,
				.max_speed_p = 620,
				.min_speed_n = 160,
				.max_speed_n = 620,
				.acc = 40,
				.dec = 40,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEBOOMROTATE,
				.setter = hcu_set_boom_rotate_params,
				.min_speed_p = 130,
				.max_speed_p = 550,
				.min_speed_n = 100,
				.max_speed_n = 550,
				.acc = 25,
				.dec = 30,
				.invert = false,
				.assembly_invert = true
		},
		{
				.name = STR_SETTINGS_VALVES_TREEBOOMTELESCOPE,
				.setter = hcu_set_boom_telescope_params,
				.min_speed_p = 110,
				.max_speed_p = 600,
				.min_speed_n = 110,
				.max_speed_n = 600,
				.acc = 25,
				.dec = 30,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEGEAR1,
				.setter = ccu_set_gear1_params,
				.min_speed_p = 110,
				.max_speed_p = 1200,
				.min_speed_n = 110,
				.max_speed_n = 1200,
				.acc = 30,
				.dec = 25,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEGEAR2,
				.setter = ccu_set_gear2_params,
				.min_speed_p = 110,
				.max_speed_p = 1200,
				.min_speed_n = 110,
				.max_speed_n = 1200,
				.acc = 30,
				.dec = 25,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEGEAR3,
				.setter = ccu_set_gear3_params,
				.min_speed_p = 110,
				.max_speed_p = 1200,
				.min_speed_n = 110,
				.max_speed_n = 1200,
				.acc = 30,
				.dec = 25,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREESTEER,
				.setter = ccu_set_steer_params,
				.min_speed_p = 120,
				.max_speed_p = 700,
				.min_speed_n = 120,
				.max_speed_n = 700,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREETELESCOPE,
				.setter = ccu_set_telescope_params,
				.min_speed_p = 110,
				.max_speed_p = 720,
				.min_speed_n = 110,
				.max_speed_n = 720,
				.acc = 40,
				.dec = 20,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREELEFTLEG,
				.setter = hcu_set_left_leg_params,
				.min_speed_p = 130,
				.max_speed_p = 1200,
				.min_speed_n = 130,
				.max_speed_n = 1200,
				.acc = 40,
				.dec = 100,
				.invert = false,
				.assembly_invert = true
		},
		{
				.name = STR_SETTINGS_VALVES_TREERIGHTLEG,
				.setter = hcu_set_right_leg_params,
				.min_speed_p = 130,
				.max_speed_p = 1200,
				.min_speed_n = 130,
				.max_speed_n = 1200,
				.acc = 40,
				.dec = 100,
				.invert = false,
				.assembly_invert = true
		},
		{
				.name = STR_SETTINGS_VALVES_TREECABROTATE,
				.setter = ccu_set_cab_rot_params,
				.min_speed_p = 110,
				.max_speed_p = 450,
				.min_speed_n = 110,
				.max_speed_n = 450,
				.acc = 20,
				.dec = 30,
				.invert = true,
				.assembly_invert = true
		}
};


