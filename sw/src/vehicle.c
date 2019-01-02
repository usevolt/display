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
				.min_speed_p = 600,
				.max_speed_p = 1400,
				.min_speed_n = 600,
				.max_speed_n = 1400,
				.acc = 40,
				.dec = 46,
				.invert = false,
				.assembly_invert = true
		},
		{
				.name = STR_SETTINGS_VALVES_TREEBOOMFOLD,
				.setter = hcu_set_boom_fold_params,
				.min_speed_p = 600,
				.max_speed_p = 1400,
				.min_speed_n = 600,
				.max_speed_n = 1400,
				.acc = 40,
				.dec = 40,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEBOOMROTATE,
				.setter = hcu_set_boom_rotate_params,
				.min_speed_p = 600,
				.max_speed_p = 1400,
				.min_speed_n = 600,
				.max_speed_n = 1400,
				.acc = 25,
				.dec = 30,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEBOOMTELESCOPE,
				.setter = hcu_set_boom_telescope_params,
				.min_speed_p = 600,
				.max_speed_p = 1400,
				.min_speed_n = 600,
				.max_speed_n = 1400,
				.acc = 25,
				.dec = 30,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEGEAR1,
				.setter = ccu_set_gear1_params,
				.min_speed_p = 500,
				.max_speed_p = 1500,
				.min_speed_n = 500,
				.max_speed_n = 1500,
				.acc = 30,
				.dec = 25,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEGEAR2,
				.setter = ccu_set_gear2_params,
				.min_speed_p = 500,
				.max_speed_p = 1500,
				.min_speed_n = 500,
				.max_speed_n = 1500,
				.acc = 30,
				.dec = 25,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEGEAR3,
				.setter = ccu_set_gear3_params,
				.min_speed_p = 500,
				.max_speed_p = 1500,
				.min_speed_n = 500,
				.max_speed_n = 1500,
				.acc = 30,
				.dec = 25,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREESTEER,
				.setter = ccu_set_steer_params,
				.min_speed_p = 600,
				.max_speed_p = 1600,
				.min_speed_n = 600,
				.max_speed_n = 1600,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREETELESCOPE,
				.setter = ccu_set_telescope_params,
				.min_speed_p = 600,
				.max_speed_p = 1400,
				.min_speed_n = 600,
				.max_speed_n = 1400,
				.acc = 60,
				.dec = 50,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREELEFTLEG,
				.setter = hcu_set_left_leg_params,
				.min_speed_p = 600,
				.max_speed_p = 2000,
				.min_speed_n = 600,
				.max_speed_n = 2000,
				.acc = 40,
				.dec = 100,
				.invert = false,
				.assembly_invert = true
		},
		{
				.name = STR_SETTINGS_VALVES_TREERIGHTLEG,
				.setter = hcu_set_right_leg_params,
				.min_speed_p = 600,
				.max_speed_p = 2000,
				.min_speed_n = 600,
				.max_speed_n = 2000,
				.acc = 40,
				.dec = 100,
				.invert = false,
				.assembly_invert = true
		},
		{
				.name = STR_SETTINGS_VALVES_TREECABROTATE,
				.setter = ccu_set_cab_rot_params,
				.min_speed_p = 600,
				.max_speed_p = 1200,
				.min_speed_n = 600,
				.max_speed_n = 1200,
				.acc = 20,
				.dec = 30,
				.invert = true,
				.assembly_invert = true
		}
};


