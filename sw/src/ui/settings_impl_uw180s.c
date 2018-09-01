/*
 * settings_impl_uw180s.c
 *
 *  Created on: Dec 17, 2016
 *      Author: usevolt
 */


#include "settings_impl_uw180s.h"
#include "gui.h"
#include "tr.h"

#define this	(&gui.windows.settings.implements.uw180s)

#define BACK_H		50
#define BACK_W		150
#define BACK_Y		5
#define BACK_X		5

#define LABEL_H		BACK_H
#define LABEL_W		BACK_W
#define LABEL_Y		BACK_Y
#define LABEL_X		(uv_uibb(&gui.main_window)->width / 2 - LABEL_W / 2)


static void show_general() {
	uv_uiwindow_clear(this->window);
	this->state = UW180S_STATE_GENERAL;

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y + BACK_H, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y - BACK_H, 2, 1);
	uv_uigridlayout_set_padding(&grid, 10, 30);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->back, uv_str(STR_BACK), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, BACK_X, BACK_X, BACK_W, BACK_H);

	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF),
			uv_str(STR_SETTINGS_UW180S_LABELUW180SGENERAL));
	uv_uiwindow_add(this->window, &this->label, LABEL_X, LABEL_Y, LABEL_W, LABEL_H);

	uv_uislider_init(&this->general.rollers_grab_time, 0, 1000,
			dspl.user->uw180s.roller_grab_time, &uv_uistyles[0]);
	uv_uislider_set_inc_step(&this->general.rollers_grab_time, 20);
	uv_uislider_set_vertical(&this->general.rollers_grab_time);
	uv_uislider_set_title(&this->general.rollers_grab_time, uv_str(STR_SETTINGS_UW180S_SLIDERROLLERSGRABTIME));
	uv_uiwindow_add(this->window, &this->general.rollers_grab_time, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->general.blades_grab_time, 0, 1000,
			dspl.user->uw180s.blades_grab_time, &uv_uistyles[0]);
	uv_uislider_set_inc_step(&this->general.blades_grab_time, 20);
	uv_uislider_set_vertical(&this->general.blades_grab_time);
	uv_uislider_set_title(&this->general.blades_grab_time, uv_str(STR_SETTINGS_UW180S_SLIDERBLADESGRABTIME));
	uv_uiwindow_add(this->window, &this->general.blades_grab_time, bb.x, bb.y, bb.width, bb.height);

}

static void show_sliders(uw180s_state_e state, const char *label) {
	uv_uiwindow_clear(this->window);
	this->state = state;

	uv_uibutton_init(&this->back, uv_str(STR_BACK), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, BACK_X, BACK_Y, BACK_W, BACK_H);

	strcpy(this->sliders.str, "UW180s ");
	strcat(this->sliders.str, label);
	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), this->sliders.str);
	uv_uiwindow_add(this->window, &this->label, LABEL_X, LABEL_Y, LABEL_W, LABEL_H);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, uv_uibb(&this->back)->y + uv_uibb(&this->back)->height,
			uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - uv_uibb(&this->back)->y - uv_uibb(&this->back)->height,
			3, 2);
	uv_uigridlayout_set_padding(&grid, 5, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	valve_st *v;
	switch (state) {
	case UW180S_STATE_FEEDOPEN:
		v = &dspl.user->uw180s.feedopen;
		break;
	case UW180S_STATE_FEED:
		v = &dspl.user->uw180s.feed;
		break;
	case UW180S_STATE_BLADESOPEN:
		v = &dspl.user->uw180s.bladesopen;
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
	uv_uislider_set_inc_step(&this->sliders.max_speed_p, 10);
	uv_uislider_set_horizontal(&this->sliders.max_speed_p);
	uv_uislider_set_title(&this->sliders.max_speed_p, uv_str(STR_SETTINGS_VALVES_SLIDERFORMAXSPEED));
	uv_uiwindow_add(this->window, &this->sliders.max_speed_p, bb.x, bb.y,
			bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uitogglebutton_init(&this->sliders.invert, v->invert,
			uv_str(STR_SETTINGS_UW100_BUTTONINVERT), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->sliders.invert, bb.x + bb.width / 4,
			bb.y + bb.height + grid.vpadding / 2 - bb.width / 4,
			bb.width / 2, bb.width / 2);

	bb = uv_uigridlayout_next(&grid);
	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->sliders.max_speed_n, VALVE_MIN_CURRENT_MA,
			VALVE_MAX_CURRENT_MA, v->max_speed_n, &uv_uistyles[0]);
	uv_uislider_set_inc_step(&this->sliders.max_speed_n, 10);
	uv_uislider_set_horizontal(&this->sliders.max_speed_n);
	uv_uislider_set_title(&this->sliders.max_speed_n, uv_str(STR_SETTINGS_VALVES_SLIDERBACKMAXSPEED));
	uv_uiwindow_add(this->window, &this->sliders.max_speed_n, bb.x, bb.y,
			bb.width, bb.height);

}

static void show_valves(void) {
	uv_uiwindow_clear(this->window);
	this->state = UW180S_STATE_VALVES;

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y + BACK_H, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y - BACK_H, 3, 3);
	uv_uigridlayout_set_padding(&grid, 30, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->back, uv_str(STR_BACK), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, BACK_X, BACK_Y, BACK_W, BACK_H);

	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF),
			uv_str(STR_SETTINGS_UW180S_LABELVALVES));
	uv_uiwindow_add(this->window, &this->label, LABEL_X, LABEL_Y, LABEL_W, LABEL_H);

	uv_uibutton_init(&this->valves.wheels,
			uv_str(STR_SETTINGS_UW180S_BUTTONFEEDOPEN), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.wheels, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.wheels_feed,
			uv_str(STR_SETTINGS_UW180S_BUTTONFEED), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.wheels_feed, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.delimbers,
			uv_str(STR_SETTINGS_UW180S_BUTTONBLADESOPEN), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.delimbers, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.saw,
			uv_str(STR_SETTINGS_UW180S_BUTTONSAW), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.saw, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.tilt,
			uv_str(STR_SETTINGS_UW180S_BUTTONTILT), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.tilt, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.rotator,
			uv_str(STR_SETTINGS_UW180S_BUTTONROTATOR), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.rotator, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.allopen,
			uv_str(STR_SETTINGS_UW180S_BUTTONALLOPEN), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.allopen, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.impl1,
			uv_str(STR_SETTINGS_UW180S_BUTTONIMPL1), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.impl1, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->valves.impl2,
			uv_str(STR_SETTINGS_UW180S_BUTTONIMPL2), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->valves.impl2, bb.x, bb.y, bb.width, bb.height);
}



static void show_mb() {
	uv_uiwindow_clear(this->window);
	this->state = UW180S_STATE_MB;

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y + BACK_H, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y - BACK_H, 5, 1);
	uv_uigridlayout_set_padding(&grid, 10, 30);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->back, uv_str(STR_BACK), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, BACK_X, BACK_X, BACK_W, BACK_H);

	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_SETTINGS_UW180S_LABELMEAS));
	uv_uiwindow_add(this->window, &this->label, LABEL_X, LABEL_Y, LABEL_W, LABEL_H);

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
	uv_uislider_set_title(&this->mb.log_len1, uv_str(STR_SETTINGS_UW180S_SLIDERLOGLEN1));
	uv_uiwindow_add(this->window, &this->mb.log_len1, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->mb.log_len2, 0, 1000, dspl.user->uw180s.log_len2, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->mb.log_len2);
	uv_uislider_set_title(&this->mb.log_len2, uv_str(STR_SETTINGS_UW180S_SLIDERLOGLEN2));
	uv_uiwindow_add(this->window, &this->mb.log_len2, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->mb.len_calib, 0, UW180S_MB_LEN_CALIB_MAX,
			dspl.user->uw180s.len_calib, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->mb.len_calib);
	uv_uislider_set_title(&this->mb.len_calib, uv_str(STR_SETTINGS_UW180S_SLIDERLENCAL));
	uv_uiwindow_add(this->window, &this->mb.len_calib,
			bb.x, bb.y + 20, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
//	uv_uislider_init(&this->mb.vol_calib, UW180S_MB_VOL_CALIB_MIN, UW180S_MB_VOL_CALIB_MAX,
//			dspl.user->uw180s.vol_calib, &uv_uistyles[0]);
//	uv_uislider_set_vertical(&this->mb.vol_calib);
//	uv_uislider_set_title(&this->mb.vol_calib, uv_str(STR_SETTINGS_UW180S_SLIDERVOLCAL));
//	uv_uiwindow_add(this->window, &this->mb.vol_calib,
//			bb.x, bb.y + 20, bb.width, bb.height);

	uv_uilabel_init(&this->mb.info_label, &UI_FONT_SMALL, ALIGN_CENTER,
			C(0xFFFFFF), C(0xFFFFFFFF), uv_str(STR_SETTINGS_UW180S_LABELCALVALS));
	uv_uiwindow_add(this->window, &this->mb.info_label,
			uv_uibb(&this->mb.len_calib)->x, BACK_Y + BACK_H + 10,
			bb.x + bb.width - uv_uibb(&this->mb.len_calib)->x, 30);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->mb.vol_reset, uv_str(STR_SETTINGS_UW180S_BUTTONRESETVOL), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->mb.vol_reset,
			bb.x, bb.y, bb.width, bb.height);

}

void settings_impl_uw180s_show(void) {
	this->window = &gui.windows.settings.implements.window;
	uv_uiwindow_clear(this->window);
	this->state = UW180S_STATE_NONE;

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y + BACK_H, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y - BACK_H, 3, 1);
	uv_uigridlayout_set_padding(&grid, 30, 30);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), "UW180s");
	uv_uiwindow_add(this->window, &this->label, LABEL_X, LABEL_Y, LABEL_W, LABEL_H);

	uv_uibutton_init(&this->main.general, uv_str(STR_SETTINGS_UW180S_LABELGENERAL), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->main.general, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->main.measurement, uv_str(STR_SETTINGS_UW180S_LABELLOGMEAS), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->main.measurement, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->main.valves, uv_str(STR_SETTINGS_UW180S_LABELVALVECONFS), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->main.valves, bb.x, bb.y, bb.width, bb.height);

}


uv_uiobject_ret_e settings_impl_uw180s_step(uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	valve_st *v;

	switch (this->state) {
	case UW180S_STATE_FEEDOPEN:
		v = &dspl.user->uw180s.feedopen;
		break;
	case UW180S_STATE_FEED:
		v = &dspl.user->uw180s.feed;
		break;
	case UW180S_STATE_BLADESOPEN:
		v = &dspl.user->uw180s.bladesopen;
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
	case UW180S_STATE_ALLOPEN:
		v = &dspl.user->uw180s.all_open;
		break;
	case UW180S_STATE_IMPL1:
		v = &dspl.user->uw180s.impl1;
		break;
	case UW180S_STATE_IMPL2:
		v = &dspl.user->uw180s.impl2;
		break;
	default:
		v = NULL;
		break;
	}
	if (this->state == UW180S_STATE_VALVES) {
		if (uv_uibutton_clicked(&this->valves.wheels)) {
			show_sliders(UW180S_STATE_FEEDOPEN, uv_uibutton_get_text(&this->valves.wheels));
		}
		else if (uv_uibutton_clicked(&this->valves.wheels_feed)) {
			show_sliders(UW180S_STATE_FEED, uv_uibutton_get_text(&this->valves.wheels_feed));
		}
		else if (uv_uibutton_clicked(&this->valves.delimbers)) {
			show_sliders(UW180S_STATE_BLADESOPEN, uv_uibutton_get_text(&this->valves.delimbers));
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
		else if (uv_uibutton_clicked(&this->valves.allopen)) {
			show_sliders(UW180S_STATE_ALLOPEN, uv_uibutton_get_text(&this->valves.allopen));
		}
		else if (uv_uibutton_clicked(&this->valves.impl1)) {
			show_sliders(UW180S_STATE_IMPL1, uv_uibutton_get_text(&this->valves.impl1));
		}
		else if (uv_uibutton_clicked(&this->valves.impl2)) {
			show_sliders(UW180S_STATE_IMPL2, uv_uibutton_get_text(&this->valves.impl2));
		}
		else if (uv_uibutton_clicked(&this->back)) {
			settings_impl_uw180s_show();
		}
		else {

		}
	}
	else if (this->state > UW180S_STATE_VALVES) {
		if (uv_uislider_value_changed(&this->sliders.max_speed_n) ||
				uv_uislider_value_changed(&this->sliders.max_speed_p) ||
				uv_uitogglebutton_clicked(&this->sliders.invert)) {
			// call ecu callback function
			if (v != NULL) {
				v->setter(v);
			}
		}
		if (uv_uibutton_clicked(&this->back)) {
			show_valves();
			ret = UIOBJECT_RETURN_KILLED;
		}
	}
	else if (this->state == UW180S_STATE_MB) {
		if (uv_uibutton_clicked(&this->back)) {
			settings_impl_uw180s_show();
		}
		else if (uv_uislider_value_changed(&this->mb.len_calib)) {
			icu_set_len_calib(&dspl.network.icu, uv_uislider_get_value(&this->mb.len_calib));
		}
		else if (uv_uislider_value_changed(&this->mb.log_len1)) {
			dspl.user->uw180s.log_len1 = uv_uislider_get_value(&this->mb.log_len1);
		}
		else if (uv_uislider_value_changed(&this->mb.log_len2)) {
			dspl.user->uw180s.log_len2 = uv_uislider_get_value(&this->mb.log_len2);
		}
		else if (uv_uibutton_clicked(&this->mb.vol_reset)) {
			uv_canopen_sdo_write32(ICU_NODE_ID, ICU_VOL_DM3_INDEX,
					ICU_VOL_DM3_SUBINDEX, 0);
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
	else if (this->state == UW180S_STATE_GENERAL) {
		if (uv_uislider_value_changed(&this->general.rollers_grab_time)) {
			icu_set_feed_grab_time(&dspl.network.icu,
					uv_uislider_get_value(&this->general.rollers_grab_time));
		}
		else if (uv_uislider_value_changed(&this->general.blades_grab_time)) {
			icu_set_blades_grab_time(&dspl.network.icu,
					uv_uislider_get_value(&this->general.blades_grab_time));
		}
		else if (uv_uibutton_clicked(&this->back)) {
			settings_impl_uw180s_show();
			ret = UIOBJECT_RETURN_KILLED;
		}
		else {

		}
	}
	else {
		if (uv_uibutton_clicked(&this->main.general)) {
			show_general();
			ret = UIOBJECT_RETURN_KILLED;
		}
		else if (uv_uibutton_clicked(&this->main.measurement)) {
			show_mb();
			ret = UIOBJECT_RETURN_KILLED;
		}
		else if (uv_uibutton_clicked(&this->main.valves)) {
			show_valves();
			ret = UIOBJECT_RETURN_KILLED;
		}
		else {

		}
	}
	return ret;
}
