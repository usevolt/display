/*
 * settings_hydout.c
 *
 *  Created on: Dec 29, 2016
 *      Author: usevolt
 */

#include <settings_impl_hydout.h>
#include "gui.h"
#include "tr.h"


#define this	(&gui.windows.settings.implements.hydout)

#define BACK_H		50
#define BACK_W		200
#define BACK_Y		5
#define BACK_X		5


static void show_sliders(hydout_states_e state, char *label) {
	uv_uiwindow_clear(this->window);

	this->state = state;
	valve_st *v;
	if (state == HYDOUT_STATE_IMPL2) { v = &dspl.user->hydout.impl2; }
	else { v = NULL; }

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y, 3, 3);
	uv_uigridlayout_set_padding(&grid, 30, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->back, uv_str(STR_BACK), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->back, bb.x, bb.y, bb.width, BACK_H);
	bb = uv_uigridlayout_next(&grid);

	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), label);
	uv_uiwindow_add(this->window, &this->label, bb.x, bb.y, bb.width, BACK_H);
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
	uv_uislider_set_title(&this->max_speed_p, uv_str(STR_SETTINGS_UW100_SLIDERFORMAXSPEED));
	uv_uiwindow_add(this->window, &this->max_speed_p, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->max_speed_n, VALVE_MIN_CURRENT_MA, VALVE_MAX_CURRENT_MA,
			v->max_speed_n, &uv_uistyles[0]);
	uv_uislider_set_inc_step(&this->max_speed_n, 10);
	uv_uislider_set_vertical(&this->max_speed_n);
	uv_uislider_set_title(&this->max_speed_n, uv_str(STR_SETTINGS_UW100_SLIDERBACKMAXSPEED));
	uv_uiwindow_add(this->window, &this->max_speed_n, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);

	bb = uv_uigridlayout_next(&grid);

	bb = uv_uigridlayout_next(&grid);
	uv_uitogglebutton_init(&this->invert, v->invert,
			uv_str(STR_SETTINGS_UW100_BUTTONINVERT), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->invert, bb.x, bb.y + bb.height / 5,
			bb.width, bb.height / 2);
}

void settings_impl_hydout_show(void) {
	this->window = &gui.windows.settings.implements.window;
	uv_uiwindow_clear(this->window);

	this->state = HYDOUT_STATE_NONE;

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, BACK_Y, uv_uibb(this->window)->width,
			uv_uibb(this->window)->height - BACK_Y, 3, 3);
	uv_uigridlayout_set_padding(&grid, 30, 10);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);
	bb = uv_uigridlayout_next(&grid);

	uv_uilabel_init(&this->label, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF), C(0xFFFFFFFF), "HYDOUT");
	uv_uiwindow_add(this->window, &this->label, bb.x, bb.y, bb.width, BACK_H);
	uv_uigridlayout_next(&grid);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->impl2, uv_str(STR_SETTINGS_UW180S_BUTTONIMPL2), &uv_uistyles[0]);
	uv_uiwindow_add(this->window, &this->impl2, bb.x + bb.width / 2 + grid.hpadding,
			bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
}


uv_uiobject_ret_e settings_impl_hydout_step(uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	if (this->state == HYDOUT_STATE_NONE) {
		if (uv_uibutton_clicked(&this->impl2)) {
			show_sliders(HYDOUT_STATE_IMPL2, uv_uibutton_get_text(&this->impl2));
			ret = UIOBJECT_RETURN_KILLED;
		}
	}
	else {
		valve_st *v = NULL;

		if (this->state == HYDOUT_STATE_IMPL2) {
			v = &dspl.user->hydout.impl2;
			v->setter(v);
		}

		if (uv_uislider_value_changed(&this->max_speed_p)) {
			v->max_speed_p = uv_uislider_get_value(&this->max_speed_p);
			v->setter(v);
		}
		else if (uv_uislider_value_changed(&this->max_speed_n)) {
			v->max_speed_n = uv_uislider_get_value(&this->max_speed_n);
			v->setter(v);
		}
		else if (uv_uitogglebutton_clicked(&this->invert)) {
			v->invert = uv_uitogglebutton_get_state(&this->invert);
			v->setter(v);
		}
		else if (uv_uibutton_clicked(&this->back)) {
			settings_impl_hydout_show();
			ret = UIOBJECT_RETURN_KILLED;
		}
	}
	return ret;
}

