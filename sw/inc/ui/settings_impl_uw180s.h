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
	UW180S_STATE_GENERAL,
	// put new states here

	// note: after UW180S_STATE_VALVES, only valve states are allowed
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
			uv_uislider_st log_len1;
			uv_uislider_st log_len2;
			uv_uitogglebutton_st enabled;
			uv_uislider_st len_calib;
			uv_uislider_st vol_calib;
			uv_uilabel_st info_label;
		} mb;
		struct {
			uv_uibutton_st general;
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
		struct {
			uv_uislider_st rollers_grab_time;
			uv_uislider_st blades_grab_time;
		} general;
	};

} settings_uw180s_st;


void settings_impl_uw180s_show(void);


uv_uiobject_ret_e settings_impl_uw180s_step(uint16_t step_ms);


#endif /* UI_SETTINGS_IMPL_UW180S_H_ */
