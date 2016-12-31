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
#include "vehicle.h"



#define ECU_VALVE_COUNT		8



typedef struct {
	EXTENDS(netdev_st);

	uint8_t controls_moved;
	uint8_t engine_shut_down;
	uint16_t pump_angle;
	uint8_t implement;
	uint8_t stop;
	int16_t pressure;

	struct {
		int16_t boom_lift_ma;
		int16_t boom_fold_ma;
		int16_t boom_rotate_ma;
		int16_t drive_ma;
		int16_t steer_ma;
		int16_t left_leg_ma;
		int16_t right_leg_ma;
		int16_t impl_valve_ma;
	} valves;


} ecu_st;



static inline void ecu_init(ecu_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, ECU_NODE_ID);
	this->controls_moved = 0;
	this->engine_shut_down = 0;
	this->pump_angle = 0;
	this->implement = 0;
	this->stop = 0;
	this->pressure = 0;
	this->valves.boom_lift_ma = 0;
	this->valves.boom_fold_ma = 0;
	this->valves.boom_rotate_ma = 0;
	this->valves.drive_ma = 0;
	this->valves.steer_ma = 0;
	this->valves.left_leg_ma = 0;
	this->valves.right_leg_ma = 0;
	this->valves.impl_valve_ma = 0;

}



void ecu_step(ecu_st *this, unsigned int step_ms);

void ecu_update(ecu_st *this);

static inline bool ecu_get_controls_moved(ecu_st *this) {
	return this->controls_moved;
}

static inline bool ecu_get_engine_shut_down(ecu_st *this) {
	return this->engine_shut_down;
}

static inline uint16_t ecu_get_pump_angle(ecu_st *this) {
	return this->pump_angle;
}

static inline uint8_t ecu_get_implement(ecu_st *this) {
	return this->implement;
}

static inline bool ecu_get_stop(ecu_st *this) {
	return this->stop;
}

static inline int16_t ecu_get_pressure(ecu_st *this) {
	return this->pressure;
}

static inline int16_t ecu_get_boom_lift_ma(ecu_st *this) {
	return this->valves.boom_lift_ma;
}

static inline int16_t ecu_get_boom_fold_ma(ecu_st *this) {
	return this->valves.boom_fold_ma;
}

static inline int16_t ecu_get_boom_rotate_ma(ecu_st *this) {
	return this->valves.boom_rotate_ma;
}

static inline int16_t ecu_get_drive_ma(ecu_st *this) {
	return this->valves.drive_ma;
}

static inline int16_t ecu_get_steer_ma(ecu_st *this) {
	return this->valves.steer_ma;
}

static inline int16_t ecu_get_left_leg_ma(ecu_st *this) {
	return this->valves.left_leg_ma;
}

static inline int16_t ecu_get_right_leg_ma(ecu_st *this) {
	return this->valves.right_leg_ma;
}


void ecu_set_boom_lift_params(valve_st *valve);

void ecu_set_boom_fold_params(valve_st *valve);

void ecu_set_boom_rotate_params(valve_st *valve);

void ecu_set_drive_params(valve_st *valve);

void ecu_set_steer_params(valve_st *valve);

void ecu_set_left_leg_params(valve_st *valve);

void ecu_set_right_leg_params(valve_st *valve);

void ecu_set_engine_power_usage(uint16_t value);

void ecu_set_implement(uint8_t implement);


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
