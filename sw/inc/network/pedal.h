/*
 * pedal.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef PEDAL_H_
#define PEDAL_H_



#include <uv_utilities.h>
#include "netdev.h"
#include "vehicle.h"
#include "can_pedal.h"



typedef struct {
	EXTENDS(netdev_st);

	int16_t value[2];
} pedal_st;

void pedal_update(void *this);

static inline void pedal_init(pedal_st *this) {
	netdev_init(this, pedal_update);
	netdev_set_node_id(this, PEDAL_NODE_ID);
	netdev_set_disconnected_type(this, LOG_PEDAL_DISCONNECTED);
	this->value[0] = 0;
	this->value[1] = 0;
}

static inline int16_t pedal_get_value1(pedal_st *this) {
	return this->value[0];
}

static inline int16_t pedal_get_value2(pedal_st *this) {
	return this->value[1];
}

void pedal_step(pedal_st *this, unsigned int step_ms);




#endif /* PEDAL_H_ */
