/*
 * taskbar.c
 *
 *  Created on: Sep 30, 2016
 *      Author: usevolt
 */


#include "taskbar.h"
#include "gui.h"
#include "msb.h"
#include "system.h"

#define this (&gui.taskbar)


#define LEVEL_PB_WIDTH	30

#define WARNING_COLOR C(0x888800)
#define ERROR_COLOR C(0x880000)
#define WINDOW_COLOR C(0x111111)
#define PRESSED_COLOR CONFIG_UI_STYLE_ACTIVE_FG_C_1

#define BG_WARNING_DELAY_MS	1000
#define BG_ERROR_DELAY_MS	100

static void show(taskbar_state_e state);



static uv_uistyle_st taskbar_style = {
			.active_bg_c = C(0x001100),
			.active_fg_c = C(0x005500),
			.active_frame_c = C(0x228811),
			.active_font_c = C(0xFFFFFF),
			.inactive_bg_c = C(0x009900),
			.inactive_fg_c = C(0x000000),
			.inactive_frame_c = C(0x444444),
			.inactive_font_c = C(0x444444),
			.font = & UI_FONT_SMALL,
			.text_color = C(0xFFFFFF),
			.window_c = WINDOW_COLOR
};


void taskbar_init(uv_uidisplay_st *display) {
	uv_uiwindow_init(&this->taskbar, this->taskbar_buffer, &taskbar_style);
	uv_uidisplay_add(display, &this->taskbar,
			0, LCD_H(0.86f), LCD_W(1.0f), LCD_H(0.14f), uv_uiwindow_step);

	show(TASKBAR_NO_ALERTS);

}

static void show(taskbar_state_e state) {

	this->state = state;
	uv_uiwindow_clear(&this->taskbar);
	taskbar_style.window_c = WINDOW_COLOR;

	if (state == TASKBAR_NO_ALERTS) {
		snprintf(this->hour_str, TASKBAR_HOUR_STR_LEN, "%u hours", dspl.hour_counter);
		uv_uilabel_init(&this->hours, &UI_FONT_SMALL, ALIGN_BOTTOM_LEFT,
				C(0xFFFFFF), taskbar_style.window_c, this->hour_str);
		uv_uiwindow_add(&this->taskbar, &this->hours,
				0, 0, 100, uv_uibb(&this->taskbar)->height, uv_uilabel_step);

		uv_time_st t;
		uv_rtc_get_time(&t);
		snprintf(this->time, TASKBAR_TIME_LEN, "%02u:%02u", t.hour, t.min);
		uv_delay_init(100, &this->delay);
		uv_uilabel_init(&this->clock, &UI_FONT_BIG, ALIGN_CENTER_RIGHT,
				C(0xFFFFFF), taskbar_style.window_c, this->time);
		uv_uiwindow_add(&this->taskbar, &this->clock,
				uv_ui_get_bb(&this->taskbar)->width - UI_FONT_SMALL.char_width * 5, 0,
				UI_FONT_SMALL.char_width * 5,
				uv_ui_get_bb(&this->taskbar)->height, uv_uilabel_step);

		// Motor temp
		uv_uilabel_init(&this->mtemp, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
				C(0xFFFFFFFF), "Motor T");
		uv_uiwindow_add(&this->taskbar, &this->mtemp,
				uv_uibb(&this->clock)->x - uv_uibb(&this->clock)->width - LEVEL_PB_WIDTH - 30,
				uv_uibb(&this->taskbar)->height - UI_FONT_SMALL.char_height,
				LEVEL_PB_WIDTH,
				UI_FONT_SMALL.char_height,
				uv_uilabel_step);

		uv_uiprogressbar_init(&this->mtemp_bar, 50, 100, &uv_uistyles[0]);
		uv_uiprogressbar_set_vertical(&this->mtemp_bar);
		uv_uiprogressbar_set_value(&this->mtemp_bar, msb_get_motor_temp(&dspl.network.msb));
		uv_uiprogressbar_set_limit(&this->mtemp_bar, UI_PROGRESSBAR_LIMIT_OVER,
				MOTOR_TEMP_WARNING_LIMIT, ERROR_COLOR);
		uv_uiwindow_add(&this->taskbar, &this->mtemp_bar,
				uv_uibb(&this->mtemp)->x, 0,
				LEVEL_PB_WIDTH, uv_uibb(&this->mtemp)->y - 4, uv_uiprogressbar_step);

		// Oil temp
		uv_uilabel_init(&this->otemp, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
				C(0xFFFFFFFF), "Oil T");
		uv_uiwindow_add(&this->taskbar, &this->otemp,
				uv_uibb(&this->mtemp)->x - LEVEL_PB_WIDTH - 30,
				uv_uibb(&this->taskbar)->height - UI_FONT_SMALL.char_height,
				LEVEL_PB_WIDTH,
				UI_FONT_SMALL.char_height,
				uv_uilabel_step);

		uv_uiprogressbar_init(&this->otemp_bar, 0, 100, &uv_uistyles[0]);
		uv_uiprogressbar_set_value(&this->otemp_bar, msb_get_oil_temp(&dspl.network.msb));
		uv_uiprogressbar_set_vertical(&this->otemp_bar);
		uv_uiprogressbar_set_limit(&this->otemp_bar, UI_PROGRESSBAR_LIMIT_OVER,
				OIL_TEMP_WARNING_LIMIT, ERROR_COLOR);
		uv_uiwindow_add(&this->taskbar, &this->otemp_bar,
				uv_uibb(&this->otemp)->x, 0,
				LEVEL_PB_WIDTH, uv_uibb(&this->otemp)->y - 4, uv_uiprogressbar_step);

		// Oil level
		uv_uilabel_init(&this->oil, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
				C(0xFFFFFFFF), "Oil L");
		uv_uiwindow_add(&this->taskbar, &this->oil,
				uv_uibb(&this->otemp)->x - LEVEL_PB_WIDTH - 30,
				uv_uibb(&this->taskbar)->height - UI_FONT_SMALL.char_height,
				LEVEL_PB_WIDTH,
				UI_FONT_SMALL.char_height,
				uv_uilabel_step);

		uv_uiprogressbar_init(&this->oil_level, 20, 100, &uv_uistyles[0]);
		uv_uiprogressbar_set_value(&this->oil_level, msb_get_oil_level(&dspl.network.msb));
		uv_uiprogressbar_set_vertical(&this->oil_level);
		uv_uiprogressbar_set_limit(&this->oil_level, UI_PROGRESSBAR_LIMIT_UNDER,
				OIL_LEVEL_WARNING_LIMIT, ERROR_COLOR);
		uv_uiwindow_add(&this->taskbar, &this->oil_level,
				uv_uibb(&this->oil)->x, 0,
				LEVEL_PB_WIDTH, uv_uibb(&this->oil)->y - 4, uv_uiprogressbar_step);

		// Fuel level
		uv_uilabel_init(&this->fuel, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
				C(0xFFFFFFFF), "Fuel L");
		uv_uiwindow_add(&this->taskbar, &this->fuel,
				uv_uibb(&this->oil)->x - LEVEL_PB_WIDTH - 30,
				uv_uibb(&this->taskbar)->height - UI_FONT_SMALL.char_height,
				LEVEL_PB_WIDTH,
				UI_FONT_SMALL.char_height,
				uv_uilabel_step);

		uv_uiprogressbar_init(&this->fuel_level, 0, 100, &uv_uistyles[0]);
		uv_uiprogressbar_set_value(&this->fuel_level, msb_get_fuel_level(&dspl.network.msb));
		uv_uiprogressbar_set_vertical(&this->fuel_level);
		uv_uiprogressbar_set_limit(&this->fuel_level, UI_PROGRESSBAR_LIMIT_UNDER,
				FUEL_LEVEL_WARNING_LIMIT, ERROR_COLOR);
		uv_uiwindow_add(&this->taskbar, &this->fuel_level,
				uv_uibb(&this->fuel)->x, 0,
				LEVEL_PB_WIDTH, uv_uibb(&this->fuel)->y - 4, uv_uiprogressbar_step);

		// voltage
		uv_uilabel_init(&this->voltage, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
				C(0xFFFFFFFF), "Bat V");
		uv_uiwindow_add(&this->taskbar, &this->voltage,
				uv_uibb(&this->fuel)->x - LEVEL_PB_WIDTH - 30,
				uv_uibb(&this->taskbar)->height - UI_FONT_SMALL.char_height,
				LEVEL_PB_WIDTH,
				UI_FONT_SMALL.char_height,
				uv_uilabel_step);

		uv_uiprogressbar_init(&this->voltage_level, 0, 100, &uv_uistyles[0]);
		uv_uiprogressbar_set_value(&this->voltage_level, msb_get_voltage(&dspl.network.msb));
		uv_uiprogressbar_set_vertical(&this->voltage_level);
		uv_uiprogressbar_set_limit(&this->voltage_level, UI_PROGRESSBAR_LIMIT_UNDER,
				VOLTAGE_WARNING_LIMIT_MV, ERROR_COLOR);
		uv_uiwindow_add(&this->taskbar, &this->voltage_level,
				uv_uibb(&this->voltage)->x, 0,
				LEVEL_PB_WIDTH, uv_uibb(&this->voltage)->y - 4, uv_uiprogressbar_step);

	}
	else if (state == TASKBAR_ALERTS) {

		this->log_count = log_get_nack_count();


		uv_uitoucharea_init(&this->touch);
		uv_uiwindow_add(&this->taskbar, &this->touch, 0, 0,
				uv_uibb(&this->taskbar)->width, uv_uibb(&this->taskbar)->height,
				uv_uitoucharea_step);

		log_entry_st entry;
		log_get_nack(&entry, 0);
		const log_entry_def_st *def = log_entry_get_definition(entry.type);

		uv_delay_init((log_get_type(&entry) == LOG_WARNING) ?
				BG_WARNING_DELAY_MS : BG_ERROR_DELAY_MS,
				&this->bg_delay);

		uv_uilabel_init(&this->icon_label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), "!");
		uv_uilabel_set_scale(&this->icon_label, 2);
		uv_uiwindow_add(&this->taskbar, &this->icon_label, 0, 0,
				40, uv_uibb(&this->taskbar)->height, uv_uilabel_step);

		uv_uilabel_init(&this->info_label, &UI_FONT_SMALL, ALIGN_CENTER_LEFT, C(0xFFFFFF),
				C(0xFFFFFFFF), (char *) def->def);
		uv_uiwindow_add(&this->taskbar, &this->info_label, uv_uibb(&this->icon_label)->width, 0,
				uv_uibb(&this->taskbar)->width - 20 - 30, uv_uibb(&this->taskbar)->height,
				uv_uilabel_step);

		snprintf(this->count_str, TASKBAR_COUNT_STR_LEN, "1/%u", this->log_count);
		uv_uilabel_init(&this->count_label, &UI_FONT_SMALL, ALIGN_CENTER_RIGHT, C(0xFFFFFF),
				C(0xFFFFFFFF), this->count_str);
		uv_uiwindow_add(&this->taskbar, &this->count_label, uv_uibb(&this->taskbar)->width - 100,
				0, 100, uv_uibb(&this->taskbar)->height / 2, uv_uilabel_step);

		uv_uilabel_init(&this->click_label, &UI_FONT_SMALL, ALIGN_CENTER_RIGHT, C(0xFFFFFF),
				C(0xFFFFFFFF), (log_get_type(&entry) == LOG_WARNING) ?
						"Click to close" : "Click to go to the log");
		uv_uiwindow_add(&this->taskbar, &this->click_label, uv_uibb(&this->taskbar)->width,
				uv_uibb(&this->taskbar)->height / 2, 0, uv_uibb(&this->taskbar)->height / 2, uv_uilabel_step);

	}
}

void taskbar_step(uint16_t step_ms) {

	if (this->state == TASKBAR_NO_ALERTS) {

		if (log_get_nack_count()) {
			show(TASKBAR_ALERTS);
			return;
		}

		uv_uiprogressbar_set_value(&this->oil_level, msb_get_oil_level(&dspl.network.msb));
		uv_uiprogressbar_set_value(&this->otemp_bar, msb_get_oil_temp(&dspl.network.msb));
		uv_uiprogressbar_set_value(&this->fuel_level, msb_get_fuel_level(&dspl.network.msb));
		uv_uiprogressbar_set_value(&this->mtemp_bar, msb_get_motor_temp(&dspl.network.msb));

		if (uv_delay(step_ms, &this->delay)) {
			uv_time_st t;
			uv_rtc_get_time(&t);
			snprintf(this->time, TASKBAR_TIME_LEN,
					"%02u:%02u", t.hour, t.min);
			uv_ui_refresh(&this->clock);
			uv_delay_init(100, &this->delay);
		}
	}
	else {
		uint16_t c = log_get_nack_count();
		if (this->log_count != c || c == 0) {
			show(TASKBAR_NO_ALERTS);
			return;
		}
		this->log_count = c;

		log_entry_st entry;
		log_get_nack(&entry, 0);

		if (uv_delay(step_ms, &this->bg_delay)) {
			uv_delay_init((log_get_type(&entry) == LOG_WARNING) ?
					BG_WARNING_DELAY_MS : BG_ERROR_DELAY_MS, &this->bg_delay);
			if (taskbar_style.window_c != WARNING_COLOR &&
					taskbar_style.window_c != ERROR_COLOR) {
				taskbar_style.window_c = (log_get_type(&entry) == LOG_ERROR) ? ERROR_COLOR : WARNING_COLOR;
			}
			else {
				taskbar_style.window_c = WINDOW_COLOR;
			}
			uv_ui_refresh(&this->taskbar);
		}

		if (uv_uitoucharea_pressed(&this->touch, NULL, NULL)) {
			taskbar_style.window_c = PRESSED_COLOR;
			uv_delay_init((log_get_type(&entry) == LOG_WARNING) ?
					BG_WARNING_DELAY_MS : BG_ERROR_DELAY_MS, &this->bg_delay);
			uv_ui_refresh(&this->taskbar);
		}
		else if (uv_uitoucharea_is_down(&this->touch, NULL, NULL)) {
			taskbar_style.window_c = PRESSED_COLOR;
			uv_delay_init((log_get_type(&entry) == LOG_WARNING) ?
					BG_WARNING_DELAY_MS : BG_ERROR_DELAY_MS, &this->bg_delay);
		}
		else if (uv_uitoucharea_released(&this->touch, NULL, NULL)) {
			taskbar_style.window_c = WINDOW_COLOR;
			uv_ui_refresh(&this->taskbar);
		}
		else if (uv_uitoucharea_clicked(&this->touch, NULL, NULL)) {
			// warning logs can be acknowledged by clicking
			if (log_get_type(&entry) == LOG_WARNING) {
				log_ack(0);
				this->log_count = log_get_nack_count();
				if (this->log_count) {
					show(TASKBAR_ALERTS);
				}
				else {
					show(TASKBAR_NO_ALERTS);
				}
			}
			// error logs need to be acknowledged from the settings
			else {
				system_show_tab(system_log_show);
				show(TASKBAR_ALERTS);
			}
		}

	}

}




