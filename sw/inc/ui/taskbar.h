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
	uv_window_st taskbar;
	uv_ui_object_st *taskbar_buffer[TASKBAR_BUF_LEN];

	uv_label_st clock;

} taskbar_st;


void taskbar_init(taskbar_st *this, uv_display_st *display);

void taskbar_step(taskbar_st *this, uint32_t step_ms);

#endif /* TASKBAR_H_ */
