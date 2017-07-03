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
#define SETTINGS_GENERAL_TREEVIEW_LEN 3


typedef struct {


	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SETTINGS_GENERAL_BUFFER_LEN];

	uv_uitreeview_st treeview;
	uv_uitreeobject_st *objbuffer[SETTINGS_GENERAL_TREEVIEW_LEN];
	struct {
	uv_uitreeobject_st general;
	uv_uitreeobject_st volume;
	} treeobjs;

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
