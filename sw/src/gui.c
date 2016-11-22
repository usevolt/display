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


#define this (&gui)

gui_st gui;

uv_mutex_ptr gui_mutex;

void gui_init() {
	uv_rtos_mutex_init(&gui_mutex);

	this->backlight_curr = 0;
	gui_set_backlight(100);
	uv_uidisplay_init(&this->display, this->display_buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);


	uv_uiwindow_init(&this->main_window, this->main_buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uidisplay_add(&this->display, &this->main_window, 0, 0, LCD_W(1), LCD_H(0.88), uv_uiwindow_step);

	taskbar_init(&this->display);

	uv_rtos_task_create(gui_step, "gui", UV_RTOS_MIN_STACK_SIZE * 12,
			NULL, UV_RTOS_IDLE_PRIORITY + 1, NULL);

	this->step_callb = NULL;


	// by default the log in screen
	login_show();
}



void gui_step(void *nullptr) {
	uint16_t step_ms = GUI_STEP_MS;

	while (true) {

		// adjust the screen brightness
		int32_t delta = this->backlight_trg - this->backlight_curr;
		if (delta > BACKLIGHT_KP_MAX) delta = BACKLIGHT_KP_MAX;
		else if (delta < -BACKLIGHT_KP_MAX) delta = -BACKLIGHT_KP_MAX;
		this->backlight_curr += delta * BACKLIGHT_KP;
		uv_pwm_set(LCD_BACKLIGHT, PWM_MAX_VALUE - (float) this->backlight_curr / 0xFFFF * PWM_MAX_VALUE);

		// lock GUI mutex
		uv_rtos_mutex_lock(&gui_mutex);

		// active window step function
		if (this->step_callb)
			this->step_callb(step_ms);

		// taskbar step function
		taskbar_step(step_ms);

		// display step function
		uv_uidisplay_step(&this->display, step_ms);

		// unlock GUI mutex
		uv_rtos_mutex_unlock(&gui_mutex);


		uv_rtos_task_delay(step_ms);
	}
}


void gui_set_backlight(uint8_t value) {
	if (value > 100) value = 100;
	this->backlight_trg = (value / 100.0f) * 0xFFFF;
}


int16_t gui_get_backlight() {
	return this->backlight_trg * (100.0f / 0xFFFF);
}
