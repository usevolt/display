/*
 * ecu.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "ecu.h"
#include "main.h"






void ecu_step(ecu_st *this, unsigned int step_ms) {

}



void ecu_update(ecu_st *this) {
	for (int16_t i = 0; i < BASE_VALVE_COUNT; i++) {
		dspl.user->base_valves[i].setter(&dspl.user->base_valves[i]);
	}
}




void ecu_set_boom_lift_params(valve_st *valve) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2000, 1, valve->max_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2000, 2, valve->min_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2000, 3, valve->max_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2000, 4, valve->min_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2000, 5, valve->acc);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2000, 6, valve->dec);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2000, 7, valve->invert);
}

void ecu_set_boom_fold_params(valve_st *valve) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2001, 1, valve->max_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2001, 2, valve->min_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2001, 3, valve->max_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2001, 4, valve->min_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2001, 5, valve->acc);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2001, 6, valve->dec);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2001, 7, valve->invert);
}

void ecu_set_boom_rotate_params(valve_st *valve) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2002, 1, valve->max_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2002, 2, valve->min_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2002, 3, valve->max_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2002, 4, valve->min_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2002, 5, valve->acc);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2002, 6, valve->dec);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2002, 7, valve->invert);
}

void ecu_set_drive_params(valve_st *valve) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2003, 1, valve->max_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2003, 2, valve->min_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2003, 3, valve->max_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2003, 4, valve->min_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2003, 5, valve->acc);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2003, 6, valve->dec);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2003, 7, valve->invert);
}

void ecu_set_steer_params(valve_st *valve) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2004, 1, valve->max_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2004, 2, valve->min_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2004, 3, valve->max_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2004, 4, valve->min_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2004, 5, valve->acc);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2004, 6, valve->dec);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2004, 7, valve->invert);
}

void ecu_set_left_leg_params(valve_st *valve) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2005, 1, valve->max_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2005, 2, valve->min_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2005, 3, valve->max_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2005, 4, valve->min_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2005, 5, valve->acc);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2005, 6, valve->dec);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2005, 7, valve->invert);
}

void ecu_set_right_leg_params(valve_st *valve) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2006, 1, valve->max_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2006, 2, valve->min_speed_p);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2006, 3, valve->max_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2006, 4, valve->min_speed_n);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2006, 5, valve->acc);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2006, 6, valve->dec);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2006, 7, valve->invert);
}

void ecu_set_uw180s_wheels_feed_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2100, 1, speed_f);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2100, 2, speed_b);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE, ECU_NODE_ID, 0x2100, 3, invert);
}

void ecu_set_uw180s_delimbers_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2101, 1, speed_f);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2101, 2, speed_b);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE, ECU_NODE_ID, 0x2101, 3, invert);
}

void ecu_set_uw180s_wheels_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2102, 1, speed_f);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2102, 2, speed_b);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE, ECU_NODE_ID, 0x2102, 3, invert);
}

void ecu_set_uw180s_saw_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2103, 1, speed_f);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2103, 2, speed_b);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE, ECU_NODE_ID, 0x2103, 3, invert);
}

void ecu_set_uw180s_tilt_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2104, 1, speed_f);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2104, 2, speed_b);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE, ECU_NODE_ID, 0x2104, 3, invert);
}

void ecu_set_uw180s_rotator_params(uint16_t speed_f,
		uint16_t speed_b, bool invert) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2105, 1, speed_f);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2105, 2, speed_b);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE, ECU_NODE_ID, 0x2105, 3, invert);
}

void ecu_set_uw50_saw_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2200, 1, speed_f);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2200, 2, speed_b);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2200, 3, acc);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2200, 4, dec);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE, ECU_NODE_ID, 0x2200, 3, invert);
}

void ecu_set_uw50_tilt_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert) {
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2201, 1, speed_f);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2201, 2, speed_b);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2201, 3, acc);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_2_BYTES, ECU_NODE_ID, 0x2201, 4, dec);
	uv_canopen_sdo_write(&dspl.canopen, CANOPEN_SDO_CMD_WRITE_1_BYTE, ECU_NODE_ID, 0x2201, 3, invert);
}
