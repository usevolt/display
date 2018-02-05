/*
 * fsb.h
 *
 *  Created on: Oct 25, 2017
 *      Author: usevolt
 */

#ifndef NETWORK_FSB_H_
#define NETWORK_FSB_H_



#include <uv_utilities.h>
#include "netdev.h"
#include "vehicle.h"
#include "can_fsb.h"
#include <uv_output.h>


typedef struct {
	EXTENDS(netdev_st);

	// READ
	struct {
		uint16_t total_current;
		fsb_ignkey_states_e ignkey;
		uint8_t emcy;
		uint8_t doorsw1;
		uint8_t doorsw2;
		uint8_t seatsw;
	} read;
} fsb_st;



/// @brief: Download the most recent data to the msb
void fsb_update(void *me);


void fsb_init(fsb_st *this);


void fsb_step(fsb_st *this, unsigned int step_ms);


static inline uint16_t fsb_get_total_current(fsb_st *this) {
	return this->read.total_current;
}

static inline fsb_ignkey_states_e fsb_get_ignkey_state(fsb_st *this) {
	return this->read.ignkey;
}

static inline uint8_t fsb_get_emcy(fsb_st *this) {
	return this->read.emcy;
}

static inline uint8_t fsb_get_doorsw1(fsb_st *this) {
	return this->read.doorsw1;
}

static inline uint8_t fsb_get_doorsw2(fsb_st *this) {
	return this->read.doorsw2;
}

static inline uint8_t fsb_get_seatsw(fsb_st *this) {
	return this->read.seatsw;
}



#endif /* NETWORK_FSB_H_ */
