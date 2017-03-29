/*
 * dashboard.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef UI_DASHBOARD_H_
#define UI_DASHBOARD_H_

#include <uv_utilities.h>
#include <uv_ui.h>
#include "main.h"
#include "dashboard_uw180s.h"
#include "dashboard_uw50.h"
#include "dashboard_generic.h"

#define DASHBOARD_BUFFER_LEN	12
#define IMPL_BUFFER_LEN			12

typedef struct {
	uv_uiwindow_st window;
	uv_uiobject_st *buffer[DASHBOARD_BUFFER_LEN];

	uv_uilabel_st topic;
	uv_uibutton_st cancel;
	uv_uibutton_st ok;

	uv_uiwindow_st impl_window;
	uv_uiobject_st *impl_buffer[IMPL_BUFFER_LEN];

	union {
		dashboard_uw180s_st dashboard_uw180s;
		dashboard_uw50_st dashboard_uw50;
	} implements;


} dashboard_st;




void dashboard_show(void);


void dashboard_step(uint16_t step_ms);


#endif /* UI_DASHBOARD_H_ */
