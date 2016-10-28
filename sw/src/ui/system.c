/*
 * system.c
 *
 *  Created on: Oct 28, 2016
 *      Author: usevolt
 */



#include "system.h"
#include "main.h"
#include "gui.h"

#define this (&gui.system)

static void cancel_callb(void *me, uibutton_state_e state);
static void ok_callb(void *me, uibutton_state_e state);


void system_show() {
	uv_rtos_mutex_lock(&gui_mutex);

	uv_uiwindow_clear(&gui.main_window);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uiwindow_styles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_uibb(&gui.main_window)->width, uv_uibb(&gui.main_window)->height,
			uv_uiwindow_step);

	TOPIC_INIT(&this->window, &this->topic, "System");

	CANCEL_INIT(&this->window, &this->cancel, cancel_callb);

	OK_INIT(&this->window, &this->ok, ok_callb);

	snprintf(this->about_str, ABOUT_STR_LEN, "Usewood %s Built on %s", uv_projname, uv_datetime);
	this->about_str[ABOUT_STR_LEN - 1] = '\0';
	uv_uilabel_init(&this->about, &UI_FONT_SMALL, ALIGN_TOP_CENTER,
			C(0xFFFFFF), uv_uiwindow_styles[WINDOW_STYLE_INDEX].main_color, this->about_str);
	uv_uiwindow_add(&this->window, &this->about,
			uv_uibb(&this->window)->width / 2, uv_uibb(&this->window)->height - UI_FONT_SMALL.char_height - 2,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_rtos_mutex_unlock(&gui_mutex);
}

static void cancel_callb(void *me, uibutton_state_e state) {

}

static void ok_callb(void *me, uibutton_state_e state) {

}
