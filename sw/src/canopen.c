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
				.main_index = 0x2010,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.msb.fuel_level
		},
		{
				.main_index = 0x2011,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.msb.oil_level
		},
		{
				.main_index = 0x2012,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED8,
				.data_ptr = (void*) &dspl.network.msb.oil_temp
		},
		{
				.main_index = 0x2013,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_SIGNED8,
				.data_ptr = (void*) &dspl.network.msb.motor_temp
		},
		{
				.main_index = 0x2014,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.msb.heater
		},
		{
				.main_index = 0x2020,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.csb.drive_light
		},
		{
				.main_index = 0x2021,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.csb.work_light
		},
		{
				.main_index = 0x2022,
				.sub_index = 0,
				.permissions = CANOPEN_RO,
				.type = CANOPEN_UNSIGNED8,
				.data_ptr = &dspl.network.csb.wiper
		}
};




unsigned int object_dictionary_size(void) {
	return sizeof(obj_dict) / sizeof(uv_canopen_object_st);
}


