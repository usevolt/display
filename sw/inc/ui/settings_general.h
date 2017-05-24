/*
 * settings_general.h
 *
 *  Created on: Oct 29, 2016
 *      Author: usevolt
 */

#ifndef UI_SETTINGS_GENERAL_H_
#define UI_SETTINGS_GENERAL_H_


#include <uv_ui.h>

#define SETTINGS_GENERAL_BUFFER_LEN	6



typedef struct {

	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SETTINGS_GENERAL_BUFFER_LEN];

	uv_uislider_st brightness;
	uv_uislider_st volume;

	uv_uitogglebutton_st drive_lights;
	uv_uitogglebutton_st work_lights;
	uv_uislider_st wiper;
	uv_uislider_st heater;

} settings_general_st;


/// @brief: Shows this window
void settings_general_show();


#endif /* UI_SETTINGS_GENERAL_H_ */
