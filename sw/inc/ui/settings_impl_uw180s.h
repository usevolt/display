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


#define UW180S_CALIB_DATA_STR_LEN	64


enum {
	UW180S_STATE_NONE = 0,
	UW180S_STATE_MB,
	UW180S_STATE_WIDTH_CALIB,
	UW180S_STATE_GENERAL,
	// put new states here

	// note: after UW180S_STATE_VALVES, only valve states are allowed
	UW180S_STATE_VALVES,
	UW180S_STATE_FEEDOPEN,
	UW180S_STATE_FEED,
	UW180S_STATE_BLADESOPEN,
	UW180S_STATE_SAW,
	UW180S_STATE_TILT,
	UW180S_STATE_ROTATOR,
	UW180S_STATE_ALLOPEN,
	UW180S_STATE_IMPL1,
	UW180S_STATE_IMPL2
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
			uv_uislider_st len_calib;
			uv_uislider_st vol_calib;
			uv_uilabel_st info_label;
			uv_uibutton_st vol_reset;
			uv_uibutton_st calib;
		} mb;
		struct {
			uint16_t diam_count;
			char calib_data_str[UW180S_CALIB_DATA_STR_LEN];
			uv_uilabel_st calib_data;
			uv_uibutton_st add_diam;
			uv_uitogglebutton_st start_calib;
			uv_uibutton_st clear_diam;
		} width_calib;
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
			uv_uibutton_st allopen;
			uv_uibutton_st impl1;
			uv_uibutton_st impl2;
		} valves;
		struct {
			uv_uislider_st max_speed_p;
			uv_uislider_st max_speed_n;
			uv_uitogglebutton_st invert;
			char str[32];
			uv_uitoucharea_st assinv_touch;
			uv_uilabel_st assinv_label;
			char assinv_str[32];
			int assinv_delay;
		} sliders;
		struct {
			uv_uislider_st rollers_grab_time;
			uv_uislider_st blades_grab_time;
			uv_uitogglebutton_st tilt_float;
		} general;
	};

} settings_uw180s_st;


void settings_impl_uw180s_show(void);


uv_uiobject_ret_e settings_impl_uw180s_step(uint16_t step_ms);


#endif /* UI_SETTINGS_IMPL_UW180S_H_ */
