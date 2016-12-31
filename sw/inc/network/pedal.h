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

	int16_t value;
} pedal_st;


static inline void pedal_init(pedal_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, PEDAL_NODE_ID);
	this->value = 0;
}

static inline int16_t pedal_get_value(pedal_st *this) {
	return this->value;
}

void pedal_step(pedal_st *this, unsigned int step_ms);


void pedal_update(pedal_st *this);


#endif /* PEDAL_H_ */
