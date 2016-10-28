/*
 * taskbar.c
 *
 *  Created on: Sep 30, 2016
 *      Author: usevolt
 */


#include "taskbar.h"
#include "gui.h"

#define this (&gui.taskbar)

void taskbar_init(uv_uidisplay_st *display) {
	uv_uiwindow_init(&this->taskbar, this->taskbar_buffer, &uv_uiwindow_styles[TASKBAR_STYLE_INDEX]);
	uv_uidisplay_add(display, &this->taskbar,
			0, LCD_H(0.9f), LCD_W(1.0f), LCD_H(0.1f), uv_uiwindow_step);

	uv_uilabel_init(&this->clock, &UI_FONT_BIG, ALIGN_CENTER_RIGHT,
			C(0xFFFFFF), uv_uiwindow_styles[TASKBAR_STYLE_INDEX].main_color, "12:00");
	uv_uiwindow_add(&this->taskbar, &this->clock,
			uv_ui_get_bb(&this->taskbar)->width - 110, 0, 100,
			uv_ui_get_bb(&this->taskbar)->height, uv_uilabel_step);

}

