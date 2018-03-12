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
				.main_index = 0x2200,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.read.controls_moved
		},
		{
				.main_index = 0x2201,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.read.engine_shut_down
		},
		{
				.main_index = 0x2202,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.ecu.read.pump_angle
		},
		{
				.main_index = 0x2203,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.read.implement
		},
		{
				.main_index = 0x2204,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.read.legs_down
		},
		{
				.main_index = 0x2205,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.ecu.read.pressure
		},
		{
				.main_index = 0x2206,
				.array_max_size = ECU_VALVE_COUNT,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY16,
				.data_ptr = (void*) &dspl.network.ecu.read.valves
		},
		{
				.main_index = 0x2207,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.ecu.read.gear
		},
		{
				.main_index = 0x2300,
				.array_max_size = 2,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.l_keypad.read.x
		},
		{
				.main_index = 0x2301,
				.array_max_size = 2,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.l_keypad.read.y
		},
		{
				.main_index = 0x2302,
				.array_max_size = 2,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.l_keypad.read.z
		},
		{
				.main_index = 0x2303,
				.array_max_size = 2,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.l_keypad.read.v
		},
		{
				.main_index = 0x2304,
				.array_max_size = KEYPAD_BUTTON_COUNT,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) dspl.network.l_keypad.read.b
		},
		{
				.main_index = 0x2400,
				.array_max_size = 2,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.r_keypad.read.x
		},
		{
				.main_index = 0x2401,
				.array_max_size = 2,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.r_keypad.read.y
		},
		{
				.main_index = 0x2402,
				.array_max_size = 2,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.r_keypad.read.z
		},
		{
				.main_index = 0x2403,
				.array_max_size = 2,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) &dspl.network.r_keypad.read.v
		},
		{
				.main_index = 0x2404,
				.array_max_size = KEYPAD_BUTTON_COUNT,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) dspl.network.r_keypad.read.b
		},
		{
				.main_index = 0x2500,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.pedal.read.value
		},
		{
				.main_index = 0x2600,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.uw180s_mb.read.width
		},
		{
				.main_index = 0x2601,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_SIGNED16,
				.data_ptr = (void*) &dspl.network.uw180s_mb.read.length
		},
		{
				.main_index = 0x2602,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_SIGNED32,
				.data_ptr = (void*) &dspl.network.uw180s_mb.read.volume
		},
		{
				.main_index = 0x2700,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED16,
				.data_ptr = (void*) &dspl.network.esb.read.total_current
		},
		{
				.main_index = 0x2701,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED16,
				.data_ptr = (void*) &dspl.network.esb.read.rpm
		},
		{
				.main_index = 0x2702,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.esb.read.alt_l
		},
		{
				.main_index = 0x2703,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.esb.read.motor_water
		},
		{
				.main_index = 0x2704,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.esb.read.motor_oil_press
		},
		{
				.main_index = 0x2705,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.esb.read.motor_temp
		},
		{
				.main_index = 0x2706,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.esb.read.oil_temp
		},
		{
				.main_index = 0x2707,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.esb.read.oil_level
		},
		{
				.main_index = 0x2708,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.esb.read.fuel_level
		},
		{
				.main_index = 0x2709,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED16,
				.data_ptr = (void*) &dspl.network.esb.read.voltage
		},
		{
				.main_index = 0x2800,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED16,
				.data_ptr = (void*) &dspl.network.fsb.read.total_current
		},
		{
				.main_index = 0x2801,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.fsb.read.ignkey
		},
		{
				.main_index = 0x2802,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.fsb.read.emcy
		},
		{
				.main_index = 0x2803,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.fsb.read.doorsw1
		},
		{
				.main_index = 0x2804,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.fsb.read.doorsw2
		},
		{
				.main_index = 0x2805,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.fsb.read.seatsw
		},
		{
				.main_index = 0x2806,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.fsb.read.heater_speed
		},
		{
				.main_index = 0x2900,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED16,
				.data_ptr = (void*) &dspl.network.csb.read.total_current
		},
		{
				.main_index = 0x2901,
				.sub_index = 0,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = (void*) &dspl.network.csb.read.wiper_speed
		}
};




unsigned int object_dictionary_size(void) {
	return sizeof(obj_dict) / sizeof(canopen_object_st);
}


