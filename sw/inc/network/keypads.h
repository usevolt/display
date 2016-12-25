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


#define RKEYPAD_NODE_ID		3
#define LKEYPAD_NODE_ID		4



typedef struct {
	EXTENDS(netdev_st);

} keypad_st;



static inline void rkeypad_init(keypad_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, RKEYPAD_NODE_ID);
}


static inline void lkeypad_init(keypad_st *this) {
	netdev_init(this);
	netdev_set_node_id(this, LKEYPAD_NODE_ID);
}


void keypad_step(keypad_st *this, unsigned int step_ms);

void keypad_update(keypad_st *this);



#endif /* KEYPADS_H_ */
