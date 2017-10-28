/*
 * csb.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "csb.h"
#include "main.h"


void csb_init(csb_st *this) {
	netdev_init(this, csb_update);
	netdev_set_node_id(this, CSB_NODE_ID);
	netdev_set_disconnected_type(this, LOG_CSB_DISCONNECTED);
}


void csb_step(csb_st *this, unsigned int step_ms) {
	netdev_step(this, step_ms);

}


#define this ((csb_st*)me)
void csb_update(void *me) {
}
#undef this
