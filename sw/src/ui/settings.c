/*
 * settings.c
 *
 *  Created on: Oct 28, 2016
 *      Author: usevolt
 */

#include "settings.h"
#include "main.h"
#include "gui.h"
#include "alert.h"
#include "home.h"
#include <string.h>
#include <stdlib.h>


#define this (&gui.windows.settings)


static const char* tab_names[] = {
		"General",
		"Valve configuration",
		"Controls",
		"Joystick calibration"
};


static void cancel_callb(void *me, uibutton_state_e state);
static void ok_callb(void *me, uibutton_state_e state);
static void tabs_callb(void *me, uint16_t tab);

void settings_show(int16_t tab_index) {
	uv_rtos_mutex_lock(&gui_mutex);

	uv_uiwindow_clear(&gui.main_window);

	gui.step_callb = NULL;

	this->tab_names = tab_names;

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_uibb(&gui.main_window)->width, uv_uibb(&gui.main_window)->height,
			uv_uiwindow_step);

	TOPIC_INIT(&this->window, &this->topic, "Settings");

	CANCEL_INIT(&this->window, &this->cancel, cancel_callb);

	OK_INIT(&this->window, &this->ok, ok_callb);

	uv_uitabwindow_init(&this->tabs, SETTINGS_TAB_COUNT,&uv_uistyles[WINDOW_STYLE_INDEX],
			this->tabs_buffer, this->tab_names, tabs_callb);
	uv_uiwindow_add(&this->window, &this->tabs, 0, TOPIC_HEIGHT + 10,
			uv_uibb(&this->window)->width, uv_uibb(&this->window)->height - TOPIC_HEIGHT - 10,
			uv_uitabwindow_step);

	// set the requested tab
	uv_uitabwindow_set_tab(&this->tabs, tab_index);

	uv_rtos_mutex_unlock(&gui_mutex);
}

static void tabs_callb(void *me, uint16_t tab) {
	uv_uiwindow_clear(&this->tabs);

	if (tab == 0) {
		gui.step_callb = settings_general_step;
		settings_general_show(&this->general, &this->tabs);
	}
}


static void cancel_callb(void *me, uibutton_state_e state) {
	if (state == UIBUTTON_CLICKED) {
		home_show();
	}
}


static void ok_callb(void *me, uibutton_state_e state) {

}


