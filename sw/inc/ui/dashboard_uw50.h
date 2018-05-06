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
	uv_uidigit_st len;
	uv_uilabel_st len_label;

	uv_uidigit_st wid;
	uv_uilabel_st wid_label;

	uv_uidigit_st vol;
	uv_uilabel_st vol_label;

	uv_uilabel_st tree_type;
	uv_uilabel_st log_type;

	uv_uibutton_st log_length;

	uv_uilabel_st saw_pos;
	char saw_str[16];

	uint8_t active_len;

} dashboard_uw50_st;


void dashboard_uw50_show();

uv_uiobject_ret_e dashboard_uw50_step(uint16_t step_ms);



#endif /* UI_DASHBOARD_UW50_H_ */
