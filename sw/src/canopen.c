/*
 * dspl_canopen.c
 *
 *  Created on: Mar 15, 2016
 *      Author: usevolt
 */

#include <canopen.h>
#include <uv_canopen.h>


extern dspl_st dspl;

const canopen_object_st obj_dict[] = {
		{
				.main_index = 0x2000,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.msb.read.oil_level
		},
		{
				.main_index = 0x2001,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.msb.read.fuel_level
		},
		{
				.main_index = 0x2002,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED8,
				.data_ptr = (void*) &dspl.network.msb.read.oil_temp
		},
		{
				.main_index = 0x2003,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED8,
				.data_ptr = (void*) &dspl.network.msb.read.motor_temp
		},
		{
				.main_index = 0x2004,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.msb.read.rpm
		},
		{
				.main_index = 0x2005,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.msb.read.voltage
		},
		{
				.main_index = 0x2006,
				.array_max_size = 8,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.msb.read.power
		},
		{
				.main_index = 0x2100,
				.array_max_size = 4,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.csb.read.lights
		},
		{
				.main_index = 0x2101,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.csb.read.wiper
		},
		{
				.main_index = 0x2200,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.read.controls_moved
		},
		{
				.main_index = 0x2201,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.read.engine_shut_down
		},
		{
				.main_index = 0x2202,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.ecu.read.pump_angle
		},
		{
				.main_index = 0x2203,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.read.implement
		},
		{
				.main_index = 0x2204,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.read.stop
		},
		{
				.main_index = 0x2205,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.ecu.read.pressure
		},
		{
				.main_index = 0x2206,
				.array_max_size = ECU_VALVE_COUNT,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_ARRAY16,
				.data_ptr = (void*) &dspl.network.ecu.read.valves
		},
		{
				.main_index = 0x2300,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.l_keypad.read.x
		},
		{
				.main_index = 0x2301,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.l_keypad.read.y
		},
		{
				.main_index = 0x2302,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.l_keypad.read.z
		},
		{
				.main_index = 0x2303,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED16,
				.data_ptr = (void*) &dspl.network.l_keypad.read.buttons
		},
		{
				.main_index = 0x2400,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.r_keypad.read.x
		},
		{
				.main_index = 0x2401,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.r_keypad.read.y
		},
		{
				.main_index = 0x2402,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.r_keypad.read.z
		},
		{
				.main_index = 0x2403,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED16,
				.data_ptr = (void*) &dspl.network.r_keypad.read.buttons
		},
		{
				.main_index = 0x2500,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.pedal.read.value
		}
};




unsigned int object_dictionary_size(void) {
	return sizeof(obj_dict) / sizeof(canopen_object_st);
}


