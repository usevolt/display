/*
 * taskbar.c
 *
 *  Created on: Sep 30, 2016
 *      Author: usevolt
 */


#include "taskbar.h"



void taskbar_init(taskbar_st *this, uv_uidisplay_st *display) {
	uv_uiwindow_init(&this->taskbar, this->taskbar_buffer, &uv_uiwindow_styles[TASKBAR_STYLE_INDEX]);
	uv_uidisplay_add(display, &this->taskbar,
			0, LCD_H(0.9f), LCD_W(1.0f), LCD_H(0.1f), true, uv_uiwindow_step);

	uv_uilabel_init(&this->clock, &font_16X26, ALIGN_CENTER_RIGHT, 0xFFFFFF, "12:00");
	uv_uiwindow_add(&this->taskbar, &this->clock,
			uv_ui_get_bb(&this->taskbar)->width - 110, 0, 100,
			uv_ui_get_bb(&this->taskbar)->height, true, uv_uilabel_step);

}

