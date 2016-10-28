/*
 * home.c
 *
 *  Created on: Oct 24, 2016
 *      Author: usevolt
 */


#include "home.h"
#include "gui.h"

#define this (&gui.home)

static void button_callb(void *button, uibutton_state_e state);


#define BUTW		300
#define BUTH		175


void home_show() {
	uv_rtos_mutex_lock(&gui_mutex);

	uv_uiwindow_clear(&gui.main_window);
	uv_uiwindow_init(&this->window, this->buffer, &uv_uiwindow_styles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_ui_get_bb(&gui.main_window)->width, uv_ui_get_bb(&gui.main_window)->height, uv_uiwindow_step);

	uv_uibutton_init(&this->dashboard, "Dashboard", &uv_uibutton_styles[0], button_callb);
	uv_uiwindow_add(&this->window, &this->dashboard, (LCD_W(0.5) - BUTW) / 2, LCD_H(0.05),
			BUTW, BUTH, uv_uibutton_step);

	uv_uibutton_init(&this->settings, "Settings", &uv_uibutton_styles[0], button_callb);
	uv_uiwindow_add(&this->window, &this->settings, (LCD_W(0.5) - BUTW) / 2, LCD_H(0.05) + BUTH + 25,
			BUTW, BUTH, uv_uibutton_step);

	uv_uibutton_init(&this->ioconfig, "System", &uv_uibutton_styles[0], button_callb);
	uv_uiwindow_add(&this->window, &this->ioconfig, LCD_W(0.5) + (LCD_W(0.5) - BUTW) / 2, LCD_H(0.05),
			BUTW, BUTH, uv_uibutton_step);

	uv_uibutton_init(&this->logout, "Log out", &uv_uibutton_styles[0], button_callb);
	uv_uiwindow_add(&this->window, &this->logout, LCD_W(0.5) + (LCD_W(0.5) - BUTW) / 2, LCD_H(0.05) + BUTH + 25,
			BUTW, BUTH, uv_uibutton_step);

	uv_rtos_mutex_unlock(&gui_mutex);
}



static void button_callb(void *button, uibutton_state_e state) {
	printf("button action\n\r");
}
