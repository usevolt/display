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
void netdev_init(void *me, void (*update_callb)(void*)) {
	this->connected = false;
	this->notified = false;
	uv_delay_init(NETDEV_CONNECTION_TIME_OUT_MS, &this->timeout_delay);
	this->transmission_delay = -1;
	this->update_callb = update_callb;
	this->disconnected_entry_type = LOG_NETDEV_DISCONNECTED;
}


void netdev_step(void *me, unsigned int step_ms) {
	if (uv_delay(step_ms, &this->timeout_delay)) {
		if (this->connected) {
			this->connected = false;
			this->notified = false;
		}
//		todo: log warning disconnected because of unintended warnings
//		if (!this->notified) {
//			bool entry_found = false;
//			for (int i = 0; i < log_get_nack_count(); i++) {
//				log_entry_st e;
//				log_get_nack(&e, i);
//				if (e.type == this->disconnected_entry_type) {
//					entry_found = true;
//					break;
//				}
//			}
//			if (!entry_found) {
//				log_add(this->disconnected_entry_type, this->node_id);
//			}
//			this->notified = true;
//		}
	}
	if (uv_delay(step_ms, &this->transmission_delay)) {
		this->update_callb(this);
	}
}


void netdev_set_transmit_failure(void *me) {
	uv_delay_init(NETDEV_TRANSMISSION_FAILURE_DELAY, &this->transmission_delay);
}


void netdev_receive_heartbeat(void *me, uv_can_message_st *msg) {
	if (msg->type == CAN_STD && (msg->id & 0xFF) == this->node_id &&
			msg->data_8bit[0] == CANOPEN_OPERATIONAL) {
		if (!this->connected) {
			this->connected = true;
			this->notified = false;
		}
		else {
			if (!this->notified) {
				//check if log warning as active and clear it
				for (int i = 0; i < log_get_nack_count(); i++) {
					log_entry_st e;
					log_get_nack(&e, i);
					if (e.type == this->disconnected_entry_type) {
						log_ack(i);
						i = 0;
					}
				}
				this->notified = true;
			}
		}
		uv_delay_init(NETDEV_CONNECTION_TIME_OUT_MS, &this->timeout_delay);
	}
}
