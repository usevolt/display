/*
 * settings_general.h
 *
 *  Created on: Oct 29, 2016
 *      Author: usevolt
 */

#ifndef UI_SETTINGS_GENERAL_H_
#define UI_SETTINGS_GENERAL_H_


#include <uv_ui.h>
#include <uv_rtc.h>

#define SETTINGS_GENERAL_TREEVIEW_LEN 4
#define SETTINGS_GENERAL_BUFFER_LEN	14
#define DATE_STR_LEN				40


typedef struct {

	uv_uitreeview_st treeview;
	uv_uitreeobject_st *objbuffer[SETTINGS_GENERAL_TREEVIEW_LEN];
	uv_uiobject_st *buffer[SETTINGS_GENERAL_BUFFER_LEN];


	uv_uitreeobject_st generalobj;
	uv_uitreeobject_st displayobj;
	uv_uitreeobject_st implementobj;
	uv_uitreeobject_st dateobj;

	union {
		struct {
			uv_uitogglebutton_st drive_lights;
			uv_uitogglebutton_st work_lights;
			uv_uislider_st wiper;
			uv_uislider_st heater;
			uv_uislider_st power_usage;
		} general;
		struct {
			uv_uislider_st brightness;
			uv_uislider_st volume;
		} display;
		struct {
			uv_uilist_st impls_list;
			char *impl_names[UW_IMPLEMENT_COUNT];
		} implement;
		struct {
			// contains the time when settings window was opened
			uv_time_st date;
			char datestr[DATE_STR_LEN];
			uv_uilabel_st date_label;

			uv_uilabel_st time;
			uv_uibutton_st sec_inc;
			uv_uibutton_st sec_dec;
			uv_uibutton_st min_inc;
			uv_uibutton_st min_dec;
			uv_uibutton_st hour_inc;
			uv_uibutton_st hour_dec;
			uv_uibutton_st day_inc;
			uv_uibutton_st day_dec;
			uv_uibutton_st month_inc;
			uv_uibutton_st month_dec;
			uv_uibutton_st year_inc;
			uv_uibutton_st year_dec;
		} date;
	};


} settings_general_st;


/// @brief: Shows this window
void settings_general_show(void);


#endif /* UI_SETTINGS_GENERAL_H_ */
