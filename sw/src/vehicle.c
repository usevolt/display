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
				.min_speed_p = 570,
				.max_speed_p = 1400,
				.min_speed_n = 570,
				.max_speed_n = 1400,
				.acc = 70,
				.dec = 86,
				.invert = false,
				.assembly_invert = true
		},
		{
				.name = STR_SETTINGS_VALVES_TREEBOOMFOLD,
				.setter = hcu_set_boom_fold_params,
				.min_speed_p = 570,
				.max_speed_p = 1400,
				.min_speed_n = 570,
				.max_speed_n = 1400,
				.acc = 70,
				.dec = 80,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEBOOMROTATE,
				.setter = hcu_set_boom_rotate_params,
				.min_speed_p = 570,
				.max_speed_p = 1400,
				.min_speed_n = 570,
				.max_speed_n = 1400,
				.acc = 75,
				.dec = 80,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEBOOMTELESCOPE,
				.setter = hcu_set_boom_telescope_params,
				.min_speed_p = 570,
				.max_speed_p = 1400,
				.min_speed_n = 570,
				.max_speed_n = 1400,
				.acc = 75,
				.dec = 80,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEGEAR1,
				.setter = ccu_set_gear1_params,
				.min_speed_p = 570,
				.max_speed_p = 1500,
				.min_speed_n = 570,
				.max_speed_n = 1500,
				.acc = 70,
				.dec = 85,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEGEAR2,
				.setter = ccu_set_gear2_params,
				.min_speed_p = 570,
				.max_speed_p = 1500,
				.min_speed_n = 570,
				.max_speed_n = 1500,
				.acc = 70,
				.dec = 85,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREEGEAR3,
				.setter = ccu_set_gear3_params,
				.min_speed_p = 570,
				.max_speed_p = 1500,
				.min_speed_n = 570,
				.max_speed_n = 1500,
				.acc = 70,
				.dec = 85,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREESTEER,
				.setter = ccu_set_steer_params,
				.min_speed_p = 570,
				.max_speed_p = 1600,
				.min_speed_n = 570,
				.max_speed_n = 1600,
				.acc = 100,
				.dec = 100,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREETELESCOPE,
				.setter = ccu_set_telescope_params,
				.min_speed_p = 570,
				.max_speed_p = 1400,
				.min_speed_n = 570,
				.max_speed_n = 1400,
				.acc = 80,
				.dec = 80,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREESTEERBACK,
				.setter = ccu_set_telescope_params,
				.min_speed_p = 570,
				.max_speed_p = 1400,
				.min_speed_n = 570,
				.max_speed_n = 1400,
				.acc = 80,
				.dec = 80,
				.invert = false,
				.assembly_invert = false
		},
		{
				.name = STR_SETTINGS_VALVES_TREELEFTLEG,
				.setter = hcu_set_left_leg_params,
				.min_speed_p = 570,
				.max_speed_p = 1300,
				.min_speed_n = 570,
				.max_speed_n = 1300,
				.acc = 70,
				.dec = 100,
				.invert = false,
				.assembly_invert = true
		},
		{
				.name = STR_SETTINGS_VALVES_TREERIGHTLEG,
				.setter = hcu_set_right_leg_params,
				.min_speed_p = 570,
				.max_speed_p = 1300,
				.min_speed_n = 570,
				.max_speed_n = 1300,
				.acc = 70,
				.dec = 100,
				.invert = false,
				.assembly_invert = true
		},
		{
				.name = STR_SETTINGS_VALVES_TREECABROTATE,
				.setter = ccu_set_cab_rot_params,
				.min_speed_p = 570,
				.max_speed_p = 1200,
				.min_speed_n = 570,
				.max_speed_n = 1200,
				.acc = 70,
				.dec = 70,
				.invert = true,
				.assembly_invert = true
		}
};


