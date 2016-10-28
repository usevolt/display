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

} taskbar_st;


void taskbar_init(uv_uidisplay_st *display);


#endif /* TASKBAR_H_ */
