/*
 * dspl_canopen.c
 *
 *  Created on: Mar 15, 2016
 *      Author: usevolt
 */

#include "dspl_canopen.h"
#include <uw_canopen.h>


extern dspl_const_obj_dict_st dspl_const_obj_dict;
extern dspl_st dspl;

const uw_canopen_object_st obj_dict[] = {
		{
				// Device type
				.main_index = 0x1000,
				.sub_index = 0,
				.permissions = UW_RO,
				.type = UW_UNSIGNED32,
				.data_ptr = (uint8_t*) &dspl_const_obj_dict.device_type
		},
		{
				// Error register
				.main_index = 0x1001,
				.sub_index = 0,
				.permissions = UW_RO,
				.type = UW_UNSIGNED8,
				.data_ptr = (uint8_t*) &dspl.obj_dict.error_register
		},
		{
				// Predefined error
				.main_index = 0x1001,
				.permissions = UW_RW,
				.type = UW_ARRAY32,
				.array_max_size = DSPL_CANOPEN_ERROR_COUNT,
				.data_ptr = (uint8_t*) &dspl.obj_dict.error_array
		},
		{
				// Node-ID
				.main_index = 0x100B,
				.sub_index = 0,
				.permissions = UW_RW,
				.type = UW_UNSIGNED8,
				.data_ptr = (uint8_t*) &dspl.obj_dict.node_id
		},
		{
				// Save parameters
				.main_index = 0x1010,
				.permissions = UW_RW,
				.type = UW_ARRAY32,
				.array_max_size = 1,
				.data_ptr = (uint8_t*) &dspl.obj_dict.save_req
		},
		{
				// Restore parameters
				.main_index = 0x1011,
				.permissions = UW_RW,
				.type = UW_ARRAY32,
				.array_max_size = 1,
				.data_ptr = (uint8_t*) &dspl.obj_dict.restore_req
		},
		{
				// producer heartbeat time
				.main_index = 0x1017,
				.permissions = UW_RW,
				.type = UW_UNSIGNED32,
				.array_max_size = 1,
				.data_ptr = (uint8_t*) &dspl.obj_dict.heartbeat_time
		},
		{
				// identity object
				.main_index = 0x1018,
				.permissions = UW_RO,
				.type = UW_ARRAY32,
				.array_max_size = 4,
				.data_ptr = (uint8_t*) &dspl.obj_dict.identity_obj
		},
		{
				// RXPDO1 communication parameter
				.main_index = 0x1400,
				.permissions = UW_RW,
				.type = UW_PDO_COM_ARRAY,
				.array_max_size = UW_RXPDO_COM_ARRAY_SIZE,
				.data_ptr = (uint8_t*) &dspl.obj_dict.rxpdo_coms[0]
		},
		{
				// RXPDO1 mapping parameter
				.main_index = 0x1600,
				.permissions = UW_RW,
				.type = UW_PDO_MAP_ARRAY,
				.array_max_size = DSPL_CANOPEN_PDO_MAPPING_MAX_COUNT,
				.data_ptr = (uint8_t*) &dspl.obj_dict.rxpdo_mappings[0]
		},
		{
				// TXPDO1 communication parameter
				.main_index = 0x1800,
				.permissions = UW_RW,
				.type = UW_PDO_COM_ARRAY,
				.array_max_size = UW_TXPDO_COM_ARRAY_SIZE,
				.data_ptr = (uint8_t*) &dspl.obj_dict.txpdo_coms[0]
		},
		{
				// TXPDO1 mapping parameter
				.main_index = 0x1A00,
				.permissions = UW_RW,
				.type = UW_PDO_MAP_ARRAY,
				.array_max_size = DSPL_CANOPEN_PDO_MAPPING_MAX_COUNT,
				.data_ptr = (uint8_t*) &dspl.obj_dict.txpdo_mappings[0]
		},
		{
				// TXPDO2 communication parameter
				.main_index = 0x1801,
				.permissions = UW_RW,
				.type = UW_PDO_COM_ARRAY,
				.array_max_size = UW_TXPDO_COM_ARRAY_SIZE,
				.data_ptr = (uint8_t*) &dspl.obj_dict.txpdo_coms[1]
		},
		{
				// TXPDO2 mapping parameter
				.main_index = 0x1A01,
				.permissions = UW_RW,
				.type = UW_PDO_MAP_ARRAY,
				.array_max_size = DSPL_CANOPEN_PDO_MAPPING_MAX_COUNT,
				.data_ptr = (uint8_t*) &dspl.obj_dict.txpdo_mappings[1]
		},
		{
				// TXPDO3 communication parameter
				.main_index = 0x1802,
				.permissions = UW_RW,
				.type = UW_PDO_COM_ARRAY,
				.array_max_size = UW_TXPDO_COM_ARRAY_SIZE,
				.data_ptr = (uint8_t*) &dspl.obj_dict.txpdo_coms[2]
		},
		{
				// TXPDO3 mapping parameter
				.main_index = 0x1A02,
				.permissions = UW_RW,
				.type = UW_PDO_MAP_ARRAY,
				.array_max_size = DSPL_CANOPEN_PDO_MAPPING_MAX_COUNT,
				.data_ptr = (uint8_t*) &dspl.obj_dict.txpdo_mappings[2]
		}
};




unsigned int dspl_object_dictionary_size(void) {
	return sizeof(obj_dict) / sizeof(uw_canopen_object_st);
}


