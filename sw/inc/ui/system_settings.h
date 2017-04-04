/*
 * system_settings.h
 *
 *  Created on: Dec 29, 2016
 *      Author: usevolt
 */

#ifndef UI_SYSTEM_SETTINGS_H_
#define UI_SYSTEM_SETTINGS_H_

#include <uv_utilities.h>
#include <uv_ui.h>
#include <uv_rtc.h>

#define SYSTEM_SETTINGS_BUF_LEN		25
#define DATE_STR_LEN				40
#define CALIB_LINE_LEN				40

typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SYSTEM_SETTINGS_BUF_LEN];

	uv_uilabel_st impls_label;
	uv_uilist_st impls_list;
	char *impl_names[UW_IMPLEMENT_COUNT];

	uv_uislider_st power_usage;

	// joystick calibration
	uv_uitogglebutton_st calib_start;
	uv_uilabel_st calib_help;
	uv_uilabel_st calib_labels1;
	uv_uilabel_st calib_labels2;
	uv_uilabel_st calib_labels3;
	uv_uilabel_st calib_values1;
	char calib_values1_str[CALIB_LINE_LEN];
	uv_uilabel_st calib_values2;
	char calib_values2_str[CALIB_LINE_LEN];
	uv_uilabel_st calib_values3;
	char calib_values3_str[CALIB_LINE_LEN];

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

} system_settings_st;


void system_settings_show(void);

void system_settings_step(uint16_t step_ms);

#endif /* UI_SYSTEM_SETTINGS_H_ */
