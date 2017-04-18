/*
 * settings_implements.h
 *
 *  Created on: Nov 3, 2016
 *      Author: usevolt
 */

#ifndef UI_SETTINGS_IMPLEMENTS_H_
#define UI_SETTINGS_IMPLEMENTS_H_


#include <uv_ui.h>
#include "vehicle.h"
#include "implement.h"
#include "settings_impl_uw180s.h"
#include "settings_impl_uw50.h"
#include "settings_impl_uw100.h"

#define SETTINGS_IMPLEMENT_BUFFER_LEN	12


typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SETTINGS_IMPLEMENT_BUFFER_LEN];

	union {
		settings_uw180s_st uw180s;
		settings_uw100_st uw100;
		settings_uw50_st uw50;
		struct {
			uv_uilabel_st info;
			uv_uibutton_st goto_settings;
		};
	};

} settings_implements_st;


void settings_implements_show(void);


uv_uiobject_ret_e settings_implements_step(uint16_t step_ms);


#endif /* UI_SETTINGS_IMPLEMENTS_H_ */
