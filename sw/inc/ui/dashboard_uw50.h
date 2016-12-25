/*
 * dashboard_uw50.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef UI_DASHBOARD_UW50_H_
#define UI_DASHBOARD_UW50_H_

#include <uv_ui.h>


typedef struct {
	uv_uiwindow_st *window;
} dashboard_uw50_st;


void dashboard_uw50_show();

void dashboard_uw50_step(uint16_t step_ms);



#endif /* UI_DASHBOARD_UW50_H_ */
