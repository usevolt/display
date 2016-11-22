/*
 * settings_valves.c
 *
 *  Created on: Oct 30, 2016
 *      Author: usevolt
 */


#include "settings_valves.h"
#include "main.h"
#include "gui.h"

#define this (&gui.windows.settings.valves)

static void sliders_show(valve_st *valve);

static void valve_callb(void *me, uibutton_state_e state);

static void back_callb(void *me, uibutton_state_e state);
static void min_speed_p_callb(void *me, int16_t value);
static void max_speed_p_callb(void *me, int16_t value);
static void min_speed_n_callb(void *me, int16_t value);
static void max_speed_n_callb(void *me, int16_t value);
static void acc_callb(void *me, int16_t value);
static void dec_callb(void *me, int16_t value);
static void invert_callb(void *me, uibutton_state_e state);



void settings_valves_show() {
	uv_uiwindow_st *window = (uv_uiwindow_st*) &gui.windows.settings.tabs;
	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_add(window, &this->window, 0, CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uibb(window)->width, uv_uibb(window)->height - CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uiwindow_step);

	// grid layout is used to help with aligning the elements
	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uibb(&this->window)->width, uv_uibb(&this->window)->height,
			3, 3);
	uv_uigridlayout_set_padding(&grid, 20, 15);
	uv_bounding_box_st bb;

	for (int16_t i = 0; i < BASE_VALVE_COUNT; i++) {
		uv_uibutton_init(&this->valves[i],(char*) dspl.user->base_valves[i].name, &uv_uistyles[0], valve_callb);
		bb = uv_uigridlayout_next(&grid);
		uv_uiwindow_add(&this->window, &this->valves[i], bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);
	}

	this->valve = NULL;

	sliders_show(&dspl.user->base_valves[3]);
}


void settings_valves_step(uint16_t step_ms) {
	if (this->valve) {
		uv_uilabel_set_text(&this->topic, (char*) this->valve->name);
		uv_uislider_set_value(&this->max_speed_n, this->valve->max_speed_n);
		uv_uislider_set_value(&this->max_speed_p, this->valve->max_speed_p);
		uv_uislider_set_value(&this->min_speed_n, this->valve->min_speed_n);
		uv_uislider_set_value(&this->min_speed_p, this->valve->min_speed_p);
		uv_uislider_set_value(&this->acc, this->valve->acc);
		uv_uislider_set_value(&this->dec, this->valve->dec);
		uv_uitogglebutton_set_state(&this->invert, this->valve->invert);
	}

}

static void valve_callb(void *me, uibutton_state_e state) {
	for (int16_t i = 0; i < BASE_VALVE_COUNT; i++) {
		if (strcmp(dspl.user->base_valves[i].name, uv_uibutton_get_text(me)) == 0) {
			sliders_show(&dspl.user->base_valves[i]);
			break;
		}
	}
	printf("Unknown valve '%s'\n\r", uv_uibutton_get_text(me));

}

static void sliders_show(valve_st *valve) {
	this->valve = valve;
	uv_uiwindow_clear(&this->window);

	uv_uilabel_init(&this->topic, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), (char*) valve->name);
	uv_uiwindow_add(&this->window, &this->topic, 0, 0,
			uv_uibb(&this->window)->width, 80, uv_uilabel_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, uv_uibb(&this->topic)->height,
			uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height - uv_uibb(&this->topic)->height,
			3, 2);
	uv_uigridlayout_set_padding(&grid, 10, 0);
	uv_bounding_box_st bb;

	bb = uv_uigridlayout_next(&grid);

	uv_uibutton_init(&this->back, "Back to valve\n\rconfigurations", &uv_uistyles[0], back_callb);
	uv_uiwindow_add(&this->window, &this->back, bb.x, 10,
			bb.width, 50, uv_uibutton_step);

	uv_uitogglebutton_init(&this->invert, valve->invert, "Invert Direction", &uv_uistyles[0], invert_callb);
	uv_uiwindow_add(&this->window, &this->invert, bb.x + (bb.width + 20) * 2, 10,
			bb.width, 50, uv_uitogglebutton_step);


	uv_uislider_init(&this->min_speed_p, VALVE_MIN_CURRENT_MA, VALVE_MAX_CURRENT_MA,
			valve->min_speed_p, &uv_uistyles[0], min_speed_p_callb);
	uv_uiwindow_add(&this->window, &this->min_speed_p,
			bb.x, bb.y, bb.width, bb.height / 2, uv_uislider_step);
	uv_uilabel_init(&this->min_speed_p_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Forward min speed (mA)");
	uv_uiwindow_add(&this->window, &this->min_speed_p_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2, uv_uilabel_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->max_speed_p, VALVE_MIN_CURRENT_MA, VALVE_MAX_CURRENT_MA,
			valve->max_speed_p, &uv_uistyles[0], max_speed_p_callb);
	uv_uiwindow_add(&this->window, &this->max_speed_p,
			bb.x, bb.y, bb.width, bb.height / 2, uv_uislider_step);
	uv_uilabel_init(&this->max_speed_p_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Forward max speed (mA)");
	uv_uiwindow_add(&this->window, &this->max_speed_p_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2, uv_uilabel_step);


	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->acc, VALVE_MIN_CURRENT_MA, VALVE_MAX_CURRENT_MA,
			valve->acc, &uv_uistyles[0], acc_callb);
	uv_uiwindow_add(&this->window, &this->acc,
			bb.x, bb.y, bb.width, bb.height / 2, uv_uislider_step);
	uv_uilabel_init(&this->acc_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Acceleration (%)");
	uv_uiwindow_add(&this->window, &this->acc_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2, uv_uilabel_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->min_speed_n, VALVE_MIN_CURRENT_MA, VALVE_MAX_CURRENT_MA,
			valve->min_speed_n, &uv_uistyles[0], min_speed_n_callb);
	uv_uiwindow_add(&this->window, &this->min_speed_n,
			bb.x, bb.y, bb.width, bb.height / 2, uv_uislider_step);
	uv_uilabel_init(&this->min_speed_n_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Backward min speed (mA)");
	uv_uiwindow_add(&this->window, &this->min_speed_n_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2, uv_uilabel_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->max_speed_n, VALVE_MIN_CURRENT_MA, VALVE_MAX_CURRENT_MA,
			valve->max_speed_n, &uv_uistyles[0], max_speed_n_callb);
	uv_uiwindow_add(&this->window, &this->max_speed_n,
			bb.x, bb.y, bb.width, bb.height / 2, uv_uislider_step);
	uv_uilabel_init(&this->max_speed_n_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Backward max speed (mA)");
	uv_uiwindow_add(&this->window, &this->max_speed_n_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2, uv_uilabel_step);


	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->dec, VALVE_MIN_CURRENT_MA, VALVE_MAX_CURRENT_MA,
			valve->dec, &uv_uistyles[0], dec_callb);
	uv_uiwindow_add(&this->window, &this->dec,
			bb.x, bb.y, bb.width, bb.height / 2, uv_uislider_step);
	uv_uilabel_init(&this->dec_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Deceleration (%)");
	uv_uiwindow_add(&this->window, &this->dec_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2, uv_uilabel_step);

}

static void min_speed_p_callb(void *me, int16_t value) {

}

static void max_speed_p_callb(void *me, int16_t value) {

}

static void min_speed_n_callb(void *me, int16_t value) {

}

static void max_speed_n_callb(void *me, int16_t value) {

}

static void acc_callb(void *me, int16_t value) {

}

static void dec_callb(void *me, int16_t value) {

}

static void invert_callb(void *me, uibutton_state_e state) {

}

static void back_callb(void *me, uibutton_state_e state) {
	settings_valves_show();
}
