/*
 * msb.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef MSB_H_
#define MSB_H_

#include <uv_utilities.h>
#include "netdev.h"


#define MSB_NODE_ID				6
#define MSB_HEATER_SPEED_COUNT	2


/// @file: Defines the communication interface with Main Supply Board
typedef struct {
	EXTENDS(netdev_st);

	uint8_t heater;
	uint8_t fuel_level;
	uint8_t oil_level;
	int8_t oil_temp;
	int8_t motor_temp;

} msb_st;


static inline void msb_init(msb_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, MSB_NODE_ID);
	this->fuel_level = 0;
	this->heater = 0;
	this->motor_temp = 0;
	this->oil_level = 0;
	this->oil_temp = 0;
}


void msb_step(msb_st *this, unsigned int step_ms);

/// @brief: Download the most recent data to the msb
void msb_update(msb_st *this);


static inline uint8_t msb_get_heater(msb_st *msb) {
	return msb->heater;
}

static inline uint8_t msb_get_fuel_level(msb_st *msb) {
	return msb->fuel_level;
}

static inline uint8_t msb_get_oil_level(msb_st *msb) {
	return msb->oil_level;
}

static inline int8_t msb_get_oil_temp(msb_st *msb) {
	return msb->oil_temp;
}

static inline int8_t msb_get_motor_temp(msb_st *msb) {
	return msb->motor_temp;
}


#endif /* MSB_H_ */
