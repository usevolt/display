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




typedef struct {
	EXTENDS(netdev_st);

	struct {
		int16_t value;
	} read;
} pedal_st;

void pedal_update(void *this);

static inline void pedal_init(pedal_st *this) {
	netdev_init(this, pedal_update);
	netdev_set_node_id(this, PEDAL_NODE_ID);
	this->read.value = 0;
}

static inline int16_t pedal_get_value(pedal_st *this) {
	return this->read.value;
}

void pedal_step(pedal_st *this, unsigned int step_ms);




#endif /* PEDAL_H_ */
