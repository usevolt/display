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
#include "uw180s_mb.h"
#include "uw180s_ecu.h"
/// @file: Provides the interface for communicating to the CAN network.



typedef struct {
	bool updating;
	msb_st msb;
	csb_st csb;
	keypad_st r_keypad;
	keypad_st l_keypad;
	ecu_st ecu;
	pedal_st pedal;
	mb_st uw180s_mb;
	uw180s_ecu_st uw180s_ecu;
} network_st;


void network_init(network_st *this);

void network_receive_message(network_st *this, uv_can_message_st *msg);

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
