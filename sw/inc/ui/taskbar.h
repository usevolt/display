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
#define TASKBAR_HOUR_STR_LEN	16


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

			uv_uilabel_st emcy_stop;
			uv_uilabel_st emcy_label;
			int emcy_delay;

			char hour_str[TASKBAR_HOUR_STR_LEN];
			uv_uilabel_st hours;

			uv_uiprogressbar_st voltage_level;

			uv_uiprogressbar_st fuel_level;

			uv_uiprogressbar_st oil_level;

			uv_uiprogressbar_st otemp_bar;

			uv_uiprogressbar_st mtemp_bar;

			uv_uilabel_st clock;
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

void taskbar_step(uint16_t step_ms);










#endif /* TASKBAR_H_ */
