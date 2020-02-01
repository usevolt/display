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
#include <uv_filters.h>
#include "esb.h"
#include "csb.h"
#include "fsb.h"
#include "pedal.h"
#include "keypads.h"
#include "hcu.h"
#include "ccu.h"
#include "icu.h"
#include "tcu.h"
/// @file: Provides the interface for communicating to the CAN network.



typedef struct {
	bool updating;
	bool save;
	bool update_disabled;
	esb_st esb;
	csb_st csb;
	fsb_st fsb;
	keypad_st r_keypad;
	keypad_st l_keypad;
	hcu_st hcu;
	ccu_st ccu;
	pedal_st pedal;
	icu_st icu;
	tcu_st tcu;

	/// @brief: moving average filter for can state. 0 = error, non-zero = no errors
	uv_moving_aver_st can_state;
	int can_last_state;
} network_st;


void network_init(network_st *this);

void network_receive_message(network_st *this, uv_can_message_st *msg);

/// @brief: Updates the all modified parameters to the CAN network devices
static inline void network_update(network_st *this) {
	this->updating = true;
}

static inline void network_update_save(network_st *this) {
	this->updating = true;
	this->save = true;
}

/// @brief: Returns true if the SDO parameter update process is
/// on going in the network
static inline bool network_updating(network_st *this) {
	return this->updating;
}


/// @brief: Saves the non-volatile settings to all devices on the network
void network_save_params(network_st *this);











#endif /* NETWORK_H_ */
