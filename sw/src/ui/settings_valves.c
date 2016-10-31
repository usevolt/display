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

static void sliders_show(char *str);

static void boom_lift_callb(void *me, uibutton_state_e state);
static void boom_fold_callb(void *me, uibutton_state_e state);
static void boom_rotate_callb(void *me, uibutton_state_e state);
static void left_leg_callb(void *me, uibutton_state_e state);
static void right_leg_callb(void *me, uibutton_state_e state);
static void drive_callb(void *me, uibutton_state_e state);
static void steer_callb(void *me, uibutton_state_e state);

static void back_callb(void *me, uibutton_state_e state);
static void min_speed_p_callb(void *me, int16_t value);
static void max_speed_p_callb(void *me, int16_t value);
static void min_speed_n_callb(void *me, int16_t value);
static void max_speed_n_callb(void *me, int16_t value);
static void acc_callb(void *me, int16_t value);
static void dec_callb(void *me, int16_t value);


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

	// boom lift
	uv_uibutton_init(&this->boom_lift, "Boom Lift", &uv_uistyles[0], boom_lift_callb);
	bb = uv_uigridlayout_next(&grid);
	uv_uiwindow_add(&this->window, &this->boom_lift, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	// boom fold
	uv_uibutton_init(&this->boom_fold, "Boom Fold", &uv_uistyles[0], boom_fold_callb);
	bb = uv_uigridlayout_next(&grid);
	uv_uiwindow_add(&this->window, &this->boom_fold, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	// boom rotate
	uv_uibutton_init(&this->boom_rotate, "Boom Rotate", &uv_uistyles[0], boom_rotate_callb);
	bb = uv_uigridlayout_next(&grid);
	uv_uiwindow_add(&this->window, &this->boom_rotate, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	//left leg
	uv_uibutton_init(&this->left_leg, "Left Leg", &uv_uistyles[0], left_leg_callb);
	bb = uv_uigridlayout_next(&grid);
	uv_uiwindow_add(&this->window, &this->left_leg, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	//right leg
	uv_uibutton_init(&this->right_leg, "Right Leg", &uv_uistyles[0], right_leg_callb);
	bb = uv_uigridlayout_next(&grid);
	uv_uiwindow_add(&this->window, &this->right_leg, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	//drive
	uv_uibutton_init(&this->drive, "Drive", &uv_uistyles[0], drive_callb);
	bb = uv_uigridlayout_next(&grid);
	uv_uiwindow_add(&this->window, &this->drive, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);

	//steer
	uv_uibutton_init(&this->steer, "Steer", &uv_uistyles[0], steer_callb);
	bb = uv_uigridlayout_next(&grid);
	uv_uiwindow_add(&this->window, &this->steer, bb.x, bb.y, bb.width, bb.height, uv_uibutton_step);
}


void settings_valves_step(uint16_t step_ms) {

}

static void boom_lift_callb(void *me, uibutton_state_e state) {
	sliders_show(uv_uibutton_get_text(&this->boom_lift));

}

static void boom_fold_callb(void *me, uibutton_state_e state) {
	sliders_show(uv_uibutton_get_text(&this->boom_fold));

}

static void boom_rotate_callb(void *me, uibutton_state_e state) {
	sliders_show(uv_uibutton_get_text(&this->boom_rotate));

}

static void left_leg_callb(void *me, uibutton_state_e state) {
	sliders_show(uv_uibutton_get_text(&this->left_leg));

}

static void right_leg_callb(void *me, uibutton_state_e state) {
	sliders_show(uv_uibutton_get_text(&this->right_leg));

}

static void drive_callb(void *me, uibutton_state_e state) {
	sliders_show(uv_uibutton_get_text(&this->drive));

}

static void steer_callb(void *me, uibutton_state_e state) {
	sliders_show(uv_uibutton_get_text(&this->steer));
}

static void sliders_show(char *str) {
	uv_uiwindow_clear(&this->window);

	uv_uilabel_init(&this->topic, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), str);
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

	uv_uislider_init(&this->min_speed_p, 0, 1000, 50, &uv_uistyles[0], min_speed_p_callb);
	uv_uiwindow_add(&this->window, &this->min_speed_p,
			bb.x, bb.y, bb.width, bb.height / 2, uv_uislider_step);
	uv_uilabel_init(&this->min_speed_p_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Positive min speed (mA)");
	uv_uiwindow_add(&this->window, &this->min_speed_p_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2, uv_uilabel_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->max_speed_p, 0, 1000, 50, &uv_uistyles[0], max_speed_p_callb);
	uv_uiwindow_add(&this->window, &this->max_speed_p,
			bb.x, bb.y, bb.width, bb.height / 2, uv_uislider_step);
	uv_uilabel_init(&this->max_speed_p_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Positive max speed (mA)");
	uv_uiwindow_add(&this->window, &this->max_speed_p_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2, uv_uilabel_step);


	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->acc, 0, 100, 50, &uv_uistyles[0], acc_callb);
	uv_uiwindow_add(&this->window, &this->acc,
			bb.x, bb.y, bb.width, bb.height / 2, uv_uislider_step);
	uv_uilabel_init(&this->acc_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Acceleration (%)");
	uv_uiwindow_add(&this->window, &this->acc_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2, uv_uilabel_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->min_speed_n, 0, 1000, 50, &uv_uistyles[0], min_speed_n_callb);
	uv_uiwindow_add(&this->window, &this->min_speed_n,
			bb.x, bb.y, bb.width, bb.height / 2, uv_uislider_step);
	uv_uilabel_init(&this->min_speed_n_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Negative min speed (mA)");
	uv_uiwindow_add(&this->window, &this->min_speed_n_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2, uv_uilabel_step);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->max_speed_n, 0, 1000, 50, &uv_uistyles[0], max_speed_n_callb);
	uv_uiwindow_add(&this->window, &this->max_speed_n,
			bb.x, bb.y, bb.width, bb.height / 2, uv_uislider_step);
	uv_uilabel_init(&this->max_speed_n_label, &UI_FONT_SMALL, ALIGN_TOP_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Negative max speed (mA)");
	uv_uiwindow_add(&this->window, &this->max_speed_n_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2, uv_uilabel_step);


	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->dec, 0, 100, 50, &uv_uistyles[0], dec_callb);
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

static void back_callb(void *me, uibutton_state_e state) {
	settings_valves_show();
}
