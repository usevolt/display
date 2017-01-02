/*
 * keypads.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "keypads.h"

void keypad_step(keypad_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);

}


#define this ((keypad_st*)me)

void keypad_update(void *me) {

}
