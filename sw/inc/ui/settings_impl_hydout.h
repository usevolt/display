/*
 * settings_hydout.h
 *
 *  Created on: Dec 29, 2016
 *      Author: usevolt
 */

#ifndef UI_SETTINGS_IMPL_HYDOUT_H_
#define UI_SETTINGS_IMPL_HYDOUT_H_


#include <uv_utilities.h>
#include <uv_ui.h>


enum {
	HYDOUT_STATE_NONE = 0,
	HYDOUT_STATE_IMPL2
};
typedef uint8_t hydout_states_e;

typedef struct {
	uv_uiwindow_st *window;

	hydout_states_e state;

	uv_uibutton_st back;
	uv_uilabel_st label;
	union {
		struct {
			uv_uibutton_st impl2;
		};
		struct {
			uv_uislider_st max_speed_p;
			uv_uislider_st max_speed_n;
			uv_uitogglebutton_st invert;
		};
	};
} settings_hydout_st;

void settings_impl_hydout_show(void);

uv_uiobject_ret_e settings_impl_hydout_step(uint16_t step_ms);


#endif /* UI_SETTINGS_IMPL_HYDOUT_H_ */
