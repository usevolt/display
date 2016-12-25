/*
 * netdev.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef NETWORK_NETDEV_H_
#define NETWORK_NETDEV_H_


#include <uv_utilities.h>

/// @file: Defines the basic data structure for network devices.
/// All network devices should inherit this one.

typedef struct {
	bool connected;
	uint8_t node_id;
} netdev_st;



#undef this
#define this ((netdev_st*)me)


/// @brief: Initializes the netdev structure
static inline void netdev_init(void *me) {
	this->connected = true;
}

static inline void netdev_set_node_id(void *me, uint8_t node_id) {
	this->node_id = node_id;
}
static inline uint8_t netdev_get_node_id(void *me) {
	return this->node_id;
}



void netdev_step(void *me, unsigned int step_ms);


#undef this

#endif /* NETWORK_NETDEV_H_ */
