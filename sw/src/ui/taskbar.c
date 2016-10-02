/*
 * taskbar.c
 *
 *  Created on: Sep 30, 2016
 *      Author: usevolt
 */


#include "taskbar.h"



void taskbar_init(taskbar_st *this, uv_display_st *display) {
	uv_window_init(&this->taskbar, this->taskbar_buffer, &uv_window_styles[TASKBAR_STYLE_INDEX]);
	uv_display_add(display, &this->taskbar,
			0, LCD_H(0.9f), LCD_W(1.0f), LCD_H(0.1f), true, uv_window_step);

	uv_label_init(&this->clock, &font_16X26, ALIGN_CENTER_RIGHT, 0xFFFFFF, "12:00");
	uv_window_add(&this->taskbar, &this->clock,
			uv_ui_get_bb(&this->taskbar)->width - 110, 0, 100,
			uv_ui_get_bb(&this->taskbar)->height, true, uv_label_step);

}

void taskbar_step(taskbar_st *this, uint32_t step_ms) {

	uv_window_step(&this->taskbar, step_ms);
}
