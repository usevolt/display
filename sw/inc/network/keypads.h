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

} keypad_st;



static inline void rkeypad_init(keypad_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, RKEYPAD_NODE_ID);
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->buttons = 0;
}


static inline void lkeypad_init(keypad_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, LKEYPAD_NODE_ID);
}

static inline int16_t keypad_get_x(keypad_st *this) {
	return this->x;
}

static inline int16_t keypad_get_y(keypad_st *this) {
	return this->y;
}

static inline int16_t keypad_get_z(keypad_st *this) {
	return this->z;
}

static inline uint16_t keypad_get_buttons(keypad_st *this) {
	return this->buttons;
}

static inline unsigned int keypad_get_b1(keypad_st *this) {
	return this->b1;
}

static inline unsigned int keypad_get_b2(keypad_st *this) {
	return this->b2;
}

static inline unsigned int keypad_get_b3(keypad_st *this) {
	return this->b3;
}

static inline unsigned int keypad_get_b4(keypad_st *this) {
	return this->b4;
}

static inline unsigned int keypad_get_b5(keypad_st *this) {
	return this->b5;
}

static inline unsigned int keypad_get_b6(keypad_st *this) {
	return this->b6;
}

static inline unsigned int keypad_get_b7(keypad_st *this) {
	return this->b7;
}

static inline unsigned int keypad_get_b8(keypad_st *this) {
	return this->b8;
}

static inline unsigned int keypad_get_b9(keypad_st *this) {
	return this->b9;
}

static inline unsigned int keypad_get_b10(keypad_st *this) {
	return this->b10;
}

static inline unsigned int keypad_get_b11(keypad_st *this) {
	return this->b11;
}

static inline unsigned int keypad_get_b12(keypad_st *this) {
	return this->b12;
}

static inline unsigned int keypad_get_b13(keypad_st *this) {
	return this->b13;
}

static inline unsigned int keypad_get_b14(keypad_st *this) {
	return this->b14;
}

static inline unsigned int keypad_get_b15(keypad_st *this) {
	return this->b15;
}

static inline unsigned int keypad_get_b16(keypad_st *this) {
	return this->b16;
}


void keypad_step(keypad_st *this, unsigned int step_ms);

void keypad_update(keypad_st *this);



#endif /* KEYPADS_H_ */
