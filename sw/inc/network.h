/*
 * network.h
 *
 *  Created on: Jul 21, 2016
 *      Author: usevolt
 */

#ifndef NETWORK_H_
#define NETWORK_H_

/// @brief: Handles all network related configurations


#include <uv_utilities.h>
#include <uv_terminal.h>


/// @brief: A macro to cast derived data types to network_node_st
#define NETWORK_NODE(ptr)	((network_node_st*) ptr)


typedef enum {
	/// @brief: The connection is functional
	NETWORK_STATUS_CONNECTED,
	/// @brief: The connection is disabled intentionally
	NETWORK_STATUS_DISABLED,
	/// @brief: The connection is lost. The device couldn't be found
	NETWORK_STATUS_LOST
} _network_node_status_e;
typedef uint8_t network_node_status_e;



typedef struct {
	/// @brief: CANopen node ID
	uint8_t node_id;
	/// @brief: A unique serial number identifying the device
	uint32_t serial_number[4];
	/// @brief: The status of the connection to this node
	network_node_status_e status;
	/// @brief: The status delay variable which is used to determine
	/// if the connection was lost to the device
	uint16_t status_delay;
} network_node_st;



/// @brief: Variables which hold all data from this CAN network
typedef struct {
	/// @brief: MSB data structure. Inherits from network_node
	struct {
		network_node_st node;
	} msb;
	/// @brief: CSB data structure. Inherits from network_node
	struct {
		network_node_st node;
	} csb;
	/// @brief: ECU data structure. Inherits from network_node
	struct {
		network_node_st node;
	} ecu;
	/// @brief: UW181S data structure. Inherits from network_node
	struct {
		network_node_st node;
	} uw181s;
	/// @brief: Pedal data structure. Inherits from network_node
	struct {
		network_node_st node;
	} pedal;
	/// @brief: Left keypad data structure. Inherits from network_node
	struct {
		network_node_st node;
	} lkeyp;
	/// @brief: Right keypad data structure. Inherits from network_node
	struct {
		network_node_st node;
	} rkeyp;
	/// @brief: UW181S measure device structure. Inherits from network_node
	struct {
		network_node_st node;
	} uw181s_mb;
	/// @brief: GSM device data structure. Inherits from network_node
	struct {
		network_node_st node;
	} gsm;
} network_st;


/// @brief: Initializes the network settings to their default values
uv_errors_e network_init(network_st *me);


/// @brief: A terminal callback to configure MSB
void network_msb_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv);

/// @brief: A terminal callback to configure CSB
void network_csb_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv);

/// @brief: A terminal callback to configure Left keypad
void network_lkeyp_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv);

/// @brief: A terminal callback to configure Right keypad
void network_rkeyp_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv);

/// @brief: A terminal callback to configure ECU
void network_ecu_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv);

/// @brief: A terminal callback to configure pedal
void network_pedal_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv);

/// @brief: A terminal callback to configure UW181S
void network_uw181s_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv);

/// @brief: A terminal callback to configure UW181S Measure device
void network_uw181smb_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv);

/// @brief: A terminal callback to configure GSM device
void network_gsm_conf(void *me, unsigned int cmd, unsigned int args, argument_st *argv);






#endif /* NETWORK_H_ */
