/*
 * settings_impl_uw50.c
 *
 *  Created on: Dec 17, 2016
 *      Author: usevolt
 */

#include "settings_impl_uw50.h"
#include "gui.h"

#define this (&gui.windows.settings.implements.uw50)

#define BACK_H		50
#define BACK_W		200
#define BACK_Y		5
#define BACK_X		5


static void show_sliders(uw50_states_e state, char *label) {
	uv_uiwindow_clear(this->window);

	this->state = state;
	impl_valve_ext_st *v;
	if (state == UW50_STATE_SAW) { v = &dspl.user->uw50.saw; }
	else if (state == UW50_STATE_TILT) { v = &dspl.user->uw50.tilt; }
	else { v = NULL; }

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y, 3, 3);
	uv_uigridlayout_set_padding(&grid, 30, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->back, "Back", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, bb.x, bb.y, bb.width, BACK_H, uv_uibutton_step);
	bb = uv_uigridlayout_next(&grid);

	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), label);
	uv_uiwindow_add(this->window, &this->label, bb.x, bb.y, bb.width, BACK_H, uv_uilabel_step);
	uv_uigridlayout_next(&grid);

	uv_uigridlayout_init(&grid, 0, uv_uibb(&this->back)->y + uv_uibb(&this->back)->height,
			uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - uv_uibb(&this->back)->y - uv_uibb(&this->back)->height, 5, 1);
	uv_uigridlayout_set_padding(&grid, 20, 20);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->max_speed_p, VALVE_MIN_CURRENT_MA, VALVE_MAX_CURRENT_MA,
			v->max_speed_p, &uv_uistyles[0]);
	uv_uislider_set_inc_step(&this->max_speed_p, 10);
	uv_uislider_set_vertical(&this->max_speed_p);
	uv_uislider_set_title(&this->max_speed_p, "Max speed\nforward (ma)");
	uv_uiwindow_add(this->window, &this->max_speed_p, bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->max_speed_n, VALVE_MIN_CURRENT_MA, VALVE_MAX_CURRENT_MA,
			v->max_speed_n, &uv_uistyles[0]);
	uv_uislider_set_inc_step(&this->max_speed_n, 10);
	uv_uislider_set_vertical(&this->max_speed_n);
	uv_uislider_set_title(&this->max_speed_n, "Max speed\nforward (ma)");
	uv_uiwindow_add(this->window, &this->max_speed_n, bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->acc, 0, 100, v->acc, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->acc);
	uv_uislider_set_title(&this->acc, "Acceleration\n(%)");
	uv_uiwindow_add(this->window, &this->acc, bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->dec, 0, 100, v->dec, &uv_uistyles[0]);
	uv_uislider_set_vertical(&this->dec);
	uv_uislider_set_title(&this->dec, "Deceleration\n(%)");
	uv_uiwindow_add(this->window, &this->dec, bb.x, bb.y, bb.width, bb.height, uv_uislider_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uitogglebutton_init(&this->invert, v->invert, "Invert", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->invert, bb.x, bb.y + bb.height / 5,
			bb.width, bb.height / 2, uv_uitogglebutton_step);
}

void settings_impl_uw50_show(void) {
	this->window = &gui.windows.settings.implements.window;
	uv_uiwindow_clear(this->window);

	this->state = UW50_STATE_NONE;

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y, 3, 3);
	uv_uigridlayout_set_padding(&grid, 30, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->back, "Back", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, bb.x, bb.y, bb.width, BACK_H, uv_uibutton_step);
	bb = uv_uigridlayout_next(&grid);

	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), "UW50");
	uv_uiwindow_add(this->window, &this->label, bb.x, bb.y, bb.width, BACK_H, uv_uilabel_step);
	uv_uigridlayout_next(&grid);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->saw, "Saw", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->saw, bb.x + bb.width / 2 + grid.hpadding,
			bb.y, bb.width, bb.height, uv_uibutton_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->tilt, "Tilt", &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->tilt, bb.x + bb.width / 2 + grid.hpadding,
			bb.y, bb.width, bb.height, uv_uibutton_step);

}


void settings_impl_uw50_step(uint16_t step_ms) {
	if (this->state == UW50_STATE_NONE) {
		if (uv_uibutton_clicked(&this->back)) {
			settings_implements_show();
			return;
		}
		else if (uv_uibutton_clicked(&this->saw)) {
			show_sliders(UW50_STATE_SAW, uv_uibutton_get_text(&this->saw));
			return;
		}
		else if (uv_uibutton_clicked(&this->tilt)) {
			show_sliders(UW50_STATE_TILT, uv_uibutton_get_text(&this->tilt));
			return;
		}
	}
	else {
		void (*set_params)(uint16_t,
				uint16_t, uint16_t, uint16_t, bool) = NULL;
		impl_valve_ext_st *v = NULL;

		if (this->state == UW50_STATE_SAW) {
			set_params = ecu_set_uw50_saw_params;
			v = &dspl.user->uw50.saw;
		}
		else if (this->state == UW50_STATE_TILT) {
			set_params = ecu_set_uw50_tilt_params;
			v = &dspl.user->uw50.tilt;
		}

		if (uv_uislider_value_changed(&this->max_speed_p)) {
			v->max_speed_p = uv_uislider_get_value(&this->max_speed_p);
			set_params(uv_uislider_get_value(&this->max_speed_p),
					uv_uislider_get_value(&this->max_speed_n),
					uv_uislider_get_value(&this->acc),
					uv_uislider_get_value(&this->dec),
					uv_uitogglebutton_get_state(&this->invert));
		}
		else if (uv_uislider_value_changed(&this->max_speed_n)) {
			v->max_speed_n = uv_uislider_get_value(&this->max_speed_n);
			set_params(uv_uislider_get_value(&this->max_speed_p),
					uv_uislider_get_value(&this->max_speed_n),
					uv_uislider_get_value(&this->acc),
					uv_uislider_get_value(&this->dec),
					uv_uitogglebutton_get_state(&this->invert));
		}
		else if (uv_uislider_value_changed(&this->acc)) {
			v->acc = uv_uislider_get_value(&this->acc);
			set_params(uv_uislider_get_value(&this->max_speed_p),
					uv_uislider_get_value(&this->max_speed_n),
					uv_uislider_get_value(&this->acc),
					uv_uislider_get_value(&this->dec),
					uv_uitogglebutton_get_state(&this->invert));
		}
		else if (uv_uislider_value_changed(&this->dec)) {
			v->dec = uv_uislider_get_value(&this->dec);
			set_params(uv_uislider_get_value(&this->max_speed_p),
					uv_uislider_get_value(&this->max_speed_n),
					uv_uislider_get_value(&this->acc),
					uv_uislider_get_value(&this->dec),
					uv_uitogglebutton_get_state(&this->invert));
		}
		else if (uv_uitogglebutton_clicked(&this->invert)) {
			v->invert = uv_uitogglebutton_get_state(&this->invert);
			set_params(uv_uislider_get_value(&this->max_speed_p),
					uv_uislider_get_value(&this->max_speed_n),
					uv_uislider_get_value(&this->acc),
					uv_uislider_get_value(&this->dec),
					uv_uitogglebutton_get_state(&this->invert));
		}
		else if (uv_uibutton_clicked(&this->back)) {
			settings_impl_uw50_show();
			return;
		}
	}
}

