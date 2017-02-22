/*
 * dashboard_uw100.h
 *
 *  Created on: Feb 21, 2017
 *      Author: usevolt
 */

#ifndef UI_DASHBOARD_UW100_H_
#define UI_DASHBOARD_UW100_H_

#include <uv_ui.h>


typedef struct {
	uv_uiwindow_st *window;
} dashboard_uw100_st;


void dashboard_uw100_show();

void dashboard_uw100_step(uint16_t step_ms);




#endif /* UI_DASHBOARD_UW100_H_ */
