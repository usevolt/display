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

#define SETTINGS_BUFFER_LEN	5
#define SETTINGS_GENERAL_BUFFER_LEN	4

/// @brief: Main settings window
typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SETTINGS_BUFFER_LEN];

	uv_uilabel_st topic;
	uv_uibutton_st cancel;
	uv_uibutton_st ok;

	uv_uiwindow_st general;
	uv_uiobject_st *general_buffer[SETTINGS_GENERAL_BUFFER_LEN];
	uv_uilabel_st brightness_label;
	uv_uislider_st brightness;
	uv_uilabel_st volume_label;
	uv_uislider_st volume;

} settings_st;


void settings_show();



#endif /* UI_SETTINGS_H_ */
