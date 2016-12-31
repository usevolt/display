/*
 * system_settings.c
 *
 *  Created on: Dec 29, 2016
 *      Author: usevolt
 */


#include "system_settings.h"
#include "gui.h"


#define this	(&gui.windows.system.windows.sys_settings)


static void update_time() {
	snprintf(this->datestr, DATE_STR_LEN, "%04u-%02u-%02u %02u:%02u:%02u",
			this->date.year, this->date.month, this->date.day,
			this->date.hour, this->date.min, this->date.sec);
	uv_ui_refresh(&this->date_label);
	uv_rtc_set_time(&this->date);
}


void system_settings_show(void) {
	uv_uiwindow_clear(&gui.windows.system.tabs);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_add(&gui.windows.system.tabs, &this->window, 0, CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uibb(&gui.windows.system.tabs)->width,
			uv_uibb(&gui.windows.system.tabs)->height - CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uiwindow_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0, uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height, 2, 1);
	uv_uigridlayout_set_padding(&grid, 10, 20);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	// engine power usage
	uv_uislider_init(&this->power_usage, 0, 100, ENGINE_POWER_USAGE, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->power_usage);
	uv_uislider_set_title(&this->power_usage, "Engine power\nusage");
	uv_uiwindow_add(&this->window, &this->power_usage, bb.x, bb.y, bb.width, bb.height,
			uv_uislider_step);

	// set time
	uv_rtc_get_time(&this->date);
	update_time();

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->time, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Date and time");
	uv_uiwindow_add(&this->window, &this->time,
			bb.x + bb.width / 2, bb.y + bb.height - 20,
			0, UI_FONT_SMALL.char_height, uv_uilabel_step);

	uv_uilabel_init(&this->date_label, &UI_FONT_BIG, ALIGN_CENTER_LEFT, C(0xFFFFFF),
			uv_uistyles[0].window_c, this->datestr);
	uv_uiwindow_add(&this->window, &this->date_label,
			bb.x + bb.width / 2 - UI_FONT_BIG.char_width * 10,
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




void system_settings_step(uint16_t step_ms) {
	if (uv_uislider_value_changed(&this->power_usage)) {
		dspl.user->engine_power_usage = uv_uislider_get_value(&this->power_usage);
		ecu_set_engine_power_usage(dspl.user->engine_power_usage);
	}
	else if (uv_uibutton_clicked(&this->year_inc)) {
		this->date.year++;
		update_time();
	}
	else if (uv_uibutton_clicked(&this->year_dec)) {
		this->date.year--;
		update_time();
	}
	else if (uv_uibutton_clicked(&this->month_inc)) {
		this->date.month++;
		if (this->date.month > 12) { this->date.month = 1; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->month_dec)) {
		if (this->date.month > 1) { this->date.month--; }
		else { this->date.month = 12; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->day_inc)) {
		if (this->date.day == 31) { this->date.day = 1; }
		else { this->date.day++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->day_dec)) {
		if (this->date.day > 1) { this->date.day--; }
		else { this->date.day = 31; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->hour_inc)) {
		if (this->date.hour == 24) { this->date.hour = 0; }
		else { this->date.hour++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->hour_dec)) {
		if (this->date.hour == 0) { this->date.hour = 23; }
		else { this->date.hour--; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->min_inc)) {
		if (this->date.min == 59) { this->date.min = 0; }
		else { this->date.min++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->min_dec)) {
		if (this->date.min == 0) { this->date.min = 59; }
		else { this->date.min--; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->sec_inc)) {
		if (this->date.sec == 59) { this->date.sec = 0; }
		else { this->date.sec++; }
		update_time();
	}
	else if (uv_uibutton_clicked(&this->sec_dec)) {
		if (this->date.sec == 0) { this->date.sec = 59; }
		else { this->date.sec--; }
		update_time();
	}


}
