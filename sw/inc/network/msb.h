/*
 * msb.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef MSB_H_
#define MSB_H_

#include <uv_utilities.h>
#include "vehicle.h"
#include "netdev.h"


#define MSB_HEATER_SPEED_COUNT	2


/// @file: Defines the communication interface with Main Supply Board
typedef struct {
	EXTENDS(netdev_st);

	// READ
	struct {
		uint8_t fuel_level;
		uint8_t oil_level;
		int8_t oil_temp;
		int8_t motor_temp;
		int16_t rpm;
		int16_t voltage;
		uint8_t heater;
		uint8_t alt;
		struct {
			uint8_t glow_plugs;
			uint8_t starter;
			uint8_t engine_water;
			uint8_t crane_light;
			uint8_t engine_oil_press;
			uint8_t aux;
			uint8_t emcy_stop;
		} power;
	} read;
	uint8_t horn;
} msb_st;


/// @brief: Download the most recent data to the msb
void msb_update(void *me);

static inline void msb_init(msb_st *this) {
	netdev_init(this, msb_update);
	netdev_set_node_id(this, MSB_NODE_ID);
	netdev_set_disconnected_type(this, LOG_MSB_DISCONNECTED);
	this->read.fuel_level = 0;
	this->read.motor_temp = 0;
	this->read.oil_level = 0;
	this->read.oil_temp = 0;
	this->read.rpm = 0;
	this->read.voltage = 0;
	this->read.heater = 0;
	this->read.alt = 0;
	this->read.power.aux = 0;
	this->read.power.crane_light = 0;
	this->read.power.glow_plugs = 0;
	this->read.power.starter = 0;
	this->read.power.engine_water = 0;
	this->read.power.engine_oil_press = 0;
	this->read.power.emcy_stop = 0;
}


void msb_step(msb_st *this, unsigned int step_ms);


static inline uint8_t msb_get_fuel_level(msb_st *msb) {
	return msb->read.fuel_level;
}

static inline uint8_t msb_get_oil_level(msb_st *msb) {
	return msb->read.oil_level;
}

static inline int8_t msb_get_oil_temp(msb_st *msb) {
	return msb->read.oil_temp;
}

static inline int8_t msb_get_motor_temp(msb_st *msb) {
	return msb->read.motor_temp;
}

static inline int16_t msb_get_rpm(msb_st *msb) {
	return msb->read.rpm;
}

static inline int16_t msb_get_voltage(msb_st *msb) {
	return msb->read.voltage;
}

static inline uint8_t msb_get_emcy_stop(msb_st *msb) {
	return msb->read.power.emcy_stop;
}

static inline uint8_t msb_get_alt(msb_st *msb) {
	return msb->read.alt;
}

static inline bool msb_get_power_aux(msb_st *msb) {
	return msb->read.power.aux;
}

static inline bool msb_get_power_crane_light(msb_st *msb) {
	return msb->read.power.crane_light;
}

static inline bool msb_get_power_glow_plugs(msb_st *msb) {
	return msb->read.power.glow_plugs;
}

static inline bool msb_get_power_engine_water(msb_st *msb) {
	return msb->read.power.engine_water;
}

static inline bool msb_get_power_engine_oil_press(msb_st *msb) {
	return msb->read.power.engine_oil_press;
}

static inline bool msb_get_power_starter(msb_st *msb) {
	return msb->read.power.starter;
}

static inline uint8_t msb_get_heater(msb_st *msb) {
	return msb->read.heater;
}


void msb_set_heater(void *me, uint8_t value);

void msb_set_crane_light(void *me, bool value);

void msb_set_horn(void *me, bool value);


#endif /* MSB_H_ */
