/*
 * netdev.c
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */



#include "netdev.h"
#include "log.h"
#include <uv_canopen.h>



#define this ((netdev_st*)me)

/// @brief: Initializes the netdev structure
void netdev_init(void *me) {
	this->connected = false;
	uv_delay_init(NETDEV_CONNECTION_TIME_OUT_MS, &this->delay);
}


void netdev_step(void *me, unsigned int step_ms) {
	if (uv_delay(step_ms, &this->delay)) {
		this->connected = false;
		log_add(LOG_NETDEV_DISCONNECTED, this->node_id);
	}
}




void netdev_receive_heartbeat(void *me, uv_can_message_st *msg) {
	if (msg->type == CAN_STD && (msg->id & 0xFF) == this->node_id) {
		this->connected = true;
		uv_delay_init(NETDEV_CONNECTION_TIME_OUT_MS, &this->delay);
	}
}
