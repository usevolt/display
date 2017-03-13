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

#define SYSTEM_SETTINGS_BUF_LEN		17
#define DATE_STR_LEN				40

typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SYSTEM_SETTINGS_BUF_LEN];

	uv_uilabel_st impls_label;
	uv_uilist_st impls_list;
	char *impl_names[UW_IMPLEMENT_COUNT];

	uv_uislider_st power_usage;

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
