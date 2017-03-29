/*
 * keypad.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef KEYPADS_H_
#define KEYPADS_H_


#include <uv_utilities.h>
#include "netdev.h"
#include "vehicle.h"


#define KEYPAD_BUTTON_COUNT 	10


typedef struct {
	EXTENDS(netdev_st);

	struct {
		int8_t x;
		uint8_t x_err;
		int8_t y;
		uint8_t y_err;
		int8_t z;
		uint8_t z_err;
		int8_t v;
		uint8_t v_err;
		int8_t b[KEYPAD_BUTTON_COUNT];
	} read;

} keypad_st;

void keypad_update(void *me);


static inline void rkeypad_init(keypad_st *this) {
	netdev_init(this, keypad_update);
	netdev_set_node_id(this, RKEYPAD_NODE_ID);
	netdev_set_disconnected_type(this, LOG_RKEYPAD_DISCONNECTED);
	this->read.x = 0;
	this->read.x_err = 0;
	this->read.y = 0;
	this->read.y_err = 0;
	this->read.z = 0;
	this->read.z_err = 0;
	this->read.v = 0;
	this->read.v_err = 0;
	for (int i = 0; i < KEYPAD_BUTTON_COUNT; i++) {
		this->read.b[i] = 0;
	}
}


static inline void lkeypad_init(keypad_st *this) {
	netdev_init(this, keypad_update);
	netdev_set_node_id(this, LKEYPAD_NODE_ID);
	netdev_set_disconnected_type(this, LOG_LKEYPAD_DISCONNECTED);
	this->read.x = 0;
	this->read.y = 0;
	this->read.z = 0;
	this->read.v = 0;
	for (int i = 0; i < KEYPAD_BUTTON_COUNT; i++) {
		this->read.b[i] = 0;
	}
}

static inline int8_t keypad_get_x(keypad_st *this) {
	return this->read.x;
}

static inline uint8_t keypad_get_x_err(keypad_st *this) {
	return this->read.x_err;
}

static inline int8_t keypad_get_y(keypad_st *this) {
	return this->read.y;
}

static inline uint8_t keypad_get_y_err(keypad_st *this) {
	return this->read.y_err;
}

static inline int8_t keypad_get_z(keypad_st *this) {
	return this->read.z;
}

static inline uint8_t keypad_get_z_err(keypad_st *this) {
	return this->read.z_err;
}

static inline int8_t keypad_get_v(keypad_st *this) {
	return this->read.v;
}

static inline uint8_t keypad_get_v_err(keypad_st *this) {
	return this->read.v_err;
}

static inline unsigned int keypad_get_button(keypad_st *this, uint8_t index) {
	return this->read.b[index];
}

void keypad_step(keypad_st *this, unsigned int step_ms);



#endif /* KEYPADS_H_ */
