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

#define DATE_STR_LEN				40
#define SETTINGS_GENERAL_BUFFER_LEN	18



typedef struct {

	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SETTINGS_GENERAL_BUFFER_LEN];

	uv_uilabel_st brightness_label;
	uv_uislider_st brightness;
	uv_uilabel_st volume_label;
	uv_uislider_st volume;

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

} settings_general_st;


/// @brief: Shows this window
void settings_general_show();

void settings_general_step(uint16_t step_ms);


#endif /* UI_SETTINGS_GENERAL_H_ */
