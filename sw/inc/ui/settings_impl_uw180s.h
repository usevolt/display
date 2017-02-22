/*
 * settings_impl_uw180s.h
 *
 *  Created on: Dec 17, 2016
 *      Author: usevolt
 */

#ifndef UI_SETTINGS_IMPL_UW180S_H_
#define UI_SETTINGS_IMPL_UW180S_H_


#include <uv_utilities.h>
#include <uv_ui.h>



enum {
	UW180S_STATE_NONE = 0,
	UW180S_STATE_MB,
	UW180S_STATE_VALVES,
	UW180S_STATE_WHEELS,
	UW180S_STATE_WHEELS_FEED,
	UW180S_STATE_DELIMBERS,
	UW180S_STATE_SAW,
	UW180S_STATE_TILT,
	UW180S_STATE_ROTATOR
};
typedef uint8_t uw180s_state_e;

typedef struct {
	uv_uiwindow_st *window;

	uw180s_state_e state;
	uv_uibutton_st back;
	uv_uilabel_st label;

	union {
		struct {
			uv_uitogglebutton_st enabled;
		} mb;
		struct {
			uv_uibutton_st valves;
			uv_uibutton_st measurement;
		} main;
		struct {
			uv_uibutton_st wheels;
			uv_uibutton_st wheels_feed;
			uv_uibutton_st delimbers;
			uv_uibutton_st tilt;
			uv_uibutton_st rotator;
			uv_uibutton_st saw;
		} valves;
		struct {
			uv_uislider_st max_speed_p;
			uv_uislider_st max_speed_n;
			uv_uitogglebutton_st invert;
			char str[32];
		} sliders;
	};

} settings_uw180s_st;


void settings_impl_uw180s_show(void);


void settings_impl_uw180s_step(uint16_t step_ms);


#endif /* UI_SETTINGS_IMPL_UW180S_H_ */
