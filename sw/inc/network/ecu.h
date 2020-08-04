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



typedef enum {
	EMCY_ECU_LEGS_DOWN = 0
} ecu_emcy_e;


#if FM
#define ECU_VALVE_COUNT		8
#elif LM
#define ECU_VALVE_COUNT		11
#elif CM
#define ECU_VALVE_COUNT		11
#endif

#define ECU_GEAR_COUNT		3

typedef struct {
	EXTENDS(netdev_st);

	bool legs_down_warning;

	struct {
		uint8_t controls_moved;
		uint8_t engine_shut_down;
		uint16_t pump_angle;
		uint8_t legs_down;
		int16_t pressure;
		uint8_t implement;
		uint8_t gear;
		struct {
#if FM
			int16_t boom_lift_ma;
			int16_t boom_fold_ma;
			int16_t boom_rotate_ma;
			int16_t drive_ma;
			int16_t steer_ma;
			int16_t left_leg_ma;
			int16_t right_leg_ma;
			int16_t impl_valve_ma;
#elif LM
			int16_t boom_lift_ma;
			int16_t boom_fold_ma;
			int16_t boom_rotate_ma;
			int16_t drive_ma;
			int16_t steer_ma;
			int16_t left_leg_ma;
			int16_t right_leg_ma;
			int16_t boom_telescope_ma;
			int16_t steerback_ma;
			int16_t cab_rot_ma;
#elif CM
			int16_t boom_lift_ma;
			int16_t boom_fold_ma;
			int16_t boom_rotate_ma;
			int16_t drive_ma;
			int16_t steer_ma;
			int16_t left_leg_ma;
			int16_t right_leg_ma;
			int16_t boom_telescope_ma;
			int16_t telescope_ma;
			int16_t cab_rot_ma;
#endif
		} valves;
	} read;


} ecu_st;


void ecu_update(void *me);

static inline void ecu_init(ecu_st *this) {
	netdev_init(this, ecu_update);
	netdev_set_node_id(this, ECU_NODE_ID);
	netdev_set_disconnected_type(this, LOG_ECU_DISCONNECTED);
	this->legs_down_warning = false;
	this->read.controls_moved = 0;
	this->read.engine_shut_down = 0;
	this->read.pump_angle = 0;
	this->read.implement = 1;
	this->read.legs_down = 0;
	this->read.pressure = 0;
	this->read.gear = 1;
#if FM
	this->read.valves.boom_lift_ma = 0;
	this->read.valves.boom_fold_ma = 0;
	this->read.valves.boom_rotate_ma = 0;
	this->read.valves.drive_ma = 0;
	this->read.valves.steer_ma = 0;
	this->read.valves.left_leg_ma = 0;
	this->read.valves.right_leg_ma = 0;
	this->read.valves.impl_valve_ma = 0;
#elif LM
	this->read.valves.boom_lift_ma = 0;
	this->read.valves.boom_fold_ma = 0;
	this->read.valves.boom_rotate_ma = 0;
	this->read.valves.boom_telescope_ma = 0;
	this->read.valves.drive_ma = 0;
	this->read.valves.steer_ma = 0;
	this->read.valves.steerback_ma = 0;
	this->read.valves.left_leg_ma = 0;
	this->read.valves.right_leg_ma = 0;
	this->read.valves.cab_rot_ma = 0;
#elif CM
	this->read.valves.boom_lift_ma = 0;
	this->read.valves.boom_fold_ma = 0;
	this->read.valves.boom_rotate_ma = 0;
	this->read.valves.boom_telescope_ma = 0;
	this->read.valves.drive_ma = 0;
	this->read.valves.steer_ma = 0;
	this->read.valves.telescope_ma = 0;
	this->read.valves.left_leg_ma = 0;
	this->read.valves.right_leg_ma = 0;
	this->read.valves.cab_rot_ma = 0;
#endif

}



void ecu_step(ecu_st *this, unsigned int step_ms);

void ecu_emcy(ecu_st *this, const canopen_emcy_msg_st *emcy);


static inline bool ecu_get_controls_moved(ecu_st *this) {
	return this->read.controls_moved;
}

static inline bool ecu_get_engine_shut_down(ecu_st *this) {
	return this->read.engine_shut_down;
}

static inline uint16_t ecu_get_pump_angle(ecu_st *this) {
	return this->read.pump_angle;
}

static inline uint8_t ecu_get_implement(ecu_st *this) {
	return this->read.implement;
}

static inline uint8_t ecu_get_gear(ecu_st *this) {
	return this->read.gear;
}

static inline bool ecu_get_legs_down(ecu_st *this) {
	return this->read.legs_down;
}

static inline int16_t ecu_get_pressure(ecu_st *this) {
	return this->read.pressure;
}

static inline int16_t ecu_get_boom_lift_ma(ecu_st *this) {
	return this->read.valves.boom_lift_ma;
}

static inline int16_t ecu_get_boom_fold_ma(ecu_st *this) {
	return this->read.valves.boom_fold_ma;
}

static inline int16_t ecu_get_boom_rotate_ma(ecu_st *this) {
	return this->read.valves.boom_rotate_ma;
}

static inline int16_t ecu_get_drive_ma(ecu_st *this) {
	return this->read.valves.drive_ma;
}

static inline int16_t ecu_get_steer_ma(ecu_st *this) {
	return this->read.valves.steer_ma;
}

#if FM

static inline int16_t ecu_get_impl_valve_ma(ecu_st *this) {
	return this->read.valves.impl_valve_ma;
}

#elif LM

static inline int16_t ecu_get_boom_telescope_ma(ecu_st *this) {
	return this->read.valves.boom_telescope_ma;
}

static inline int16_t ecu_get_steerback_ma(ecu_st *this) {
	return this->read.valves.steerback_ma;
}

static inline int16_t ecu_get_cab_rot_ma(ecu_st *this) {
	return this->read.valves.cab_rot_ma;
}
#elif CM

static inline int16_t ecu_get_boom_telescope_ma(ecu_st *this) {
	return this->read.valves.boom_telescope_ma;
}

static inline int16_t ecu_get_telescope_ma(ecu_st *this) {
	return this->read.valves.telescope_ma;
}

static inline int16_t ecu_get_cab_rot_ma(ecu_st *this) {
	return this->read.valves.cab_rot_ma;
}

#endif

static inline int16_t ecu_get_left_leg_ma(ecu_st *this) {
	return this->read.valves.left_leg_ma;
}

static inline int16_t ecu_get_right_leg_ma(ecu_st *this) {
	return this->read.valves.right_leg_ma;
}


void ecu_set_boom_lift_params(valve_st *valve);

void ecu_set_boom_fold_params(valve_st *valve);

void ecu_set_boom_rotate_params(valve_st *valve);

void ecu_set_drive_params(valve_st *valve);

void ecu_set_driveback_params(valve_st *valve);

void ecu_set_steer_params(valve_st *valve);

#if FM

#elif LM

void ecu_set_boom_telescope_params(valve_st *valve);

void ecu_set_steerback_params(valve_st *valve);

void ecu_set_cab_rot_params(valve_st *valve);

#elif CM

void ecu_set_boom_telescope_params(valve_st *valve);

void ecu_set_telescope_params(valve_st *valve);

void ecu_set_cab_rot_params(valve_st *valve);

#endif

void ecu_set_left_leg_params(valve_st *valve);

void ecu_set_right_leg_params(valve_st *valve);

void ecu_set_engine_power_usage(uint16_t value);

void ecu_set_implement(uint8_t implement);

void ecu_set_gear(uint8_t gear);


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

void ecu_set_uw180s_rollers_grab_time(uint16_t time_ms);

void ecu_set_uw180s_blades_grab_time(uint16_t time_ms);

void ecu_set_uw180s_rotator_params(uint16_t speed_f,
		uint16_t speed_b, bool invert);

void ecu_set_uw180s_log_length(uint16_t value);

void ecu_set_uw100_rotator_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert);

void ecu_set_uw100_open_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert);


void ecu_set_uw50_saw_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert);

void ecu_set_uw50_tilt_params(uint16_t speed_f,
		uint16_t speed_b, uint16_t acc, uint16_t dec, bool invert);

void ecu_set_drive_comp(int8_t value);

void ecu_save_params();

#undef VALVE_SETTER

#endif /* ECU_H_ */
