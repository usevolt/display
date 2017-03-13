/*
 * settings_impl_uw180s.c
 *
 *  Created on: Dec 17, 2016
 *      Author: usevolt
 */


#include "settings_impl_uw180s.h"
#include "gui.h"

#define this	(&gui.windows.settings.implements.uw180s)

#define BACK_H		50
#define BACK_W		200
#define BACK_Y		5
#define BACK_X		5

#define LABEL_H		BACK_H
#define LABEL_W		BACK_W
#define LABEL_Y		BACK_Y
#define LABEL_X		(LCD_W(0.5f) - LABEL_W / 2)

static void show_sliders(uw180s_state_e state, const char *label) {
	uv_uiwindow_clear(this->window);
	this->state = state;

	uv_uibutton_init(&this->back, "Back", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, BACK_X, BACK_Y, BACK_W, BACK_H, uv_uibutton_step);

	strcpy(this->sliders.str, "UW180s ");
	strcat(this->sliders.str, label);
	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), this->sliders.str);
	uv_uiwindow_add(this->window, &this->label, LABEL_X, LABEL_Y, LABEL_W, LABEL_H, uv_uilabel_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, uv_uibb(&this->back)->y + uv_uibb(&this->back)->height,
			uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - uv_uibb(&this->back)->y - uv_uibb(&this->back)->height,
			3, 2);
	uv_uigridlayout_set_padding(&grid, 5, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	impl_valve_st *v;
	switch (state) {
	case UW180S_STATE_WHEELS:
		v = &dspl.user->uw180s.wheels;
		break;
	case UW180S_STATE_WHEELS_FEED:
		v = &dspl.user->uw180s.wheels_feed;
		break;
	case UW180S_STATE_DELIMBERS:
		v = &dspl.user->uw180s.delimbers;
		break;
	case UW180S_STATE_SAW:
		v = &dspl.user->uw180s.saw;
		break;
	case UW180S_STATE_TILT:
		v = &dspl.user->uw180s.tilt;
		break;
	case UW180S_STATE_ROTATOR:
		v = &dspl.user->uw180s.rotator;
		break;
	default:
		v = NULL;
		break;
	}

	bb = uv_uigridlayout_next(&grid);

	uv_uislider_init(&this->sliders.max_speed_p, VALVE_MIN_CURRENT_MA,
			VALVE_MAX_CURRENT_MA, v->max_speed_p, &uv_uistyles[0]);
	uv_uislider_set_horizontal(&this->sliders.max_speed_p);
	uv_uislider_set_title(&this->sliders.max_speed_p, "Max speed forward (ma)");
	uv_uiwindow_add(this->window, &this->sliders.max_speed_p, bb.x, bb.y,
			bb.width, bb.height, uv_uislider_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uitogglebutton_init(&this->sliders.invert, v->invert, "Invert", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->sliders.invert, bb.x + bb.width / 4,
			bb.y + bb.height + grid.vpadding / 2 - bb.width / 4,
			bb.width / 2, bb.width / 2, uv_uitogglebutton_step);

	bb = uv_uigridlayout_next(&grid);
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->sliders.max_speed_n, VALVE_MIN_CURRENT_MA,
			VALVE_MAX_CURRENT_MA, v->max_speed_n, &uv_uistyles[0]);
	uv_uislider_set_horizontal(&this->sliders.max_speed_n);
	uv_uislider_set_title(&this->sliders.max_speed_n, "Max speed backward (ma)");
	uv_uiwindow_add(this->window, &this->sliders.max_speed_n, bb.x, bb.y,
			bb.width, bb.height, uv_uislider_step);

}

static void show_valves(void) {
	uv_uiwindow_clear(this->window);
	this->state = UW180S_STATE_VALVES;

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y + BACK_H, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y - BACK_H, 3, 2);
	uv_uigridlayout_set_padding(&grid, 30, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->back, "Back", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, BACK_X, BACK_Y, BACK_W, BACK_H, uv_uibutton_step);

	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), "UW180s valves");
	uv_uiwindow_add(this->window, &this->label, LABEL_X, LABEL_Y, LABEL_W, LABEL_H, uv_uilabel_step);

	uv_uibutton_init(&this->valves.wheels, "Wheels", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.wheels, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.wheels_feed, "Wheels feed", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.wheels_feed, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.delimbers, "Delimbers", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.delimbers, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.saw, "Saw", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.saw, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.tilt, "Tilt", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.tilt, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.rotator, "Rotator", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.rotator, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);
}


static char *log_names[LOG_TYPE_COUNT];


static void show_mb() {
	uv_uiwindow_clear(this->window);
	this->state = UW180S_STATE_MB;

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y + BACK_H, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y - BACK_H, 5, 1);
	uv_uigridlayout_set_padding(&grid, 10, 30);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->back, "Back", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, BACK_X, BACK_X,
			BACK_W, BACK_H, uv_uibutton_step);

	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "UW180s Measurement");
	uv_uiwindow_add(this->window, &this->label, LABEL_X, LABEL_Y,
			LABEL_W, LABEL_H, uv_uilabel_step);

	uv_uitogglebutton_init(&this->mb.enabled,
			dspl.user->uw180s.mb_enabled, "Enabled", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->mb.enabled, LCD_W_PX - BACK_W - BACK_X,
			BACK_Y, BACK_W, BACK_H, uv_uitogglebutton_step);

//	for (int i = 0; i < LOG_TYPE_COUNT; i++) {
//		log_names[i] = dspl.user->uw180s.log_type_buffer[i].name;
//	}
//	uv_uilist_init(&this->mb.logs, log_names,
//			uv_vector_size(&dspl.user->uw180s.log_types), &uv_uistyles[0]);
//	uv_uiwindow_add(this->window, &this->mb.logs, bb.x, bb.y,
//			bb.width * 2, bb.height, uv_uilist_step);
//
//
//	bb = uv_uigridlayout_next(&grid);
//	bb = uv_uigridlayout_next(&grid);
//	uv_uibutton_init(&this->mb.log_add, "Add Log", &uv_uistyles[0]);
//	uv_uiwindow_add(this->window, &this->mb.log_add, bb.x, bb.y,
//			bb.width, bb.height / 2 - 10, uv_uibutton_step);
//
//	uv_uibutton_init(&this->mb.log_del, "Delete Log", &uv_uistyles[0]);
//	uv_uiwindow_add(this->window, &this->mb.log_del, bb.x, bb.y + bb.height / 2 + 10,
//			bb.width, bb.height / 2 - 10, uv_uibutton_step);

	uv_uislider_init(&this->mb.log_len1, 0, 1000, dspl.user->uw180s.log_len1, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->mb.log_len1);
	uv_uislider_set_title(&this->mb.log_len1, "Log length 1");
	uv_uiwindow_add(this->window, &this->mb.log_len1, bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->mb.log_len2, 0, 1000, dspl.user->uw180s.log_len2, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->mb.log_len2);
	uv_uislider_set_title(&this->mb.log_len2, "Log length 2");
	uv_uiwindow_add(this->window, &this->mb.log_len2, bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->mb.len_calib, 0, UW180S_MB_LEN_CALIB_MAX,
			dspl.user->uw180s.len_calib, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->mb.len_calib);
	uv_uislider_set_title(&this->mb.len_calib, "Length\nCalibration");
	uv_uiwindow_add(this->window, &this->mb.len_calib,
			bb.x, bb.y + 20, bb.width, bb.height, uv_uislider_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->mb.vol_calib, UW180S_MB_VOL_CALIB_MIN, UW180S_MB_VOL_CALIB_MAX,
			dspl.user->uw180s.vol_calib, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->mb.vol_calib);
	uv_uislider_set_title(&this->mb.vol_calib, "Volume\nCalibration");
	uv_uiwindow_add(this->window, &this->mb.vol_calib,
			bb.x, bb.y + 20, bb.width, bb.height, uv_uislider_step);

	uv_uilabel_init(&this->mb.info_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), "Note: Calibration values are\n"
			"shared across all users");
	uv_uiwindow_add(this->window, &this->mb.info_label,
			uv_uibb(&this->mb.len_calib)->x, BACK_Y + BACK_H + 10,
			bb.x + bb.width - uv_uibb(&this->mb.len_calib)->x, 30, uv_uilabel_step);

}

void settings_impl_uw180s_show(void) {
	this->window = &gui.windows.settings.implements.window;
	uv_uiwindow_clear(this->window);
	this->state = UW180S_STATE_NONE;

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y + BACK_H, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y - BACK_H, 2, 1);
	uv_uigridlayout_set_padding(&grid, 60, 60);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);


	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), "UW180s");
	uv_uiwindow_add(this->window, &this->label, LABEL_X, LABEL_Y, LABEL_W, LABEL_H, uv_uilabel_step);

	uv_uibutton_init(&this->main.measurement, "Log\nMeasurement", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->main.measurement, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->main.valves, "Valve\nConfigurations", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->main.valves, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

}


void settings_impl_uw180s_step(uint16_t step_ms) {
	void (*set_params)(uint16_t,
			uint16_t, bool) = NULL;

	switch (this->state) {
	case UW180S_STATE_NONE:
		break;
	case UW180S_STATE_VALVES:
		if (uv_uibutton_clicked(&this->valves.wheels)) {
			show_sliders(UW180S_STATE_WHEELS, uv_uibutton_get_text(&this->valves.wheels));
		}
		else if (uv_uibutton_clicked(&this->valves.wheels_feed)) {
			show_sliders(UW180S_STATE_WHEELS_FEED, uv_uibutton_get_text(&this->valves.wheels_feed));
		}
		else if (uv_uibutton_clicked(&this->valves.delimbers)) {
			show_sliders(UW180S_STATE_DELIMBERS, uv_uibutton_get_text(&this->valves.delimbers));
		}
		else if (uv_uibutton_clicked(&this->valves.saw)) {
			show_sliders(UW180S_STATE_SAW, uv_uibutton_get_text(&this->valves.saw));
		}
		else if (uv_uibutton_clicked(&this->valves.tilt)) {
			show_sliders(UW180S_STATE_TILT, uv_uibutton_get_text(&this->valves.tilt));
		}
		else if (uv_uibutton_clicked(&this->valves.rotator)) {
			show_sliders(UW180S_STATE_ROTATOR, uv_uibutton_get_text(&this->valves.rotator));
		}
		break;
	case UW180S_STATE_WHEELS:
		set_params = ecu_set_uw180s_wheels_params;
		break;
	case UW180S_STATE_WHEELS_FEED:
		set_params = ecu_set_uw180s_wheels_feed_params;
		break;
	case UW180S_STATE_DELIMBERS:
		set_params = ecu_set_uw180s_delimbers_params;
		break;
	case UW180S_STATE_SAW:
		set_params = ecu_set_uw180s_saw_params;
		break;
	case UW180S_STATE_TILT:
		set_params = ecu_set_uw180s_tilt_params;
		break;
	case UW180S_STATE_ROTATOR:
		set_params = ecu_set_uw180s_rotator_params;
		break;
	default:
		break;
	}
	if (this->state > UW180S_STATE_VALVES) {
		if (uv_uislider_value_changed(&this->sliders.max_speed_n) ||
				uv_uislider_value_changed(&this->sliders.max_speed_p) ||
				uv_uitogglebutton_clicked(&this->sliders.invert)) {
			// call ecu callback function
			if (set_params) {
				set_params(uv_uislider_get_value(&this->sliders.max_speed_p),
						uv_uislider_get_value(&this->sliders.max_speed_n),
						uv_uitogglebutton_get_state(&this->sliders.invert));
			}
		}
		if (uv_uibutton_clicked(&this->back)) {
			show_valves();
			return;
		}
	}
	else if (this->state == UW180S_STATE_VALVES) {
		if (uv_uibutton_clicked(&this->back)) {
			settings_impl_uw180s_show();
		}
	}
	else if (this->state == UW180S_STATE_MB) {
		if (uv_uibutton_clicked(&this->back)) {
			settings_impl_uw180s_show();
		}
		else if (uv_uitogglebutton_clicked(&this->mb.enabled)) {
			dspl.user->uw180s.mb_enabled = uv_uitogglebutton_get_state(&this->mb.enabled);
		}
		else if (uv_uislider_value_changed(&this->mb.len_calib)) {
			mb_set_length_calib(&dspl.network.uw180s_mb, uv_uislider_get_value(&this->mb.len_calib));
		}
		else if (uv_uislider_value_changed(&this->mb.vol_calib)) {
			mb_set_vol_calib(&dspl.network.uw180s_mb, uv_uislider_get_value(&this->mb.vol_calib));
		}
		else if (uv_uislider_value_changed(&this->mb.log_len1)) {
			dspl.user->uw180s.log_len1 = uv_uislider_get_value(&this->mb.log_len1);
		}
		else if (uv_uislider_value_changed(&this->mb.log_len2)) {
			dspl.user->uw180s.log_len2 = uv_uislider_get_value(&this->mb.log_len2);
		}
//		else if (uv_uibutton_clicked(&this->mb.log_add)) {
//			if (uv_vector_size(&dspl.user->uw180s.log_types) <
//					uv_vector_max_size(&dspl.user->uw180s.log_types)) {
//				if (uv_uikeyboard_show("Add new log type",
//						((log_type_st*) uv_vector_at(&dspl.user->uw180s.log_types,
//								uv_vector_size(&dspl.user->uw180s.log_types) + 1))->name,
//						LOG_NAME_LEN, &uv_uistyles[0])) {
//					uv_vector_push_back(&dspl.user->uw180s.log_types, NULL);
//					uv_uilist_push_back(&this->mb.logs,
//							((log_type_st*) uv_vector_at(&dspl.user->uw180s.log_types))->name);
//				}
//			}
//			else {
//				printf("Log count is at maximum\n");
//			}
//		}
	}
	else {
		if (uv_uibutton_clicked(&this->main.measurement)) {
			show_mb();
			return;
		}
		else if (uv_uibutton_clicked(&this->main.valves)) {
			show_valves();
			return;
		}
	}
}
