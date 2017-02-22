/*
 * system.c
 *
 *  Created on: Oct 28, 2016
 *      Author: usevolt
 */



#include "system.h"
#include "main.h"
#include "gui.h"


#define this (&gui.windows.system)

static const char* tab_names[] = {
		"System\nSettings",
		"Network\nDiagnostics",
		"Log",
		"System\nRestore"
};


void system_show() {

	uv_uiwindow_clear(&gui.main_window);

	gui.step_callb = system_step;

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_uibb(&gui.main_window)->width, uv_uibb(&gui.main_window)->height,
			uv_uiwindow_step);

	TOPIC_INIT(&this->window, &this->topic, "System");

	CANCEL_INIT(&this->window, &this->cancel);

	OK_INIT(&this->window, &this->ok);

	snprintf(this->about_str, ABOUT_STR_LEN, "Usewood %s Built on %s", uv_projname, uv_datetime);
	this->about_str[ABOUT_STR_LEN - 1] = '\0';
	uv_uilabel_init(&this->about, &UI_FONT_SMALL, ALIGN_TOP_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), this->about_str);
	uv_uiwindow_add(&this->window, &this->about,
			uv_uibb(&this->window)->width / 2,
			uv_uibb(&this->window)->height - UI_FONT_SMALL.char_height - 2,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);


	uv_uitabwindow_init(&this->tabs, sizeof(tab_names) / sizeof(const char *),
			&uv_uistyles[0], this->tabs_buffer, tab_names);
	uv_uiwindow_add(&this->window, &this->tabs, 0, TOPIC_HEIGHT + 10,
			uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height - TOPIC_HEIGHT - 10 - uv_uibb(&this->about)->height - 12,
			uv_uitabwindow_step);

	// set the requested tab
	uv_uitabwindow_set_tab(&this->tabs, 0);
	system_settings_show();

}

void system_show_tab(void (*show_callb)(void)) {
	system_show();
	if (show_callb == system_settings_show) {
		uv_uitabwindow_set_tab(&this->tabs, 0);
	}
	else if (show_callb == system_network_show) {
		uv_uitabwindow_set_tab(&this->tabs, 1);
	}
	else if (show_callb == system_log_show) {
		uv_uitabwindow_set_tab(&this->tabs, 2);
	}
	else if (show_callb == system_restore_show) {
		uv_uitabwindow_set_tab(&this->tabs, 3);
	}
	else {
		return;
	}
	show_callb();
}



void system_step(uint16_t step_ms) {
	if (uv_uibutton_clicked(&this->ok)) {
		home_show();
	}
	else if (uv_uibutton_clicked(&this->cancel)) {
		home_show();
	}

	if (uv_uitabwindow_tab_changed(&this->tabs)) {
		if (uv_uitabwindow_tab(&this->tabs) == 0) {
			system_settings_show();
		}
		else if (uv_uitabwindow_tab(&this->tabs) == 1) {
			system_network_show();
		}
		else if (uv_uitabwindow_tab(&this->tabs) == 2) {
			system_log_show();
		}
		else if (uv_uitabwindow_tab(&this->tabs) == 3) {
			system_restore_show();
		}
	}

	if (uv_uitabwindow_tab(&this->tabs) == 0) {
		system_settings_step(step_ms);
	}
	else if (uv_uitabwindow_tab(&this->tabs) == 1) {
		system_network_step(step_ms);
	}
	else if (uv_uitabwindow_tab(&this->tabs) == 2) {
		system_log_step(step_ms);
	}
	else if (uv_uitabwindow_tab(&this->tabs) == 3) {
		system_restore_step(step_ms);
	}
}
