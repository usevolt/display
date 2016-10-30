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
#define TASKBAR_BUF_LEN			10


typedef struct {
	uv_uiwindow_st taskbar;
	uv_uiobject_st *taskbar_buffer[TASKBAR_BUF_LEN];

	uv_uilabel_st clock;

	uv_uilabel_st mtemp;
	uv_uiprogressbar_st mtemp_bar;

	uv_uilabel_st otemp;
	uv_uiprogressbar_st otemp_bar;

	uv_uilabel_st oil;
	uv_uiprogressbar_st oil_level;

	uv_uilabel_st fuel;
	uv_uiprogressbar_st fuel_level;

} taskbar_st;


void taskbar_init(uv_uidisplay_st *display);

void taskbar_step(uint16_t step_ms);


#endif /* TASKBAR_H_ */
