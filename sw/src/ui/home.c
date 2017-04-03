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
	uv_uiwindow_set_contentbb(&this->window, uv_uibb(&gui.main_window)->width,
			uv_uibb(&gui.main_window)->height * 1.5f);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_ui_get_bb(&gui.main_window)->width, uv_ui_get_bb(&gui.main_window)->height,
			uv_uiwindow_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uiwindow_get_contentbb(&this->window).width,
			uv_uiwindow_get_contentbb(&this->window).height, 2, 2);
	uv_uigridlayout_set_padding(&grid, 25, 25);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->dashboard, "Dashboard", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->dashboard, bb.x, bb.y,
			bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->settings, "Settings", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->settings, bb.x, bb.y,
			bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->system, "System", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->system, bb.x, bb.y,
			bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->logout, "Log out", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->logout, bb.x, bb.y,
			bb.width, bb.height, uv_uibutton_step);

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
