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

#define SETTINGS_GENERAL_TREEVIEW_LEN 5
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
	uv_uitreeobject_st langobj;

	union {
		struct {
			uv_uitogglebutton_st drive_lights;
			uv_uitogglebutton_st work_lights;
			uv_uislider_st power_usage;
			uv_uitogglebutton_st radiator_enable;
		} general;
		struct {
			uv_uislider_st brightness;
			uv_uislider_st oilcooler_trigger;
			uv_uislider_st drivef_comp;
			uv_uislider_st driveb_comp;
		} system;
		struct {
			uv_uilist_st impls_list;
			char *impl_names[HCU_IMPLEMENT_COUNT];
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
		struct {
			uv_uilist_st languages;
			char *lang_list[LANG_COUNT];
			uv_uibutton_st setlang;
		} lang;
	};


} settings_general_st;


/// @brief: Shows this window
void settings_general_show(void);


#endif /* UI_SETTINGS_GENERAL_H_ */
