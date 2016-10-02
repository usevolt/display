/*
 * network.c
 *
 *  Created on: Jul 21, 2016
 *      Author: usevolt
 */


#include "network.h"
#include "main.h"
#include <string.h>
#include <stdlib.h>



uv_errors_e network_init(network_st *me) {


}



/// @brief: Configures network node variables from the arguments
static void network_node_conf(void *me, unsigned int args, argument_st *argv) {
	printf("Network node configuration\n\r");
	// if no arguments were given, print the settings
//	if (!strlen(args[0])) {
//		printf("Status: %x, node ID: %x ", NETWORK_NODE(me)->status, NETWORK_NODE(me)->node_id);
//		return;
//	}
//	if (uv_terminal_parse_bool(args[0])) {
//		if (NETWORK_NODE(me)->status == NETWORK_STATUS_DISABLED) {
//			NETWORK_NODE(me)->status = NETWORK_STATUS_CONNECTED;
//		}
//	}
//	else {
//		NETWORK_NODE(me)->status = NETWORK_STATUS_DISABLED;
//	}
//	// second argument is the CANopen node ID
//	NETWORK_NODE(me)->node_id = atoi(args[1]);

}

#if defined(this)
#undef this
#endif
#define this (&(((dspl_st*)me)->network))
void network_msb_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	network_node_conf(&this->msb, args, argv);
}

void network_csb_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	network_node_conf(&this->csb, args, argv);
}

void network_lkeyp_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	network_node_conf(&this->lkeyp, args, argv);

}

void network_rkeyp_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	network_node_conf(&this->rkeyp, args, argv);

}

void network_ecu_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	network_node_conf(&this->ecu, args, argv);

}

void network_pedal_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	network_node_conf(&this->pedal, args, argv);

}

void network_uw181s_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	network_node_conf(&this->uw181s, args, argv);

}

void network_uw181smb_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	network_node_conf(&this->uw181s_mb, args, argv);

}

void network_gsm_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv) {
	network_node_conf(&this->gsm, args, argv);

}



