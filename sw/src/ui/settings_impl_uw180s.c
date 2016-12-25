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

static void show_sliders(uw180s_state_e state, const char *label) {
	uv_uiwindow_clear(this->window);
	this->state = state;

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y, 3, 3);
	uv_uigridlayout_set_padding(&grid, 30, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->back, "Back", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, bb.x, bb.y, bb.width, BACK_H, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), (char *) label);
	uv_uiwindow_add(this->window, &this->label, bb.x, bb.y, bb.width, BACK_H, uv_uilabel_step);

	uv_uigridlayout_init(&grid, 0, uv_uibb(&this->back)->y + uv_uibb(&this->back)->height,
			uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - uv_uibb(&this->back)->y - uv_uibb(&this->back)->height,
			3, 1);
	uv_uigridlayout_set_padding(&grid, 30, 30);
	bb = uv_uigridlayout_next(&grid);

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
	uv_uislider_init(&this->max_speed_p, VALVE_MIN_CURRENT_MA,
			VALVE_MAX_CURRENT_MA, v->max_speed_p, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->max_speed_p);
	uv_uislider_set_title(&this->max_speed_p, "Max speed forward (ma)");
	uv_uiwindow_add(this->window, &this->max_speed_p, bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->max_speed_n, VALVE_MIN_CURRENT_MA,
			VALVE_MAX_CURRENT_MA, v->max_speed_n, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->max_speed_n);
	uv_uislider_set_title(&this->max_speed_n, "Max speed backward (ma)");
	uv_uiwindow_add(this->window, &this->max_speed_n, bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uitogglebutton_init(&this->invert, v->invert, "Invert", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->invert, bb.x + bb.width / 4, bb.y + bb.height / 4,
			bb.width / 2, bb.height / 2, uv_uitogglebutton_step);

}

void settings_impl_uw180s_show(void) {
	this->window = &gui.windows.settings.implements.window;
	uv_uiwindow_clear(this->window);
	this->state = UW180S_STATE_NONE;

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y, 3, 3);
	uv_uigridlayout_set_padding(&grid, 30, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->back, "Back", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, bb.x, bb.y, bb.width, BACK_H, uv_uibutton_step);
	bb = uv_uigridlayout_next(&grid);

	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), "UW180s");
	uv_uiwindow_add(this->window, &this->label, bb.x, bb.y, bb.width, BACK_H, uv_uilabel_step);
	uv_uigridlayout_next(&grid);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->wheels, "Wheels", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->wheels, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->wheels_feed, "Wheels feed", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->wheels_feed, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->delimbers, "Delimbers", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->delimbers, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->saw, "Saw", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->saw, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->tilt, "Tilt", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->tilt, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->rotator, "Rotator", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->rotator, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

}


void settings_impl_uw180s_step(uint16_t step_ms) {
	void (*set_params)(uint16_t,
			uint16_t, bool) = NULL;
	impl_valve_st *v = NULL;

	switch (this->state) {
	case UW180S_STATE_NONE:
		if (uv_uibutton_clicked(&this->wheels)) {
			show_sliders(UW180S_STATE_WHEELS, uv_uibutton_get_text(&this->wheels));
		}
		else if (uv_uibutton_clicked(&this->wheels_feed)) {
			show_sliders(UW180S_STATE_WHEELS_FEED, uv_uibutton_get_text(&this->wheels_feed));
		}
		else if (uv_uibutton_clicked(&this->delimbers)) {
			show_sliders(UW180S_STATE_DELIMBERS, uv_uibutton_get_text(&this->wheels_feed));
		}
		else if (uv_uibutton_clicked(&this->saw)) {
			show_sliders(UW180S_STATE_SAW, uv_uibutton_get_text(&this->saw));
		}
		else if (uv_uibutton_clicked(&this->tilt)) {
			show_sliders(UW180S_STATE_TILT, uv_uibutton_get_text(&this->tilt));
		}
		else if (uv_uibutton_clicked(&this->rotator)) {
			show_sliders(UW180S_STATE_ROTATOR, uv_uibutton_get_text(&this->rotator));
		}
		break;
	case UW180S_STATE_WHEELS:
		set_params = ecu_set_uw180s_wheels_params;
		v = &dspl.user->uw180s.wheels;
		break;
	case UW180S_STATE_WHEELS_FEED:
		set_params = ecu_set_uw180s_wheels_feed_params;
		v = &dspl.user->uw180s.wheels_feed;
		break;
	case UW180S_STATE_DELIMBERS:
		set_params = ecu_set_uw180s_delimbers_params;
		v = &dspl.user->uw180s.delimbers;
		break;
	case UW180S_STATE_SAW:
		set_params = ecu_set_uw180s_saw_params;
		v = &dspl.user->uw180s.saw;
		break;
	case UW180S_STATE_TILT:
		set_params = ecu_set_uw180s_tilt_params;
		v = &dspl.user->uw180s.tilt;
		break;
	case UW180S_STATE_ROTATOR:
		set_params = ecu_set_uw180s_rotator_params;
		v = &dspl.user->uw180s.rotator;
		break;
	default:
		break;
	}
	if (this->state != UW180S_STATE_NONE) {
		if (uv_uislider_value_changed(&this->max_speed_n) ||
				uv_uislider_value_changed(&this->max_speed_p) ||
				uv_uitogglebutton_clicked(&this->invert)) {
			// update local user settings
			if (v) {
				v->invert = uv_uitogglebutton_get_state(&this->invert);
				v->max_speed_p = uv_uislider_get_value(&this->max_speed_p);
				v->max_speed_n = uv_uislider_get_value(&this->max_speed_n);
			}
			// call ecu callback function
			if (set_params) {
				set_params(uv_uislider_get_value(&this->max_speed_p),
						uv_uislider_get_value(&this->max_speed_n),
						uv_uitogglebutton_get_state(&this->invert));
			}
		}

		if (uv_uibutton_clicked(&this->back)) {
			settings_impl_uw180s_show();
			return;
		}
	}
	else {
		if (uv_uibutton_clicked(&this->back)) {
			settings_implements_show();
			return;
		}
	}
}
