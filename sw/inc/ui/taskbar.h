/*
 * taskbar.h
 *
 *  Created on: Sep 30, 2016
 *      Author: usevolt
 */

#ifndef TASKBAR_H_
#define TASKBAR_H_


#include <uv_ui.h>


/// @brief: taskbar buffer length
#define TASKBAR_BUF_LEN			20
#define TASKBAR_TIME_LEN		6
#define TASKBAR_COUNT_STR_LEN	16
#define TASKBAR_HOUR_STR_LEN	8


enum {
	TASKBAR_ALERTS = 0,
	TASKBAR_NO_ALERTS
};
typedef uint8_t taskbar_state_e;

typedef struct {
	uv_uiwindow_st taskbar;
	uv_uiobject_st *taskbar_buffer[TASKBAR_BUF_LEN];

	taskbar_state_e state;

	union {
		struct {
			uv_uidigit_st hours;
			uv_uilabel_st hours_label;

			uv_uilabel_st engine_water;
			uv_uilabel_st engine_oil_press;
			uv_uilabel_st engine_alt;
			uv_uilabel_st engine_glow_plugs;
			int engine_delay;
			bool engine_visible;

			uv_uilabel_st emcy_stop;
			uv_uilabel_st emcy_label;
			int emcy_delay;

#if LM
			uv_uitoucharea_st gear_touch;
			uv_uidigit_st gear;
			uv_uilabel_st gear_label;
#endif
			uv_uilabel_st horn;
			uv_uilabel_st horn_label;
			uv_uitoucharea_st horn_touch;

			uv_uiprogressbar_st voltage_level;

			uv_uiprogressbar_st fuel_level;

			uv_uiprogressbar_st oil_level;

			uv_uiprogressbar_st otemp_bar;

			uv_uiprogressbar_st mtemp_bar;

			uv_uidigit_st clock;
			char time[TASKBAR_TIME_LEN];
		};
		struct {
			uv_uitoucharea_st touch;

			char count_str[TASKBAR_COUNT_STR_LEN];
			uv_uilabel_st count_label;

			uv_uilabel_st icon_label;

			uv_uilabel_st info_label;

			uv_uilabel_st click_label;

			int bg_delay;

			uint16_t log_count;
		};
	};


	int delay;

} taskbar_st;


void taskbar_init(uv_uidisplay_st *display);

void taskbar_step(const uint16_t step_ms);










#endif /* TASKBAR_H_ */
