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




typedef struct {
	EXTENDS(netdev_st);

	struct {
		int16_t x;
		int16_t y;
		int16_t z;
		union {
			uint16_t buttons;
			struct {
				unsigned int b1 : 1;
				unsigned int b2 : 1;
				unsigned int b3 : 1;
				unsigned int b4 : 1;
				unsigned int b5 : 1;
				unsigned int b6 : 1;
				unsigned int b7 : 1;
				unsigned int b8 : 1;
				unsigned int b9 : 1;
				unsigned int b10 : 1;
				unsigned int b11 : 1;
				unsigned int b12 : 1;
				unsigned int b13 : 1;
				unsigned int b14 : 1;
				unsigned int b15 : 1;
				unsigned int b16 : 1;
			};
		};
	} read;

} keypad_st;

void keypad_update(void *me);


static inline void rkeypad_init(keypad_st *this) {
	netdev_init(this, keypad_update);
	netdev_set_node_id(this, RKEYPAD_NODE_ID);
	this->read.x = 0;
	this->read.y = 0;
	this->read.z = 0;
	this->read.buttons = 0;
}


static inline void lkeypad_init(keypad_st *this) {
	netdev_init(this, keypad_update);
	netdev_set_node_id(this, LKEYPAD_NODE_ID);
}

static inline int16_t keypad_get_x(keypad_st *this) {
	return this->read.x;
}

static inline int16_t keypad_get_y(keypad_st *this) {
	return this->read.y;
}

static inline int16_t keypad_get_z(keypad_st *this) {
	return this->read.z;
}

static inline uint16_t keypad_get_buttons(keypad_st *this) {
	return this->read.buttons;
}

static inline unsigned int keypad_get_b1(keypad_st *this) {
	return this->read.b1;
}

static inline unsigned int keypad_get_b2(keypad_st *this) {
	return this->read.b2;
}

static inline unsigned int keypad_get_b3(keypad_st *this) {
	return this->read.b3;
}

static inline unsigned int keypad_get_b4(keypad_st *this) {
	return this->read.b4;
}

static inline unsigned int keypad_get_b5(keypad_st *this) {
	return this->read.b5;
}

static inline unsigned int keypad_get_b6(keypad_st *this) {
	return this->read.b6;
}

static inline unsigned int keypad_get_b7(keypad_st *this) {
	return this->read.b7;
}

static inline unsigned int keypad_get_b8(keypad_st *this) {
	return this->read.b8;
}

static inline unsigned int keypad_get_b9(keypad_st *this) {
	return this->read.b9;
}

static inline unsigned int keypad_get_b10(keypad_st *this) {
	return this->read.b10;
}

static inline unsigned int keypad_get_b11(keypad_st *this) {
	return this->read.b11;
}

static inline unsigned int keypad_get_b12(keypad_st *this) {
	return this->read.b12;
}

static inline unsigned int keypad_get_b13(keypad_st *this) {
	return this->read.b13;
}

static inline unsigned int keypad_get_b14(keypad_st *this) {
	return this->read.b14;
}

static inline unsigned int keypad_get_b15(keypad_st *this) {
	return this->read.b15;
}

static inline unsigned int keypad_get_b16(keypad_st *this) {
	return this->read.b16;
}


void keypad_step(keypad_st *this, unsigned int step_ms);



#endif /* KEYPADS_H_ */
