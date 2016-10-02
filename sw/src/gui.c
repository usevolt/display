/*
 * gui.c
 *
 *  Created on: Sep 23, 2016
 *      Author: usevolt
 */



#include "gui.h"
#include "pin_mappings.h"
#include "main.h"
#include <uv_pwm.h>
#include <uv_rtos.h>


#define this (&((dspl_st*)me)->gui)

#define model ((dspl_st *)me)

void gui_init(void *me) {
	this->backlight_curr = 0;
	uv_display_init(&this->display, this->display_buffer, &uv_window_styles[WINDOW_STYLE_INDEX]);

	// add all different windows in the UI here
	uv_window_init(&this->main_window, this->main_window_buffer, &uv_window_styles[WINDOW_STYLE_INDEX]);
	uv_display_add(&this->display, &this->main_window, 0, 0, LCD_W(1.0f), LCD_H(0.9f), true, uv_window_step);

	home_init(&this->home, &this->main_window);

	taskbar_init(&this->taskbar, &this->display);
}


void gui_reset(void *me) {
	gui_init(this);
	this->backlight_trg = 100;
}



void gui_step(void *me) {
	uint16_t step_ms = GUI_STEP_MS;

	while (true) {

		// adjust the screen brightness
		int32_t delta = this->backlight_trg - this->backlight_curr;
		if (delta > BACKLIGHT_KP_MAX) delta = BACKLIGHT_KP_MAX;
		else if (delta < -BACKLIGHT_KP_MAX) delta = -BACKLIGHT_KP_MAX;
		this->backlight_curr += delta * BACKLIGHT_KP;
		uv_pwm_set(LCD_BACKLIGHT, PWM_MAX_VALUE - (float) this->backlight_curr / 0xFFFF * PWM_MAX_VALUE);

		uv_display_step(&this->display, step_ms);

		home_step(&this->home, step_ms);

		taskbar_step(&this->taskbar, step_ms);

		uv_rtos_task_delay(step_ms);
	}
}


void gui_set_backlight(void *me, uint8_t value) {
	if (value > 100) value = 100;
	this->backlight_trg = (value / 100.0f) * 0xFFFF;
}
