/*
 * dspl_canopen.c
 *
 *  Created on: Mar 15, 2016
 *      Author: usevolt
 */

#include <canopen.h>
#include <uv_canopen.h>


extern dspl_st dspl;

const uv_canopen_object_st obj_dict[] = {
		{
				.main_index = 0x2000,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.msb.oil_level
		},
		{
				.main_index = 0x2001,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.msb.fuel_level
		},
		{
				.main_index = 0x2002,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED8,
				.data_ptr = (void*) &dspl.network.msb.oil_temp
		},
		{
				.main_index = 0x2003,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED8,
				.data_ptr = (void*) &dspl.network.msb.motor_temp
		},
		{
				.main_index = 0x2004,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.msb.rpm
		},
		{
				.main_index = 0x2005,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.msb.voltage
		},
		{
				.main_index = 0x2006,
				.array_max_size = 8,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.msb.power
		},
		{
				.main_index = 0x2100,
				.array_max_size = 4,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.csb.lights
		},
		{
				.main_index = 0x2101,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.csb.wiper
		},
		{
				.main_index = 0x2200,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.controls_moved
		},
		{
				.main_index = 0x2201,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.engine_shut_down
		},
		{
				.main_index = 0x2202,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.ecu.pump_angle
		},
		{
				.main_index = 0x2203,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.implement
		},
		{
				.main_index = 0x2204,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.stop
		},
		{
				.main_index = 0x2205,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.ecu.pressure
		},
		{
				.main_index = 0x2206,
				.array_max_size = ECU_VALVE_COUNT,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_ARRAY16,
				.data_ptr = (void*) &dspl.network.ecu.valves
		},
		{
				.main_index = 0x2300,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.l_keypad.x
		},
		{
				.main_index = 0x2301,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.l_keypad.y
		},
		{
				.main_index = 0x2302,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.l_keypad.z
		},
		{
				.main_index = 0x2303,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED16,
				.data_ptr = (void*) &dspl.network.l_keypad.buttons
		},
		{
				.main_index = 0x2400,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.r_keypad.x
		},
		{
				.main_index = 0x2401,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.r_keypad.y
		},
		{
				.main_index = 0x2402,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.r_keypad.z
		},
		{
				.main_index = 0x2403,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED16,
				.data_ptr = (void*) &dspl.network.r_keypad.buttons
		},
};




unsigned int object_dictionary_size(void) {
	return sizeof(obj_dict) / sizeof(uv_canopen_object_st);
}


