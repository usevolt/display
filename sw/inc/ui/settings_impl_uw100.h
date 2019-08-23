/*
 * settings_uw100.h
 *
 *  Created on: Dec 29, 2016
 *      Author: usevolt
 */

#ifndef UI_SETTINGS_IMPL_UW100_H_
#define UI_SETTINGS_IMPL_UW100_H_


#include <uv_utilities.h>
#include <uv_ui.h>


enum {
	UW100_STATE_NONE = 0,
	UW100_STATE_ROTATOR,
	UW100_STATE_OPEN,
	UW100_STATE_IMPL2
};
typedef uint8_t uw100_states_e;

typedef struct {
	uv_uiwindow_st *window;

	uw100_states_e state;

	uv_uibutton_st back;
	uv_uilabel_st label;
	union {
		struct {
			uv_uibutton_st rotator;
			uv_uibutton_st open;
			uv_uibutton_st impl2;
		};
		struct {
			uv_uislider_st max_speed_p;
			uv_uislider_st max_speed_n;
			uv_uislider_st acc;
			uv_uislider_st dec;
			uv_uitogglebutton_st invert;
		};
	};
} settings_uw100_st;
void settings_impl_uw100_show(void);
uv_uiobject_ret_e settings_impl_uw100_step(uint16_t step_ms);


#endif /* UI_SETTINGS_IMPL_UW100_H_ */
