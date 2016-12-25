/*
 * ecu.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef ECU_H_
#define ECU_H_

#include <uv_utilities.h>
#include <uv_canopen.h>
#include <stdbool.h>
#include "netdev.h"
#include "valve.h"


#define ECU_NODE_ID			0x10





typedef struct {
	EXTENDS(netdev_st);

} ecu_st;



static inline void ecu_init(ecu_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, ECU_NODE_ID);
}



void ecu_step(ecu_st *this, unsigned int step_ms);

void ecu_update(ecu_st *this);


void ecu_set_boom_lift_params(valve_st *valve);

void ecu_set_boom_fold_params(valve_st *valve);

void ecu_set_boom_rotate_params(valve_st *valve);

void ecu_set_drive_params(valve_st *valve);

void ecu_set_steer_params(valve_st *valve);

void ecu_set_left_leg_params(valve_st *valve);

void ecu_set_right_leg_params(valve_st *valve);


void ecu_set_uw180s_wheels_feed_params(uint16_t speed_f,
		uint16_t speed_b, bool invert);

void ecu_set_uw180s_delimbers_params(uint16_t speed_f,
		uint16_t speed_b, bool invert);

void ecu_set_uw180s_wheels_params(uint16_t speed_f,
		uint16_t speed_b, bool invert);

void ecu_set_uw180s_saw_params(uint16_t speed_f,
		uint16_t speed_b, bool invert);

void ecu_set_uw180s_tilt_params(uint16_t speed_f,
		uint16_t speed_b, bool invert);

void ecu_set_uw180s_rotator_params(uint16_t speed_f,
		uint16_t speed_b, bool invert);


void ecu_set_uw50_saw_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert);

void ecu_set_uw50_tilt_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert);

#undef VALVE_SETTER

#endif /* ECU_H_ */
