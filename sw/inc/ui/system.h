/*
 * system.h
 *
 *  Created on: Oct 28, 2016
 *      Author: usevolt
 */

#ifndef UI_SYSTEM_H_
#define UI_SYSTEM_H_

#include <uv_utilities.h>
#include <uv_ui.h>
#include <uv_rtc.h>
#include "main.h"
#include "system_settings.h"
#include "system_restore.h"
#include "system_network.h"

#define SYSTEM_BUFFER_LEN		5
#define SYSTEM_TAB_BUFFER_LEN	1
#define ABOUT_STR_LEN			70

typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SYSTEM_BUFFER_LEN];

	uv_uitabwindow_st tabs;
	uv_uiobject_st *tabs_buffer[SYSTEM_TAB_BUFFER_LEN];

	uv_uibutton_st cancel;
	uv_uibutton_st ok;

	uv_uilabel_st topic;
	uv_uilabel_st about;
	char about_str[ABOUT_STR_LEN];

	union {
		system_settings_st sys_settings;
		system_network_st sys_network;
		system_restore_st sys_restore;
	} windows;



} system_st;


void system_show();

void system_step(uint16_t step_ms);

#endif /* UI_SYSTEM_H_ */
