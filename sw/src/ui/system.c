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
		"Network\nDiagnostics",
		"Log",
		"System\nCalibration",
		"System\nRestore"
};


void system_show(void) {

	uv_uiwindow_clear(&gui.main_window);


	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_set_stepcallback(&this->window, &system_step);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_uibb(&gui.main_window)->width, uv_uibb(&gui.main_window)->height);

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
			0, UI_FONT_SMALL.char_height);


	uv_uitabwindow_init(&this->tabs, sizeof(tab_names) / sizeof(const char *),
			&uv_uistyles[0], this->tabs_buffer, tab_names);


	uv_uiwindow_add(&this->window, &this->tabs, 0, TOPIC_HEIGHT + 10,
			uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height - TOPIC_HEIGHT - 10 - UI_FONT_SMALL.char_height - 10);

	// set the requested tab
	uv_uitabwindow_set_tab(&this->tabs, 0);
	system_network_show();

}

void system_show_tab(void (*show_callb)(void)) {
	system_show();
	if (show_callb == system_network_show) {
		uv_uitabwindow_set_tab(&this->tabs, 0);
	}
	else if (show_callb == system_log_show) {
		uv_uitabwindow_set_tab(&this->tabs, 1);
	}
	else if (show_callb == system_calib_show) {
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



uv_uiobject_ret_e system_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	if (uv_uibutton_clicked(&this->ok)) {
		uv_memory_save();
		home_show();
		ret = UIOBJECT_RETURN_KILLED;
	}
	else if (uv_uibutton_clicked(&this->cancel)) {
		home_show();
		ret = UIOBJECT_RETURN_KILLED;
	}
	else {

	}

	if ((ret != UIOBJECT_RETURN_KILLED) && uv_uitabwindow_tab_changed(&this->tabs)) {
		if (uv_uitabwindow_tab(&this->tabs) == 0) {
			system_network_show();
			ret = UIOBJECT_RETURN_KILLED;
		}
		else if (uv_uitabwindow_tab(&this->tabs) == 1) {
			system_log_show();
			ret = UIOBJECT_RETURN_KILLED;
		}
		else if (uv_uitabwindow_tab(&this->tabs) == 2) {
			system_calib_show();
			ret = UIOBJECT_RETURN_KILLED;
		}
		else if (uv_uitabwindow_tab(&this->tabs) == 3) {
			system_restore_show();
			ret = UIOBJECT_RETURN_KILLED;
		}
		else {

		}
	}
	if (ret == UIOBJECT_RETURN_KILLED) {
		// stop keypad calibrations if they are ongoing
		if (keypad_get_calib_on(&dspl.network.l_keypad)) {
			keypad_calib_end(&dspl.network.l_keypad);
		}
		if (keypad_get_calib_on(&dspl.network.r_keypad)) {
			keypad_calib_end(&dspl.network.r_keypad);
		}
	}

	return ret;
}
