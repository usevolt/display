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
	int delay;
} netdev_st;

#define NETDEV_CONNECTION_TIME_OUT_MS		5000


#undef this
#define this ((netdev_st*)me)


/// @brief: Initializes the netdev structure
void netdev_init(void *me);

/// @brief: Should be called when the node receives a heartbeat message
void netdev_receive_heartbeat(void *me, uv_can_message_st *msg);

static inline void netdev_set_node_id(void *me, uint8_t node_id) {
	this->node_id = node_id;
}
static inline uint8_t netdev_get_node_id(void *me) {
	return this->node_id;
}

static inline bool netdev_get_connected(void *me) {
	return this->connected;
}


void netdev_step(void *me, unsigned int step_ms);


#undef this

#endif /* NETWORK_NETDEV_H_ */
