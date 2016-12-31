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
	UW50_STATE_SAW,
	UW50_STATE_TILT
};
typedef uint8_t uw50_states_e;

typedef struct {
	uv_uiwindow_st *window;

	uw50_states_e state;

	uv_uibutton_st back;
	uv_uilabel_st label;
	union {
		struct {
			uv_uibutton_st saw;
			uv_uibutton_st tilt;
		};
		struct {
			uv_uislider_st max_speed_p;
			uv_uislider_st max_speed_n;
			uv_uislider_st acc;
			uv_uislider_st dec;
			uv_uitogglebutton_st invert;
		};
	};
} settings_uw50_st;


void settings_impl_uw50_show(void);


void settings_impl_uw50_step(uint16_t step_ms);


#endif /* UI_SETTINGS_IMPL_UW50_H_ */
