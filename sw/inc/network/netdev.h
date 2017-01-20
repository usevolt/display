/*
 * netdev.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef NETWORK_NETDEV_H_
#define NETWORK_NETDEV_H_


#include <uv_utilities.h>
#include "log.h"

/// @file: Defines the basic data structure for network devices.
/// All network devices should inherit this one.

typedef struct {
	bool connected;
	uint8_t node_id;
	int timeout_delay;
	int transmission_delay;
	void (*update_callb)(void*);
	log_entry_e disconnected_entry_type;
} netdev_st;

#define NETDEV_CONNECTION_TIME_OUT_MS		5000
#define NETDEV_TRANSMISSION_FAILURE_DELAY	5000


#undef this
#define this ((netdev_st*)me)


/// @brief: Initializes the netdev structure
///
/// @param update_callb: Function which handles updating the settings over the CAN bus.
/// Will  be called if the transmission fails.
void netdev_init(void *me, void (*update_callb)(void*));

/// @brief: This should be called if the CAN message transmission failed
/// for any node. Starts up the internal delay counter for retransmissions
void netdev_set_transmit_failure(void *me);


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
static inline void netdev_set_disconnected_type(void *me, log_entry_e type) {
	this->disconnected_entry_type = type;
}


void netdev_step(void *me, unsigned int step_ms);


#undef this

#endif /* NETWORK_NETDEV_H_ */
