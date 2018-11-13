/*
 * taskbar.c
 *
 *  Created on: Sep 30, 2016
 *      Author: usevolt
 */


#include <esb.h>
#include "taskbar.h"
#include "gui.h"
#include "system.h"
#include "network.h"
#include "tr.h"

#define this (&gui.taskbar)


#define LEVEL_PB_WIDTH	30

#define WARNING_COLOR C(0x888800)
#define ERROR_COLOR C(0x880000)
#define WINDOW_COLOR C(0x111111)
#define PRESSED_COLOR CONFIG_UI_STYLE_ACTIVE_FG_C_1

#define BG_WARNING_DELAY_MS	1000
#define BG_ERROR_DELAY_MS	100

#define ENGINE_LIGHT_DELAY_MS			100

#define CLOCK_WIDTH			(UI_FONT_BIG.char_width * 5 + 5)
#define CAL_WIDTH			(UI_FONT_SMALL.char_width * 10 + 5)
#define CAL_HEIGHT			(UI_FONT_SMALL.char_height)

static void show(const taskbar_state_e state);



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
	uv_uiwindow_set_stepcallback(&this->taskbar, &taskbar_step);
	uv_uiwindow_set_transparent(this, false);
	uv_uidisplay_add(display, &this->taskbar,
			0, LCD_H(0.86f), LCD_W(1.0f), LCD_H(0.14f));
	this->log_count = log_get_nack_count();

	if (this->log_count == 0) {
		show(TASKBAR_NO_ALERTS);
	}
	else {
		show(TASKBAR_ALERTS);
	}

}


void taskbar_update_clock(void) {
	uv_delay_init(0, &this->delay);
}

static void show(const taskbar_state_e state) {

	this->state = state;
	uv_uiwindow_clear(&this->taskbar);
	taskbar_style.window_c = WINDOW_COLOR;

	if (state == TASKBAR_NO_ALERTS) {

		uv_uigridlayout_st grid;
		uv_uigridlayout_init(&grid, 0, 0, uv_uibb(&this->taskbar)->width - CLOCK_WIDTH,
				uv_uibb(&this->taskbar)->height, 12, 1);
		uv_uigridlayout_set_padding(&grid, 5, 0);
		uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

		uv_uidigit_init(&this->hours, &UI_FONT_SMALL, ALIGN_CENTER,
				C(0xFFFFFF), taskbar_style.window_c, "%u", dspl.hour_counter);
		uv_uiwindow_add(&this->taskbar, &this->hours, bb.x, bb.y, bb.width,
				bb.height - UI_FONT_SMALL.char_height);

		uv_uilabel_init(&this->hours_label, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER,
				C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_TASKBAR_LABELHOURS));
		uv_uiwindow_add(&this->taskbar, &this->hours_label,
				bb.x, bb.y, bb.width, bb.height);

		// kubota warning lights
		this->engine_visible = false;
		bb = uv_uigridlayout_next(&grid);
		uv_uigridlayout_st engine_grid;
		uv_uigridlayout_init(&engine_grid, bb.x, bb.y, bb.width, bb.height, 1, 4);
		bb = uv_uigridlayout_next(&engine_grid);
		uv_uilabel_init(&this->engine_water, &UI_FONT_SMALL, ALIGN_TOP_CENTER,
				C(0xFF0000), taskbar_style.window_c, uv_str(STR_TASKBAR_LABELWATER));
		uv_ui_set_enabled(&this->engine_water, false);
		uv_uiwindow_add(&this->taskbar, &this->engine_water, bb.x, bb.y,
				bb.width, bb.height);
		uv_delay_init(ENGINE_LIGHT_DELAY_MS, &this->engine_delay);

		bb = uv_uigridlayout_next(&engine_grid);
		uv_uilabel_init(&this->engine_oil_press, &UI_FONT_SMALL, ALIGN_CENTER,
				C(0xFF0000), taskbar_style.window_c, uv_str(STR_TASKBAR_LABELOILPRESS));
		uv_ui_set_enabled(&this->engine_oil_press, false);
		uv_uiwindow_add(&this->taskbar, &this->engine_oil_press, bb.x, bb.y,
				bb.width, bb.height);

		bb = uv_uigridlayout_next(&engine_grid);
		uv_uilabel_init(&this->engine_alt, &UI_FONT_SMALL, ALIGN_CENTER,
				C(0xFF0000), taskbar_style.window_c, uv_str(STR_TASKBAR_LABELALTERNATOR));
		uv_ui_set_enabled(&this->engine_alt, false);
		uv_uiwindow_add(&this->taskbar, &this->engine_alt, bb.x, bb.y,
				bb.width, bb.height);

		bb = uv_uigridlayout_next(&engine_grid);
		uv_uilabel_init(&this->engine_glow_plugs, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER,
				C(0xFFFF00), taskbar_style.window_c, uv_str(STR_TASKBAR_LABELGLOW));
		uv_ui_set_enabled(&this->engine_glow_plugs, false);
		uv_uiwindow_add(&this->taskbar, &this->engine_glow_plugs, bb.x, bb.y,
				bb.width, bb.height);


		// emcy stop
		bb = uv_uigridlayout_next(&grid);
		uv_uilabel_init(&this->emcy_stop, &UI_FONT_BIG, ALIGN_TOP_CENTER, C(0xFF0000),
				taskbar_style.window_c, "!");
		uv_uilabel_set_scale(&this->emcy_stop, 1.8f);
		uv_ui_set_enabled(&this->emcy_stop, false);
		uv_uiwindow_add(&this->taskbar, &this->emcy_stop, bb.x, bb.y, bb.width, 0);
		uv_uilabel_init(&this->emcy_label, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER,
				C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_TASKBAR_LABELEMCY));
		uv_ui_set_enabled(&this->emcy_label, false);
		uv_uiwindow_add(&this->taskbar, &this->emcy_label, bb.x, bb.y, bb.width, bb.height);
		uv_delay_init(BG_ERROR_DELAY_MS, &this->emcy_delay);

		// gear
		bb = uv_uigridlayout_next(&grid);
		uv_uidigit_init(&this->gear, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF),
				taskbar_style.window_c, "%u", ccu_get_gear(&dspl.network.ccu));
		uv_uiwindow_add(&this->taskbar, &this->gear, bb.x, bb.y, bb.width,
				bb.height - UI_FONT_SMALL.char_height);

		uv_uilabel_init(&this->gear_label, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
				C(0xFFFFFFFF), uv_str(STR_TASKBAR_LABELGEAR));
		uv_uiwindow_add(&this->taskbar, &this->gear_label, bb.x, bb.y + bb.height,
				bb.width, 0);

		uv_uitoucharea_init(&this->gear_touch);
		uv_uiwindow_add(&this->taskbar, &this->gear_touch, bb.x, bb.y,
				bb.width, bb.height);

		// horn
		bb = uv_uigridlayout_next(&grid);
		uv_uilabel_init(&this->horn, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF),
				taskbar_style.window_c, "Off");
		uv_uiwindow_add(&this->taskbar, &this->horn, bb.x, bb.y, bb.width,
				bb.height - UI_FONT_SMALL.char_height);

		uv_uilabel_init(&this->horn_label, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER,
				C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_TASKBAR_HORN));
		uv_uiwindow_add(&this->taskbar, &this->horn_label, bb.x, bb.y,
				bb.width, bb.height);

		uv_uitoucharea_init(&this->horn_touch);
		uv_uiwindow_add(&this->taskbar, &this->horn_touch, bb.x, bb.y,
				bb.width, bb.height);

		// wiper
		bb = uv_uigridlayout_next(&grid);
		uv_uidigit_init(&this->wiper, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF),
				taskbar_style.window_c, "%u", csb_get_wiper_speed(&dspl.network.csb));
		uv_uiwindow_add(&this->taskbar, &this->wiper, bb.x, bb.y, bb.width,
				bb.height - UI_FONT_SMALL.char_height);

		uv_uilabel_init(&this->wiper_label, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER,
				C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_TASKBAR_WIPER));
		uv_uiwindow_add(&this->taskbar, &this->wiper_label, bb.x, bb.y,
				bb.width, bb.height);

		uv_uitoucharea_init(&this->wiper_touch);
		uv_uiwindow_add(&this->taskbar, &this->wiper_touch, bb.x, bb.y,
				bb.width, bb.height);

		bb = uv_uigridlayout_next(&grid);
		uv_uidigit_init(&this->heat, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF),
			 taskbar_style.window_c, "%u", fsb_get_heater_speed(&dspl.network.fsb));
		uv_uiwindow_add(&this->taskbar, &this->heat, bb.x, bb.y, bb.width,
				bb.height - UI_FONT_SMALL.char_height);

		uv_uilabel_init(&this->heat_label, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER,
				C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_TASKBAR_HEAT));
		uv_uiwindow_add(&this->taskbar, &this->heat_label, bb.x, bb.y,
				bb.width, bb.height);

		uv_uitoucharea_init(&this->heat_touch);
		uv_uiwindow_add(&this->taskbar, &this->heat_touch, bb.x, bb.y,
				bb.width, bb.height);

		// voltage
		bb = uv_uigridlayout_next(&grid);
		uv_uiprogressbar_init(&this->voltage_level, VOLTAGE_MIN, VOLTAGE_MAX, &uv_uistyles[0]);
		uv_uiprogressbar_set_value(&this->voltage_level, esb_get_voltage(&dspl.network.esb));
		uv_uiprogressbar_set_vertical(&this->voltage_level);
		uv_uiprogressbar_set_limit(&this->voltage_level, UI_PROGRESSBAR_LIMIT_UNDER,
				VOLTAGE_WARNING_LIMIT, ERROR_COLOR);
		uv_uiprogressbar_set_title(&this->voltage_level, uv_str(STR_TASKBAR_BATV));
		uv_uiwindow_add(&this->taskbar, &this->voltage_level, bb.x, bb.y,
				bb.width, bb.height);

		// Fuel level
		bb = uv_uigridlayout_next(&grid);
		uv_uiprogressbar_init(&this->fuel_level, 0, 100, &uv_uistyles[0]);
		uv_uiprogressbar_set_value(&this->fuel_level, fsb_get_fuel_level(&dspl.network.fsb));
		uv_uiprogressbar_set_vertical(&this->fuel_level);
		uv_uiprogressbar_set_limit(&this->fuel_level, UI_PROGRESSBAR_LIMIT_UNDER,
				FUEL_LEVEL_WARNING_LIMIT, ERROR_COLOR);
		uv_uiprogressbar_set_title(&this->fuel_level, uv_str(STR_TASKBAR_FUELL));
		uv_uiwindow_add(&this->taskbar, &this->fuel_level, bb.x, bb.y,
				bb.width, bb.height);

		// Oil level
		bb = uv_uigridlayout_next(&grid);
		uv_uiprogressbar_init(&this->oil_level, 20, 100, &uv_uistyles[0]);
		uv_uiprogressbar_set_value(&this->oil_level, esb_get_oil_level(&dspl.network.esb));
		uv_uiprogressbar_set_vertical(&this->oil_level);
		uv_uiprogressbar_set_limit(&this->oil_level, UI_PROGRESSBAR_LIMIT_UNDER,
				OIL_LEVEL_WARNING_LIMIT, ERROR_COLOR);
		uv_uiprogressbar_set_title(&this->oil_level, uv_str(STR_TASKBAR_OILL));
		uv_uiwindow_add(&this->taskbar, &this->oil_level, bb.x, bb.y,
				bb.width, bb.height);

		// Oil temp
		bb = uv_uigridlayout_next(&grid);
		uv_uiprogressbar_init(&this->otemp_bar, 0, 100, &uv_uistyles[0]);
		uv_uiprogressbar_set_value(&this->otemp_bar, esb_get_oil_temp(&dspl.network.esb));
		uv_uiprogressbar_set_vertical(&this->otemp_bar);
		uv_uiprogressbar_set_limit(&this->otemp_bar, UI_PROGRESSBAR_LIMIT_OVER,
				OIL_TEMP_WARNING_LIMIT, ERROR_COLOR);
		uv_uiprogressbar_set_title(&this->otemp_bar, uv_str(STR_TASKBAR_OILT));
		uv_uiwindow_add(&this->taskbar, &this->otemp_bar, bb.x, bb.y,
				bb.width, bb.height);


		// Motor temp
		bb = uv_uigridlayout_next(&grid);
		uv_uiprogressbar_init(&this->mtemp_bar, 50, 100, &uv_uistyles[0]);
		uv_uiprogressbar_set_vertical(&this->mtemp_bar);
		uv_uiprogressbar_set_value(&this->mtemp_bar, esb_get_motor_temp(&dspl.network.esb));
		uv_uiprogressbar_set_limit(&this->mtemp_bar, UI_PROGRESSBAR_LIMIT_OVER,
				MOTOR_TEMP_WARNING_LIMIT, ERROR_COLOR);
		uv_uiprogressbar_set_title(&this->mtemp_bar, uv_str(STR_TASKBAR_MOTORT));
		uv_uiwindow_add(&this->taskbar, &this->mtemp_bar, bb.x, bb.y,
				bb.width, bb.height);


		uv_time_st t;
		uv_rtc_get_time(&t);
		snprintf(this->time, TASKBAR_TIME_LEN, "%02u:%02u", t.hour, t.min);
		uv_delay_init(1000 * 60, &this->delay);
		uv_uilabel_init(&this->clock, &UI_FONT_BIG, ALIGN_CENTER_RIGHT,
				C(0xFFFFFF), taskbar_style.window_c, this->time);
		uv_uiwindow_add(&this->taskbar, &this->clock,
				uv_uibb(&this->taskbar)->width - CLOCK_WIDTH, 0,
				CLOCK_WIDTH, uv_uibb(&this->taskbar)->height - CAL_HEIGHT);

		snprintf(this->date, TASKBAR_DATE_LEN, "%02u.%02u.%04u", t.day, t.month, t.year);
		uv_uilabel_init(&this->cal, &UI_FONT_SMALL, ALIGN_BOTTOM_RIGHT,
				C(0xFFFFFF), taskbar_style.window_c, this->date);
		uv_uiwindow_add(&this->taskbar, &this->cal,
				uv_uibb(&this->taskbar)->width - CAL_WIDTH, uv_uibb(&this->taskbar)->height - CAL_HEIGHT,
				CAL_WIDTH, CAL_HEIGHT);

	}
	else if (state == TASKBAR_ALERTS) {

		this->log_count = log_get_nack_count();


		uv_uitoucharea_init(&this->touch);
		uv_uiwindow_add(&this->taskbar, &this->touch, 0, 0,
				uv_uibb(&this->taskbar)->width, uv_uibb(&this->taskbar)->height);

		log_entry_st entry;
		log_get_nack(&entry, 0);
		const log_entry_def_st *def = log_entry_get_definition(entry.type);

		uv_delay_init((log_get_type(&entry) == LOG_WARNING) ?
				BG_WARNING_DELAY_MS : BG_ERROR_DELAY_MS,
				&this->bg_delay);

		uv_uilabel_init(&this->icon_label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), "!");
		uv_uilabel_set_scale(&this->icon_label, 2);
		uv_uiwindow_add(&this->taskbar, &this->icon_label, 0, 0,
				40, uv_uibb(&this->taskbar)->height);

		uv_uilabel_init(&this->info_label, &UI_FONT_SMALL, ALIGN_CENTER_LEFT, C(0xFFFFFF),
				C(0xFFFFFFFF), (char *) def->def);
		uv_uiwindow_add(&this->taskbar, &this->info_label, uv_uibb(&this->icon_label)->width, 0,
				uv_uibb(&this->taskbar)->width - 20 - 30, uv_uibb(&this->taskbar)->height);

		snprintf(this->count_str, TASKBAR_COUNT_STR_LEN, "1/%u", this->log_count);
		uv_uilabel_init(&this->count_label, &UI_FONT_SMALL, ALIGN_CENTER_RIGHT, C(0xFFFFFF),
				C(0xFFFFFFFF), this->count_str);
		uv_uiwindow_add(&this->taskbar, &this->count_label, uv_uibb(&this->taskbar)->width - 100,
				0, 100, uv_uibb(&this->taskbar)->height / 2);

		uv_uilabel_init(&this->click_label, &UI_FONT_SMALL, ALIGN_CENTER_RIGHT, C(0xFFFFFF),
				C(0xFFFFFFFF), (log_get_type(&entry) == LOG_WARNING) ?
						uv_str(STR_TASKBAR_CLICKTOCLOSE) : uv_str(STR_TASKBAR_CLICKTOLOG));
		uv_uiwindow_add(&this->taskbar, &this->click_label, uv_uibb(&this->taskbar)->width,
				uv_uibb(&this->taskbar)->height / 2, 0, uv_uibb(&this->taskbar)->height / 2);

	}
}

uv_uiobject_ret_e taskbar_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	if (this->state == TASKBAR_NO_ALERTS) {

		if (log_get_nack_count()) {
			show(TASKBAR_ALERTS);
			ret = UIOBJECT_RETURN_KILLED;
		}

		if (ret != UIOBJECT_RETURN_KILLED) {
			if (uv_delay(step_ms, &this->engine_delay)) {
				uv_delay_init(ENGINE_LIGHT_DELAY_MS, &this->engine_delay);
				if (fsb_get_ignkey_state(&dspl.network.fsb) == FSB_IGNKEY_STATE_OFF) {
					this->engine_visible = true;
				}
				else {
					this->engine_visible = !this->engine_visible;
				}
				uv_ui_set_enabled(&this->engine_water,
						esb_get_motor_water(&dspl.network.esb) ? this->engine_visible : false);
				uv_ui_set_enabled(&this->engine_oil_press,
						esb_get_motor_oil_press(&dspl.network.esb) ? this->engine_visible : false);
				uv_ui_set_enabled(&this->engine_alt,
						esb_get_alt_l(&dspl.network.esb) ? this->engine_visible : false);
				uv_ui_set_enabled(&this->engine_glow_plugs,
						(esb_get_glow_plugs(&dspl.network.esb) == OUTPUT_STATE_ON) ?
								this->engine_visible : false);
			}

			if (fsb_get_emcy(&dspl.network.fsb) ||
					!fsb_get_doorsw1(&dspl.network.fsb) ||
					!fsb_get_doorsw2(&dspl.network.fsb) ||
					!fsb_get_seatsw(&dspl.network.fsb)) {
				char *str;
				if (fsb_get_emcy(&dspl.network.fsb)) {
					str = uv_str(STR_TASKBAR_LABELEMCY);
				}
				else if (!fsb_get_doorsw1(&dspl.network.fsb) ||
						!fsb_get_doorsw2(&dspl.network.fsb)) {
					str = uv_str(STR_TASKBAR_LABELDOOR);
				}
				else if (!fsb_get_seatsw(&dspl.network.fsb)) {
					str = uv_str(STR_TASKBAR_LABELSEAT);
				}
				else {
					str = "";
				}
				uv_uilabel_set_text(&this->emcy_label, str);
				uv_ui_set_enabled(&this->emcy_label, true);
				if (uv_delay(step_ms, &this->emcy_delay)) {
					uv_delay_init(BG_ERROR_DELAY_MS, &this->emcy_delay);
					uv_ui_set_enabled(&this->emcy_stop, !uv_ui_get_enabled(&this->emcy_stop));
				}
			}
			else {
				uv_ui_set_enabled(&this->emcy_stop, false);
				uv_ui_set_enabled(&this->emcy_label, false);
				this->emcy_delay = 0;
			}

			if (uv_uitoucharea_clicked(&this->gear_touch, NULL, NULL)) {
				ccu_set_gear((ccu_get_gear(&dspl.network.ccu) + 1) % CCU_GEAR_COUNT);
			}
			uv_uidigit_set_value(&this->gear, ccu_get_gear(&dspl.network.ccu) + 1);

			if (uv_uitoucharea_pressed(&this->horn_touch, NULL, NULL)) {
				uv_uilabel_set_text(&this->horn, "On");
				uv_output_state_e value = OUTPUT_STATE_ON;
				uv_canopen_sdo_write(FSB_NODE_ID,
						FSB_HORN_STATUS_INDEX, FSB_HORN_STATUS_SUBINDEX,
						CANOPEN_TYPE_LEN(FSB_HORN_STATUS_TYPE), &value);
			}
			else if (uv_uitoucharea_clicked(&this->horn_touch, NULL, NULL) ||
					uv_uitoucharea_drag_released(&this->horn_touch, NULL, NULL)) {
				uv_output_state_e value = OUTPUT_STATE_OFF;
				uv_canopen_sdo_write(FSB_NODE_ID,
						FSB_HORN_STATUS_INDEX, FSB_HORN_STATUS_SUBINDEX,
						CANOPEN_TYPE_LEN(FSB_HORN_STATUS_TYPE), &value);
				uv_uilabel_set_text(&this->horn, "Off");
			}
			else if (uv_uitoucharea_pressed(&this->wiper_touch, NULL, NULL)) {
				uv_canopen_sdo_write8(CSB_NODE_ID, CSB_WIPER_REQ_INDEX,
						CSB_WIPER_REQ_SUBINDEX, 1);
			}
			else if (uv_uitoucharea_pressed(&this->heat_touch, NULL, NULL)) {
				uint8_t value = fsb_get_heater_speed(&dspl.network.fsb);
				if (value >= FSB_HEATER_MAX_SPEED) {
					value = 0;
				}
				else {
					uint8_t inc = ((FSB_HEATER_MAX_SPEED / 4) == 0) ?
							1 : (FSB_HEATER_MAX_SPEED / 4);
					value += inc;
				}
				fsb_set_heater_speed(&dspl.network.fsb, value);
			}


			uv_uidigit_set_value(&this->wiper,
					csb_get_wiper_speed(&dspl.network.csb));
			uv_uidigit_set_value(&this->heat,
					fsb_get_heater_speed(&dspl.network.fsb));
			uv_uiprogressbar_set_value(&this->voltage_level, esb_get_voltage(&dspl.network.esb));
			uv_uiprogressbar_set_value(&this->fuel_level, fsb_get_fuel_level(&dspl.network.fsb));
			uv_uiprogressbar_set_value(&this->oil_level, esb_get_oil_level(&dspl.network.esb));
			uv_uiprogressbar_set_value(&this->otemp_bar, esb_get_oil_temp(&dspl.network.esb));
			uv_uiprogressbar_set_value(&this->mtemp_bar, esb_get_motor_temp(&dspl.network.esb));

			if (uv_delay(step_ms, &this->delay)) {
				uv_time_st t;
				uv_rtc_get_time(&t);
				snprintf(this->time, TASKBAR_TIME_LEN,
						"%02u:%02u", t.hour, t.min);
				uv_ui_refresh(&this->clock);
				snprintf(this->date, TASKBAR_DATE_LEN,
						"%02u.%02u.%04u", t.day, t.month, t.year);
				uv_ui_refresh(&this->cal);
				uv_delay_init(100, &this->delay);
			}
		}
	}
	else {
		uint16_t c = log_get_nack_count();

		if (this->log_count != c || c == 0) {
			show(TASKBAR_NO_ALERTS);
			ret = UIOBJECT_RETURN_KILLED;
		}
		if (ret != UIOBJECT_RETURN_KILLED) {
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
			else if (uv_uitoucharea_drag_released(&this->touch, NULL, NULL)) {
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
					ret = UIOBJECT_RETURN_KILLED;
				}
				// error logs need to be acknowledged from the settings
				else {
					system_show_tab(system_log_show);
					show(TASKBAR_ALERTS);
					ret = UIOBJECT_RETURN_KILLED;
				}
			}
			else {

			}
		}
	}

	return ret;
}




