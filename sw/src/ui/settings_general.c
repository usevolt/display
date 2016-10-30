/*
 * settings_general.c
 *
 *  Created on: Oct 29, 2016
 *      Author: usevolt
 */


#include "settings_general.h"
#include "gui.h"


static void time_callb(void *me, uibutton_state_e state);
static void brightness_callb(void *me, int16_t value);
static void volume_callb(void *me, int16_t value);



void settings_general_show(settings_general_st *this, uv_uitabwindow_st *window) {
	// brightness
	uv_uilabel_init(&this->brightness_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Screen\n\rbrightness");
	uv_uiwindow_add(window, &this->brightness_label,
			uv_uibb(window)->width / 6, uv_uibb(window)->height/2 + 100,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uislider_init(&this->brightness, 0, 100, gui_get_backlight(), &uv_uistyles[0], brightness_callb);
	uv_uislider_set_vertical(&this->brightness);
	uv_uiwindow_add(window, &this->brightness,
			UI_ALIGN_CENTER(
					uv_uibb(&this->brightness_label)->x,
					uv_uibb(&this->brightness_label)->y - 110,
					50,
					200),
			uv_uislider_step);

	// volume
	uv_uilabel_init(&this->volume_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Volume");
	uv_uiwindow_add(window, &this->volume_label,
			uv_uibb(window)->width / 8 * 3, uv_uibb(window)->height/2 + 100,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uislider_init(&this->volume, 0, 100, alert_get_volume(&dspl.alert), &uv_uistyles[0], volume_callb);
	uv_uislider_set_vertical(&this->volume);
	uv_uiwindow_add(window, &this->volume,
			UI_ALIGN_CENTER(
					uv_uibb(&this->volume_label)->x,
					uv_uibb(&this->volume_label)->y - 110,
					50,
					200),
			uv_uislider_step);

	// set time
	uv_rtc_get_time(&this->date);
	snprintf(this->datestr, DATE_STR_LEN, "%04u-%02u-%02u %02u:%02u:%02u",
			this->date.year, this->date.month, this->date.day, this->date.hour, this->date.min, this->date.sec);

	uv_uilabel_init(&this->time, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Date and time");
	uv_uiwindow_add(window, &this->time,
			uv_uibb(window)->width / 4 * 3, uv_uibb(window)->height / 2 + 100,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uilabel_init(&this->date_label, &UI_FONT_BIG, ALIGN_CENTER_LEFT, C(0xFFFFFF),
			C(0xFFFFFFFF), this->datestr);
	uv_uiwindow_add(window, &this->date_label,
			uv_uibb(window)->width / 4 * 3 - UI_FONT_BIG.char_width * 10,
			uv_uibb(window)->height / 2,
			0, 0, uv_uilabel_step);

	int16_t datex = uv_uibb(&this->date_label)->x;
	int16_t datey = uv_uibb(&this->date_label)->y;
	int16_t fw = UI_FONT_BIG.char_width;
	int16_t fh = UI_FONT_BIG.char_height;

	uv_uibutton_init(&this->sec_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->sec_inc,
			datex + fw * 17, datey - fh * 2 - 8,
			fw * 2, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->sec_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->sec_dec,
			datex + fw * 17, datey + fh / 2 + 8,
			fw * 2, fh * 1.5,
			uv_uibutton_step);

	uv_uibutton_init(&this->min_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->min_inc,
			datex + fw * 14, datey - fh * 2 - 8,
			fw * 2, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->min_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->min_dec,
			datex + fw * 14, datey + fh / 2 + 8,
			fw * 2, fh * 1.5,
			uv_uibutton_step);

	uv_uibutton_init(&this->hour_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->hour_inc,
			datex + fw * 11, datey - fh * 2 - 8,
			fw * 2, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->hour_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->hour_dec,
			datex + fw * 11, datey + fh / 2 + 8,
			fw * 2, fh * 1.5,
			uv_uibutton_step);

	uv_uibutton_init(&this->day_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->day_inc,
			datex + fw * 8, datey - fh * 2 - 8,
			fw * 2, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->day_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->day_dec,
			datex + fw * 8, datey + fh / 2 + 8,
			fw * 2, fh * 1.5,
			uv_uibutton_step);

	uv_uibutton_init(&this->month_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->month_inc,
			datex + fw * 5, datey - fh * 2 - 8,
			fw * 2, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->month_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->month_dec,
			datex + fw * 5, datey + fh / 2 + 8,
			fw * 2, fh * 1.5,
			uv_uibutton_step);

	uv_uibutton_init(&this->year_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->year_inc,
			datex, datey - fh * 2 - 8,
			fw * 4, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->year_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX], time_callb);
	uv_uiwindow_add(window, &this->year_dec,
			datex, datey + fh / 2 + 8,
			fw * 4, fh * 1.5,
			uv_uibutton_step);

}


static void time_callb(void *me, uibutton_state_e state) {

}

static void brightness_callb(void *me, int16_t value) {

}

static void volume_callb(void *me, int16_t value) {

}

void settings_general_step(uint16_t step_ms) {

}
