/*
 * home.c
 *
 *  Created on: Oct 24, 2016
 *      Author: usevolt
 */


#include "home.h"
#include "gui.h"

#define this (&gui.windows.home)



#define BUTW		300
#define BUTH		175


void home_show() {

	gui.step_callb = home_step;

	uv_uiwindow_clear(&gui.main_window);
	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_ui_get_bb(&gui.main_window)->width, uv_ui_get_bb(&gui.main_window)->height, uv_uiwindow_step);

	uv_uibutton_init(&this->dashboard, "Dashboard", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->dashboard, (LCD_W(0.5) - BUTW) / 2, LCD_H(0.05),
			BUTW, BUTH, uv_uibutton_step);

	uv_uibutton_init(&this->system, "System", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->system, (LCD_W(0.5) - BUTW) / 2, LCD_H(0.05) + BUTH + 25,
			BUTW, BUTH, uv_uibutton_step);

	uv_uibutton_init(&this->settings, "Settings", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->settings, LCD_W(0.5) + (LCD_W(0.5) - BUTW) / 2, LCD_H(0.05),
			BUTW, BUTH, uv_uibutton_step);

	uv_uibutton_init(&this->logout, "Log out", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->logout, LCD_W(0.5) + (LCD_W(0.5) - BUTW) / 2, LCD_H(0.05) + BUTH + 25,
			BUTW, BUTH, uv_uibutton_step);

}




void home_step(uint16_t step_ms) {
	if (uv_uibutton_clicked(&this->dashboard)) {
		dashboard_show();
	}
	else if (uv_uibutton_clicked(&this->system)) {
		system_show();
	}
	else if (uv_uibutton_clicked(&this->logout)) {
		login_show();
	}
	else if (uv_uibutton_clicked(&this->settings)) {
		settings_show();
	}
}
