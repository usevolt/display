/*
 * dashboard_uw180s.h
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */

#ifndef UI_DASHBOARD_UW180S_H_
#define UI_DASHBOARD_UW180S_H_


#include <uv_ui.h>


typedef struct {
	uv_uiwindow_st *window;
} dashboard_uw180s_st;


void dashboard_uw180s_show();

void dashboard_uw180s_step(uint16_t step_ms);



#endif /* UI_DASHBOARD_UW180S_H_ */
