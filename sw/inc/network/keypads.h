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
#include <string.h>


#define KEYPAD_BUTTON_COUNT 	10


enum {
	KEYPAD_CALIB_START = 1,
	KEYPAD_CALIB_END = 2
};
typedef uint8_t keypad_axis_calib_e;

typedef struct {
	EXTENDS(netdev_st);

	struct {
		int8_t x;
		uint8_t x_err;
		uint16_t x_calib[3];
		int8_t y;
		uint8_t y_err;
		uint16_t y_calib[3];
		int8_t z;
		uint8_t z_err;
		uint16_t z_calib[3];
		int8_t v;
		uint8_t v_err;
		int8_t b[KEYPAD_BUTTON_COUNT];
	} read;
	bool calib;

} keypad_st;

void keypad_update(void *me);


static inline void rkeypad_init(keypad_st *this) {
	netdev_init(this, keypad_update);
	netdev_set_node_id(this, RKEYPAD_NODE_ID);
	netdev_set_disconnected_type(this, LOG_RKEYPAD_DISCONNECTED);
	this->read.x = 0;
	this->read.x_err = 0;
	memset(this->read.x_calib, 0, sizeof(this->read.x_calib[0]) * 3);
	this->read.y = 0;
	this->read.y_err = 0;
	memset(this->read.y_calib, 0, sizeof(this->read.y_calib[0]) * 3);
	this->read.z = 0;
	this->read.z_err = 0;
	memset(this->read.z_calib, 0, sizeof(this->read.z_calib[0]) * 3);
	this->read.v = 0;
	this->read.v_err = 0;
	for (int i = 0; i < KEYPAD_BUTTON_COUNT; i++) {
		this->read.b[i] = 0;
	}
	this->calib = false;
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

static inline uint16_t *keypad_get_x_calib(keypad_st *this) {
	return this->read.x_calib;
}

static inline uint16_t *keypad_get_y_calib(keypad_st *this) {
	return this->read.y_calib;
}

static inline uint16_t *keypad_get_z_calib(keypad_st *this) {
	return this->read.z_calib;
}

void keypad_calib_start(keypad_st *this);

void keypad_calib_end(keypad_st *this);

static inline bool keypad_get_calib_on(keypad_st *this) {
	return this->calib;
}

void keypad_step(keypad_st *this, unsigned int step_ms);



#endif /* KEYPADS_H_ */
