/*
 * settings_impl_uw50.h
 *
 *  Created on: Dec 17, 2016
 *      Author: usevolt
 */

#ifndef UI_SETTINGS_IMPL_UW50_H_
#define UI_SETTINGS_IMPL_UW50_H_

#include <uv_utilities.h>
#include <uv_ui.h>


enum {
	UW50_STATE_NONE = 0,
	UW50_STATE_MB,
	UW50_STATE_VALVES,
	UW50_STATE_WHEELS,
	UW50_STATE_WHEELS_FEED,
	UW50_STATE_DELIMBERS,
	UW50_STATE_SAW,
	UW50_STATE_TILT,
	UW50_STATE_ROTATOR
};
typedef uint8_t uw50_states_e;

typedef struct {
	uv_uiwindow_st *window;


	uw50_states_e state;
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
} settings_uw50_st;


void settings_impl_uw50_show(void);


uv_uiobject_ret_e settings_impl_uw50_step(uint16_t step_ms);


#endif /* UI_SETTINGS_IMPL_UW50_H_ */
