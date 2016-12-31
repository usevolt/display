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
#include "settings_impl_generic.h"
#include "settings_impl_uw180s.h"
#include "settings_impl_uw50.h"
#include "settings_impl_uw100.h"

#define SETTINGS_IMPLEMENT_BUFFER_LEN	12


typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[SETTINGS_IMPLEMENT_BUFFER_LEN];

	uv_uilabel_st impls_label;
	char *impl_names[UW_IMPLEMENT_COUNT + GENERIC_IMPLEMENT_COUNT];
	uv_uilist_st impls_list;
	uv_uibutton_st new_impl;
	uv_uibutton_st del_impl;
	uv_uibutton_st impl_settings;

	bool implement_dialog;

	union {
		settings_uw180s_st uw180s;
		settings_uw100_st uw100;
		settings_uw50_st uw50;
	};

} settings_implements_st;


void settings_implements_show(void);


void settings_implements_step(uint16_t step_ms);


#endif /* UI_SETTINGS_IMPLEMENTS_H_ */
