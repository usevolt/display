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


#define this (&gui.settings)


static void cancel_callb(void *me, uibutton_state_e state);
static void ok_callb(void *me, uibutton_state_e state);
static void brightness_callb(void *me, int16_t value);
static void volume_callb(void *me, int16_t value);

void settings_show() {
	uv_rtos_mutex_lock(&gui_mutex);

	uv_uiwindow_clear(&gui.main_window);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uiwindow_styles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_uibb(&gui.main_window)->width, uv_uibb(&gui.main_window)->height,
			uv_uiwindow_step);

	TOPIC_INIT(&this->window, &this->topic, "Settings");

	CANCEL_INIT(&this->window, &this->cancel, cancel_callb);

	OK_INIT(&this->window, &this->ok, ok_callb);

	uv_uiwindow_init(&this->general, this->general_buffer, &uv_uiwindow_styles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->general, 0, TOPIC_HEIGHT,
			uv_uibb(&this->window)->width, uv_uibb(&this->window)->height - TOPIC_HEIGHT,
			uv_uiwindow_step);

	// brightness
	uv_uilabel_init(&this->brightness_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), uv_uiwindow_styles[WINDOW_STYLE_INDEX].main_color, "Screen brightness");
	uv_uiwindow_add(&this->general, &this->brightness_label,
			uv_uibb(&this->general)->width/4, uv_uibb(&this->general)->height/2 + 100,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uislider_init(&this->brightness, 0, 100, gui_get_backlight(), &uv_uislider_styles[0], brightness_callb);
	uv_uislider_set_vertical(&this->brightness);
	uv_uiwindow_add(&this->general, &this->brightness,
			UI_ALIGN_CENTER(
					uv_uibb(&this->brightness_label)->x,
					uv_uibb(&this->brightness_label)->y - 110,
					50,
					200),
			uv_uislider_step);

	// volume
	uv_uilabel_init(&this->volume_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), uv_uiwindow_styles[WINDOW_STYLE_INDEX].main_color, "Volume");
	uv_uiwindow_add(&this->general, &this->volume_label,
			uv_uibb(&this->general)->width / 4 * 3, uv_uibb(&this->general)->height/2 + 100,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uislider_init(&this->volume, 0, 100, alert_get_volume(&dspl.alert), &uv_uislider_styles[0], volume_callb);
	uv_uislider_set_vertical(&this->volume);
	uv_uiwindow_add(&this->general, &this->volume,
			UI_ALIGN_CENTER(
					uv_uibb(&this->volume_label)->x,
					uv_uibb(&this->volume_label)->y - 110,
					50,
					200),
			uv_uislider_step);


	uv_rtos_mutex_unlock(&gui_mutex);
}



static void cancel_callb(void *me, uibutton_state_e state) {

}


static void ok_callb(void *me, uibutton_state_e state) {

}

static void brightness_callb(void *me, int16_t value) {

}

static void volume_callb(void *me, int16_t value) {

}
