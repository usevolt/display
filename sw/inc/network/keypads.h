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
#include "can_keypad.h"
#include <string.h>



enum {
	KEYPAD_CALIB_START = 1,
	KEYPAD_CALIB_END = 2
};
typedef uint8_t keypad_axis_calib_e;

typedef struct {
	EXTENDS(netdev_st);

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
	int8_t b[KEYP_BUTTON_COUNT];

	bool calib;

} keypad_st;

void keypad_update(void *me);

void rkeypad_init(keypad_st *this);

void lkeypad_init(keypad_st *this);

static inline int8_t keypad_get_x(keypad_st *this) {
	return this->x;
}

static inline uint8_t keypad_get_x_err(keypad_st *this) {
	return this->x_err;
}

static inline int8_t keypad_get_y(keypad_st *this) {
	return this->y;
}

static inline uint8_t keypad_get_y_err(keypad_st *this) {
	return this->y_err;
}

static inline int8_t keypad_get_z(keypad_st *this) {
	return this->z;
}

static inline uint8_t keypad_get_z_err(keypad_st *this) {
	return this->z_err;
}

static inline int8_t keypad_get_v(keypad_st *this) {
	return this->v;
}

static inline uint8_t keypad_get_v_err(keypad_st *this) {
	return this->v_err;
}

static inline unsigned int keypad_get_button(keypad_st *this, uint8_t index) {
	return this->b[index];
}

static inline uint16_t *keypad_get_x_calib(keypad_st *this) {
	return this->x_calib;
}

static inline uint16_t *keypad_get_y_calib(keypad_st *this) {
	return this->y_calib;
}

static inline uint16_t *keypad_get_z_calib(keypad_st *this) {
	return this->z_calib;
}

void keypad_calib_start(keypad_st *this);

void keypad_calib_end(keypad_st *this);

static inline bool keypad_get_calib_on(keypad_st *this) {
	return this->calib;
}

void keypad_step(keypad_st *this, unsigned int step_ms);



#endif /* KEYPADS_H_ */
