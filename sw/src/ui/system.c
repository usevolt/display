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
			uv_uibb(&this->window)->width / 2, uv_uibb(&this->window)->height - UI_FONT_SMALL.char_height - 2,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);

	// set time
	uv_rtc_get_time(&this->date);
	snprintf(this->datestr, DATE_STR_LEN, "%04u-%02u-%02u %02u:%02u:%02u",
			this->date.year, this->date.month, this->date.day, this->date.hour, this->date.min, this->date.sec);

	uv_uilabel_init(&this->time, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Date and time");
	uv_uiwindow_add(&this->window, &this->time,
			uv_uibb(&this->window)->width / 4 * 3, uv_uibb(&this->window)->height / 2 + 100,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uilabel_init(&this->date_label, &UI_FONT_BIG, ALIGN_CENTER_LEFT, C(0xFFFFFF),
			C(0xFFFFFFFF), this->datestr);
	uv_uiwindow_add(&this->window, &this->date_label,
			uv_uibb(&this->window)->width / 4 * 3 - UI_FONT_BIG.char_width * 10,
			uv_uibb(&this->window)->height / 2,
			0, 0, uv_uilabel_step);

	int16_t datex = uv_uibb(&this->date_label)->x;
	int16_t datey = uv_uibb(&this->date_label)->y;
	int16_t fw = UI_FONT_BIG.char_width;
	int16_t fh = UI_FONT_BIG.char_height;

	uv_uibutton_init(&this->sec_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->sec_inc,
			datex + fw * 17, datey - fh * 2 - 8,
			fw * 2, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->sec_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->sec_dec,
			datex + fw * 17, datey + fh / 2 + 8,
			fw * 2, fh * 1.5,
			uv_uibutton_step);

	uv_uibutton_init(&this->min_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->min_inc,
			datex + fw * 14, datey - fh * 2 - 8,
			fw * 2, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->min_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->min_dec,
			datex + fw * 14, datey + fh / 2 + 8,
			fw * 2, fh * 1.5,
			uv_uibutton_step);

	uv_uibutton_init(&this->hour_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->hour_inc,
			datex + fw * 11, datey - fh * 2 - 8,
			fw * 2, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->hour_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->hour_dec,
			datex + fw * 11, datey + fh / 2 + 8,
			fw * 2, fh * 1.5,
			uv_uibutton_step);

	uv_uibutton_init(&this->day_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->day_inc,
			datex + fw * 8, datey - fh * 2 - 8,
			fw * 2, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->day_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->day_dec,
			datex + fw * 8, datey + fh / 2 + 8,
			fw * 2, fh * 1.5,
			uv_uibutton_step);

	uv_uibutton_init(&this->month_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->month_inc,
			datex + fw * 5, datey - fh * 2 - 8,
			fw * 2, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->month_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->month_dec,
			datex + fw * 5, datey + fh / 2 + 8,
			fw * 2, fh * 1.5,
			uv_uibutton_step);

	uv_uibutton_init(&this->year_inc, "+", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->year_inc,
			datex, datey - fh * 2 - 8,
			fw * 4, fh * 1.5, uv_uibutton_step);
	uv_uibutton_init(&this->year_dec, "-", &uv_uistyles[DEFAULT_BUTTON_STYLE_INDEX]);
	uv_uiwindow_add(&this->window, &this->year_dec,
			datex, datey + fh / 2 + 8,
			fw * 4, fh * 1.5,
			uv_uibutton_step);

}


void system_step(uint16_t step_ms) {
	if (uv_uibutton_clicked(&this->ok)) {
		home_show();
	}
	else if (uv_uibutton_clicked(&this->cancel)) {
		home_show();
	}
}
