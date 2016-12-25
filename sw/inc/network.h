/*
 * network.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef NETWORK_H_
#define NETWORK_H_

#include <uv_utilities.h>
#include <uv_rtos.h>
#include "msb.h"
#include "csb.h"
#include "pedal.h"
#include "keypads.h"
#include "ecu.h"
/// @file: Provides the interface for communicating to the CAN network.



typedef struct {
	bool updating;
	msb_st msb;
	csb_st csb;
	keypad_st r_keypad;
	keypad_st l_keypad;
	ecu_st ecu;
	pedal_st pedal;
} network_st;


void network_init(network_st *this);



/// @brief: Updates the all modified parameters to the CAN network devices
static inline void network_update(network_st *this) {
	this->updating = true;
}

/// @brief: Returns true if the SDO parameter update process is
/// on going in the network
static inline bool network_updating(network_st *this) {
	return this->updating;
}

#endif /* NETWORK_H_ */
