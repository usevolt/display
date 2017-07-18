/*
 * settings_valves.h
 *
 *  Created on: Oct 30, 2016
 *      Author: usevolt
 */

#ifndef UI_SETTINGS_VALVES_H_
#define UI_SETTINGS_VALVES_H_


#include <uv_ui.h>
#include "vehicle.h"

#define SETTINGS_VALVES_BUFFER_LEN	16

/// @brief: Valve configuration screen
typedef struct {
	uv_uitreeview_st treeview;
	uv_uitreeobject_st *treebuffer[BASE_VALVE_COUNT];


	uv_uitreeobject_st valves[BASE_VALVE_COUNT];
	uv_uiobject_st *buffer[SETTINGS_VALVES_BUFFER_LEN];

	/// @brief: Reference to the currently active valve
	valve_st *valve;

	uv_uilabel_st min_speed_p_label;
	uv_uislider_st min_speed_p;
	uv_uilabel_st max_speed_p_label;
	uv_uislider_st max_speed_p;
	uv_uilabel_st acc_label;
	uv_uislider_st acc;
	uv_uilabel_st min_speed_n_label;
	uv_uislider_st min_speed_n;
	uv_uilabel_st max_speed_n_label;
	uv_uislider_st max_speed_n;
	uv_uilabel_st dec_label;
	uv_uislider_st dec;
	uv_uitogglebutton_st invert;
} settings_valves_st;


void settings_valves_show();

uv_uiobject_ret_e settings_valves_step(const uint16_t step_ms);


#endif /* UI_SETTINGS_VALVES_H_ */
