/*
 * settings_general.h
 *
 *  Created on: Oct 29, 2016
 *      Author: usevolt
 */

#ifndef UI_SETTINGS_GENERAL_H_
#define UI_SETTINGS_GENERAL_H_


#include <uv_ui.h>

#define SETTINGS_GENERAL_BUFFER_LEN	4
#define SETTINGS_GENERAL_TREEBUFFER_LEN	3



typedef struct {

	uv_uitreeview_st treeview;
	uv_uitreeobject_st *treebuffer[SETTINGS_GENERAL_TREEBUFFER_LEN];
	uv_uitreeobject_st driving_obj;
	uv_uitreeobject_st volume_obj;

	uv_uiobject_st *buffer[SETTINGS_GENERAL_BUFFER_LEN];
	uv_uiwindow_st window;
	union {
		struct {
			uv_uislider_st brightness;
			uv_uitogglebutton_st drive_lights;
			uv_uitogglebutton_st work_lights;
			uv_uislider_st wiper;
			uv_uislider_st heater;
		} general;

		struct {
			uv_uislider_st volume;

		} volume;
	};



} settings_general_st;


/// @brief: Shows this window
void settings_general_show();

void settings_general_step(uint16_t step_ms);


#endif /* UI_SETTINGS_GENERAL_H_ */
