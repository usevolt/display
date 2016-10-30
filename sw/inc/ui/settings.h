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
#include "settings_general.h"

#define SETTINGS_BUFFER_LEN	5
#define SETTINGS_GENERAL_BUFFER_LEN	18
#define SETTINGS_TAB_COUNT			4

/// @brief: Main settings window
typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SETTINGS_BUFFER_LEN];

	uv_uilabel_st topic;
	uv_uibutton_st cancel;
	uv_uibutton_st ok;

	const char **tab_names;

	uv_uitabwindow_st tabs;
	uv_uiobject_st *tabs_buffer[SETTINGS_GENERAL_BUFFER_LEN];

	/// @brief: Window structures for all tabs
	union {
		settings_general_st general;
	};

} settings_st;


void settings_show(int16_t tab_index);



#endif /* UI_SETTINGS_H_ */
