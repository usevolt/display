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
#include "network.h"
#include "log.h"
#include <string.h>
#include <stdlib.h>


#define this (&gui.windows.settings)


static const char* tab_names[] = {
		"General",
		"Valve\nconfigurations",
		"Implement\nsettings"
};


void settings_show() {

	uv_uiwindow_clear(&gui.main_window);

	gui.step_callb = settings_step;

	this->tab_names = tab_names;

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_uibb(&gui.main_window)->width, uv_uibb(&gui.main_window)->height,
			uv_uiwindow_step);

	TOPIC_INIT(&this->window, &this->topic, "Settings");

	CANCEL_INIT(&this->window, &this->cancel);

	OK_INIT(&this->window, &this->ok);

	uv_uitabwindow_init(&this->tabs, SETTINGS_TAB_COUNT, &uv_uistyles[WINDOW_STYLE_INDEX],
			this->tabs_buffer, this->tab_names);
	uv_uiwindow_add(&this->window, &this->tabs, 0, TOPIC_HEIGHT + 10,
			uv_uibb(&this->window)->width, uv_uibb(&this->window)->height - TOPIC_HEIGHT - 10,
			uv_uitabwindow_step);

	// set the requested tab
	uv_uitabwindow_set_tab(&this->tabs, 0);
	settings_general_show();

}


void settings_step(uint16_t step_ms) {

	if (uv_uitabwindow_tab_changed(&this->tabs)) {

		if (uv_uitabwindow_tab(&this->tabs) == 0) {
			settings_general_show();
		}
		else if (uv_uitabwindow_tab(&this->tabs) == 1) {
			settings_valves_show();
		}
		else if (uv_uitabwindow_tab(&this->tabs) == 2) {
			settings_implements_show();
		}
	}

	switch (uv_uitabwindow_tab(&this->tabs)) {
	case 0:
		settings_general_step(step_ms);
		break;
	case 1:
		settings_valves_step(step_ms);
		break;
	case 2:
		settings_implements_step(step_ms);
		break;
	default:
		break;
	}

	if (uv_uibutton_clicked(&this->ok)) {
		uv_errors_e e = uv_memory_save();
		if (e) {
			log_add(LOG_MEMORY_SAVE_FAILED, (int32_t) e);
		}
		// save ecu params
		ecu_save_params();
		home_show();
	}
	else if (uv_uibutton_clicked(&this->cancel)) {
		uv_memory_load();
		network_update(&dspl.network);

		home_show();
	}

}

