/*
 * system_network.h
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */

#ifndef UI_SYSTEM_NETWORK_H_
#define UI_SYSTEM_NETWORK_H_

#include <uv_utilities.h>
#include <uv_ui.h>

#define SYSTEM_NETWORK_BUFFER_LEN			9
#define SYSTEM_NETWORK_ROW_VALUE_LEN		40

enum {
	ESB = 0,
	FSB,
	CSB,
	ECU,
	L_KEYPAD,
	R_KEYPAD,
	PEDAL,
	UW180S_ECU,
	UW180S_MB,
	DEV_COUNT
};
typedef uint8_t devices_e;

typedef struct {
	uv_uitreeview_st treeview;
	uv_uitreeobject_st *treeviewbuffer[SYSTEM_NETWORK_BUFFER_LEN];

	devices_e dev;

	uv_uitreeobject_st objs[DEV_COUNT];

	uv_uiobject_st *buffer[SYSTEM_NETWORK_BUFFER_LEN];
	uv_uilabel_st name;
	uv_uilabel_st row1_topics;
	uv_uilabel_st row1_values;
	char row1_val_str[SYSTEM_NETWORK_ROW_VALUE_LEN];
	uv_uilabel_st row2_topics;
	uv_uilabel_st row2_values;
	char row2_val_str[SYSTEM_NETWORK_ROW_VALUE_LEN];
	uv_uilabel_st row3_topics;
	uv_uilabel_st row3_values;
	char row3_val_str[SYSTEM_NETWORK_ROW_VALUE_LEN];
	uv_uibutton_st back;
} system_network_st;


void system_network_show(void);

uv_uiobject_ret_e system_network_step(const uint16_t step_ms);


#endif /* UI_SYSTEM_NETWORK_H_ */
