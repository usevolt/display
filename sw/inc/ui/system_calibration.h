/*
 * system_settings.h
 *
 *  Created on: Dec 29, 2016
 *      Author: usevolt
 */

#ifndef UI_SYSTEM_CALIBRATION_H_
#define UI_SYSTEM_CALIBRATION_H_

#include <uv_utilities.h>
#include <uv_ui.h>
#include <uv_rtc.h>

#define CALIB_LINE_LEN				40
#define SYSTEM_CALIB_BUF_LEN		11

typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SYSTEM_CALIB_BUF_LEN];

	// uw180s mb calibration
	uv_uilabel_st mb_label;
	uv_uibutton_st mb_calib_min;
	uv_uibutton_st mb_calib_max;

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

} system_calib_st;


void system_calib_show(void);

uv_uiobject_ret_e system_calib_step(const uint16_t step_ms);

#endif /* UI_SYSTEM_CALIBRATION_H_ */
