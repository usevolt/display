/*
 * dspl_main.h
 *
 *  Created on: Mar 8, 2016
 *      Author: usevolt
 */

#ifndef DSPL_MAIN_H_
#define DSPL_MAIN_H_

#include <uw_gpio.h>
#include <uw_memory.h>
#include <uw_canopen.h>

#define DSPL_CANOPEN_ERROR_COUNT				10
#define DSPL_CANOPEN_HEARTBEAT_TIME				20
#define DSPL_CANOPEN_DEFAULT_NODE_ID			0xF
#define DSPL_CANOPEN_PDO_MAPPING_MAX_COUNT		4
#define DSPL_CANOPEN_TXPDO_COUNT				3
#define DSPL_CANOPEN_RXPDO_COUNT				1


/// @brief: CANopen object dictionary const objects
/// @note: These should be saved in flash memory
typedef struct {
	uint32_t device_type;
} dspl_const_obj_dict_st;



typedef struct {

	uw_data_start_t data_start;

	unsigned int step_cycle_ms;

	// CANopen object dictionary data
	struct {
		const dspl_const_obj_dict_st *consts;
		uint32_t error_array[DSPL_CANOPEN_ERROR_COUNT];
		uint8_t error_register;
		uint8_t error_count;
		uint8_t node_id;
		uint8_t heartbeat_time;
		uint32_t save_req;
		uint32_t restore_req;
		uw_identity_object_st identity_obj;
		uw_rxpdo_com_parameter_st rxpdo_coms[DSPL_CANOPEN_RXPDO_COUNT];
		uw_pdo_mapping_parameter_st rxpdo_mappings[DSPL_CANOPEN_PDO_MAPPING_MAX_COUNT]
												   [DSPL_CANOPEN_RXPDO_COUNT];
		uw_txpdo_com_parameter_st txpdo_coms[DSPL_CANOPEN_TXPDO_COUNT];
		uw_pdo_mapping_parameter_st txpdo_mappings[DSPL_CANOPEN_PDO_MAPPING_MAX_COUNT]
												   [DSPL_CANOPEN_TXPDO_COUNT];
	} obj_dict;


	uw_data_end_t data_endl;
} dspl_st;

void dspl_init(dspl_st *me);
//void dspl_step(void *me, unsigned int step_ms);
void dspl_pin_callback(void *me, uw_gpios_e pin);

void dspl_step(void *me);

#endif /* DSPL_MAIN_H_ */
