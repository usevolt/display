/*
 * settings.h
 *
 *  Created on: Oct 28, 2016
 *      Author: usevolt
 */

#ifndef UI_SETTINGS_H_
#define UI_SETTINGS_H_


#include <uv_utilities.h>
#include <uv_ui.h>
#include <uv_rtc.h>
#include "main.h"
#include "settings_general.h"
#include "settings_valves.h"
#include "settings_implements.h"

#define SETTINGS_BUFFER_LEN	5
#define SETTINGS_TABS_BUFFER_LEN	1
#define SETTINGS_TAB_COUNT			3

/// @brief: Main settings window
typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SETTINGS_BUFFER_LEN];

	uv_uilabel_st topic;
	uv_uibutton_st cancel;
	uv_uibutton_st ok;

	char *tab_names[SETTINGS_TAB_COUNT];

	uv_uitabwindow_st tabs;
	uv_uiobject_st *tabs_buffer[SETTINGS_TABS_BUFFER_LEN];

	/// @brief: Window structures for all tabs
	union {
		settings_general_st general;
		settings_valves_st valves;
		settings_implements_st implements;
	};

} settings_st;


void settings_show(void);

uv_uiobject_ret_e settings_step(const uint16_t step_ms);

#endif /* UI_SETTINGS_H_ */
