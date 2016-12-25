/*
 * system.h
 *
 *  Created on: Oct 28, 2016
 *      Author: usevolt
 */

#ifndef UI_SYSTEM_H_
#define UI_SYSTEM_H_

#include <uv_utilities.h>
#include <uv_ui.h>
#include <uv_rtc.h>
#include "main.h"

#define DATE_STR_LEN				40
#define SYSTEM_BUFFER_LEN	16
#define ABOUT_STR_LEN		70

typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SYSTEM_BUFFER_LEN];

	uv_uibutton_st cancel;
	uv_uibutton_st ok;

	uv_uilabel_st topic;
	uv_uilabel_st about;
	char about_str[ABOUT_STR_LEN];

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


} system_st;


void system_show();

void system_step(uint16_t step_ms);

#endif /* UI_SYSTEM_H_ */
