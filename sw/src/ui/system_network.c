/*
 * system_network.c
 *
 *  Created on: Dec 30, 2016
 *      Author: usevolt
 */


#include "system_network.h"
#include "gui.h"
#include "network.h"
#include "netdev.h"

#define this (&gui.windows.system.windows.sys_network)

#define OBJ_HEIGHT	160

static void show(uv_uitreeobject_st *obj);

typedef struct {
	const char *name;
	const char *row2;
	const char *row3;
} data_st;
static const data_st labels[];


void system_network_show(void) {
	uv_uiwindow_clear(&gui.windows.system.tabs);

	uv_uitreeview_init(&this->treeview, this->treeviewbuffer, &uv_uistyles[0]);
	uv_uitabwindow_add(&gui.windows.system.tabs, &this->treeview, 0, 0,
			uv_uibb(&gui.windows.system.tabs)->width,
			uv_uitabwindow_get_contentbb(&gui.windows.system.tabs).height);

	this->dev = DEV_COUNT;

	for (int i = 0; i < DEV_COUNT; i++) {
		uv_uitreeobject_init(&this->objs[i], this->buffer,
				labels[i].name, &show, &uv_uistyles[0]);
		uv_uitreeobject_set_step_callback(&this->objs[i], system_network_step);
		uv_uitreeview_add(&this->treeview, &this->objs[i], OBJ_HEIGHT, false);
	}
}

const char *get_output_state_str(uv_output_state_e state) {
	if (state == OUTPUT_STATE_OFF) {
		return "OFF";
	}
	else if (state == OUTPUT_STATE_ON) {
		return "ON";
	}
	else if (state == OUTPUT_STATE_FAULT) {
		return "FAULT";
	}
	else if (state== OUTPUT_STATE_OVERLOAD) {
		return "OVERL";
	}
	else {
		return "";
	}
}

static const char netdev_label[] =
		"Connected\n"
		"Node ID";

static const data_st labels[DEV_COUNT] = {
		// ESB
		{
				.name = "ESB",
				.row2 = "Total Current\n"
						"Glow State\n"
						"Starter State\n"
						"AC State\n"
						"MStart1 State\n"
						"MStart2 State\n"
						"Pump State\n"
						"Alt IG State\n"
						"Oil cooler State",
				.row3 = "RPM\n"
						"Alt L\n"
						"Motor Water\n"
						"Motor Oil\n"
						"Motor Temp (C)\n"
						"Oil Temp (C)\n"
						"Oil Level (%)\n"
						"Fuel Level (%)\n"
						"Voltage (mV)\n"
						"OilC trig temp (C)"
		},
		// FSB
		{
				.name = "FSB",
				.row2 = "Total Current\n"
						"Horn State\n"
						"Radio State\n"
						"Aux State\n"
						"Heater State",
				.row3 = "Ignition key\n"
						"Heater Speed\n"
						"EMCY switch\n"
						"Bat Voltage\n"
						"Eber Fan\n"
						"Seat\n"
						"Door1\n"
						"Door2"
		},
		// CSB
		{
				.name = "CSB",
				.row2 = "Total Current\n"
						"Work Light State\n"
						"Drive Light State\n"
						"Back Light State\n"
						"In Light State\n"
						"Beacon State\n"
						"Wiper State\n"
						"Cooler State\n"
						"Oil Cooler State",
				.row3 = "Wiper Speed\n"
						"Cooler P\n"
						"Work Light Current\n"
						"Drive Light Current\n"
						"OilC trigger temp"
		},
		// ECU
#if FM
		{
				.name = "ECU",
				.row2 = "Controls moved\n"
						"Engine shut down\n"
						"Pump angle (ppt)\n"
						"Implement\n"
						"Legs Down\n"
						"Pressure (bar)",
				.row3 = "Boom Lift (mA)\n"
						"Boom Fold (mA)\n"
						"Boom Rotate (mA)\n"
						"Drive (mA)\n"
						"Steer (mA)\n"
						"Left Leg (mA)\n"
						"Right Leg (mA)\n"
						"Impl valve (mA)"
		},
#elif LM
		{
				.name = "ECU",
				.row2 = "Controls moved\n"
						"Engine shut down\n"
						"Pump angle (ppt)\n"
						"Implement\n"
						"Legs Down\n"
						"Pressure (bar)",
				.row3 = "Boom Lift (mA)\n"
						"Boom Fold (mA)\n"
						"Boom Rotate (mA)\n"
						"Boom Telescope (mA)\n"
						"Drive Front (mA)\n"
						"Drive Back (mA)\n"
						"Steer Front (mA)\n"
						"Steer Back (mA)\n"
						"Left Leg (mA)\n"
						"Right Leg (mA)\n"
						"Cabin Rotate (mA)"
		},
#elif CM
		{
				.name = "ECU",
				.row2 = "Controls moved\n"
						"Engine shut down\n"
						"Pump angle (ppt)\n"
						"Implement\n"
						"Legs Down\n"
						"Pressure (bar)",
				.row3 = "Boom Lift (mA)\n"
						"Boom Fold (mA)\n"
						"Boom Rotate (mA)\n"
						"Drive Front (mA)\n"
						"Drive Back (mA)\n"
						"Steer Front (mA)\n"
						"Body Telescope (mA)\n"
						"Left Leg (mA)\n"
						"Right Leg (mA)\n"
						"Cabin Rotate (mA)"
		},
#endif
		// L_KEYPAD
		{
				.name = "Left Keypad",
				.row2 = "x\nx err\ny\ny err\nz\nz err\nv\nv err",
				.row3 = "b1\nb2\nb3\nb4\nb5\nb6\nb7\nb8\nb9\nb10"
		},
		// R_KEYPAD
		{
				.name = "Right Keypad",
				.row2 = "x\nx err\ny\ny err\nz\nz err\nv\nv err",
				.row3 = "b1\nb2\nb3\nb4\nb5\nb6\nb7\nb8\nb9\nb10"
		},
		// PEDAL
		{
				.name = "Pedal",
				.row2 = "pos",
				.row3 = ""
		},
		// UW180S
		{
				.name = "UW180S",
				.row2 = "",
				.row3 = ""
		},
		// UW180S_MB
		{
				.name = "UW180S MB",
				.row2 = "Length\nWidth",
				.row3 = "Width sensors\n"
		},

};

static void update_netdev(void *dev) {
	snprintf(this->row1_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
			"%i\n%i",
		netdev_get_connected(dev),
		netdev_get_node_id(dev));
	uv_ui_refresh(&this->row1_values);
	if (!netdev_get_connected(dev)) {
		strcpy(this->row2_val_str, "");
		strcpy(this->row3_val_str, "");
	}
}

static void update(devices_e dev) {
	if (dev == ESB) {
		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
				uv_canopen_sdo_read16(ESB_NODE_ID,
					ESB_TOTAL_CURRENT_INDEX, ESB_TOTAL_CURRENT_SUBINDEX),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_GLOW_STATUS_INDEX, ESB_GLOW_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_STARTER_STATUS_INDEX, ESB_STARTER_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_AC_STATUS_INDEX, ESB_AC_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_ENGINE_START1_STATUS_INDEX, ESB_ENGINE_START1_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_ENGINE_START2_STATUS_INDEX, ESB_ENGINE_START2_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_PUMP_STATUS_INDEX, ESB_PUMP_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_ALT_IG_STATUS_INDEX, ESB_ALT_IG_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_OILCOOLER_STATUS_INDEX, ESB_OILCOOLER_STATUS_SUBINDEX)));
		uv_ui_refresh(&this->row2_values);
		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i",
				uv_canopen_sdo_read16(ESB_NODE_ID,
						ESB_RPM_INDEX, ESB_RPM_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_ALT_L_INDEX, ESB_ALT_L_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_MOTOR_WATER_TEMP_INDEX, ESB_MOTOR_WATER_TEMP_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_MOTOR_OIL_PRESS_INDEX, ESB_MOTOR_OIL_PRESS_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_MOTOR_TEMP_INDEX, ESB_MOTOR_TEMP_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_OIL_TEMP_INDEX, ESB_OIL_TEMP_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_OIL_LEVEL_INDEX, ESB_OIL_LEVEL_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_FUEL_LEVEL_INDEX, ESB_FUEL_LEVEL_SUBINDEX),
				uv_canopen_sdo_read16(ESB_NODE_ID,
						ESB_VDD_INDEX, ESB_VDD_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_OILCOOLER_TRIGGER_INDEX, ESB_OILCOOLER_TRIGGER_SUBINDEX));
		uv_ui_refresh(&this->row3_values);
		update_netdev(&dspl.network.esb);
	}
	else if (dev == FSB) {
		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%s\n%s\n%s\n%s",
				uv_canopen_sdo_read16(FSB_NODE_ID,
						FSB_TOTAL_CURRENT_INDEX, FSB_TOTAL_CURRENT_SUBINDEX),
				get_output_state_str(uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_HORN_STATUS_INDEX, FSB_HORN_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_RADIO_STATUS_INDEX, FSB_RADIO_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_AUX_STATUS_INDEX, FSB_AUX_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_HEATER_STATUS_INDEX, FSB_HEATER_STATUS_SUBINDEX)));
		uv_ui_refresh(&this->row2_values);
		fsb_ignkey_states_e ignkey_state = uv_canopen_sdo_read8(FSB_NODE_ID,
				FSB_IGNKEY_INDEX, FSB_IGNKEY_SUBINDEX);
		const char *ignkey;
		if (ignkey_state == FSB_IGNKEY_STATE_OFF) {
			ignkey = "OFF";
		}
		else if (ignkey_state == FSB_IGNKEY_STATE_ON) {
			ignkey = "ON";
		}
		else if (ignkey_state == FSB_IGNKEY_STATE_PREHEAT) {
			ignkey = "PREHEAT";
		}
		else if (ignkey_state == FSB_IGNKEY_STATE_START) {
			ignkey = "START";
		}
		else {
			ignkey = "";
		}
		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%s\n%i\n%i\n%i\n%i\n%i\n%i\n%i",
				ignkey,
				uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_HEATER_SPEED_INDEX, FSB_HEATER_SPEED_SUBINDEX),
				uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_EMCY_INDEX, FSB_EMCY_SUBINDEX),
				uv_canopen_sdo_read16(FSB_NODE_ID,
						FSB_BAT_INDEX, FSB_BAT_SUBINDEX),
				uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_EBERFAN_INDEX, FSB_EBERFAN_SUBINDEX),
				uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_SEATSW_INDEX, FSB_SEATSW_SUBINDEX),
				uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_DOORSW1_INDEX, FSB_DOORSW1_SUBINDEX),
				uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_DOORSW2_INDEX, FSB_DOORSW2_SUBINDEX));
		uv_ui_refresh(&this->row3_values);

		update_netdev(&dspl.network.fsb);

	}
	else if (dev == CSB) {

		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%s\n%s\n%s\n%s\n%s\n%s",
				uv_canopen_sdo_read16(CSB_NODE_ID,
						CSB_TOTAL_CURRENT_INDEX, CSB_TOTAL_CURRENT_SUBINDEX),
				get_output_state_str(uv_canopen_sdo_read8(CSB_NODE_ID,
						CSB_WORK_LIGHT_STATUS_INDEX, CSB_WORK_LIGHT_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(CSB_NODE_ID,
						CSB_DRIVE_LIGHT_STATUS_INDEX, CSB_DRIVE_LIGHT_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(CSB_NODE_ID,
						CSB_BACK_LIGHT_STATUS_INDEX, CSB_BACK_LIGHT_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(CSB_NODE_ID,
						CSB_IN_LIGHT_STATUS_INDEX, CSB_IN_LIGHT_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(CSB_NODE_ID,
						CSB_BEACON_STATUS_INDEX, CSB_BEACON_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(CSB_NODE_ID,
						CSB_WIPER_STATUS_INDEX, CSB_WIPER_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(CSB_NODE_ID,
						CSB_COOLER_STATUS_INDEX, CSB_COOLER_STATUS_SUBINDEX)));
		uv_ui_refresh(&this->row2_values);

		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i",
				uv_canopen_sdo_read8(CSB_NODE_ID,
						CSB_WIPER_SPEED_INDEX, CSB_WIPER_SPEED_SUBINDEX),
				uv_canopen_sdo_read8(CSB_NODE_ID,
						CSB_COOLER_P_INDEX, CSB_COOLER_P_SUBINDEX),
				uv_canopen_sdo_read16(CSB_NODE_ID,
						CSB_WORK_LIGHT_CURRENT_INDEX, CSB_WORK_LIGHT_CURRENT_SUBINDEX),
				uv_canopen_sdo_read16(CSB_NODE_ID,
						CSB_DRIVE_LIGHT_CURRENT_INDEX, CSB_DRIVE_LIGHT_CURRENT_SUBINDEX));
		uv_ui_refresh(&this->row3_values);

		update_netdev(&dspl.network.csb);
	}
	else if (dev == ECU) {
		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i",
				ecu_get_controls_moved(&dspl.network.ecu),
				ecu_get_engine_shut_down(&dspl.network.ecu),
				ecu_get_pump_angle(&dspl.network.ecu),
				ecu_get_implement(&dspl.network.ecu),
				ecu_get_legs_down(&dspl.network.ecu),
				ecu_get_pressure(&dspl.network.ecu));
		uv_ui_refresh(&this->row2_values);
#if FM
		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i",
				ecu_get_boom_lift_ma(&dspl.network.ecu),
				ecu_get_boom_fold_ma(&dspl.network.ecu),
				ecu_get_boom_rotate_ma(&dspl.network.ecu),
				ecu_get_drive_ma(&dspl.network.ecu),
				ecu_get_steer_ma(&dspl.network.ecu),
				ecu_get_left_leg_ma(&dspl.network.ecu),
				ecu_get_right_leg_ma(&dspl.network.ecu),
				ecu_get_impl_valve_ma(&dspl.network.ecu));
#elif LM
		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i",
				ecu_get_boom_lift_ma(&dspl.network.ecu),
				ecu_get_boom_fold_ma(&dspl.network.ecu),
				ecu_get_boom_rotate_ma(&dspl.network.ecu),
				ecu_get_boom_telescope_ma(&dspl.network.ecu),
				ecu_get_drivefront_ma(&dspl.network.ecu),
				ecu_get_driveback_ma(&dspl.network.ecu),
				ecu_get_steerfront_ma(&dspl.network.ecu),
				ecu_get_steerback_ma(&dspl.network.ecu),
				ecu_get_left_leg_ma(&dspl.network.ecu),
				ecu_get_right_leg_ma(&dspl.network.ecu),
				ecu_get_cab_rot_ma(&dspl.network.ecu));
#elif CM
		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i",
				ecu_get_boom_lift_ma(&dspl.network.ecu),
				ecu_get_boom_fold_ma(&dspl.network.ecu),
				ecu_get_boom_rotate_ma(&dspl.network.ecu),
				ecu_get_drivefront_ma(&dspl.network.ecu),
				ecu_get_driveback_ma(&dspl.network.ecu),
				ecu_get_steer_ma(&dspl.network.ecu),
				ecu_get_telescope_ma(&dspl.network.ecu),
				ecu_get_left_leg_ma(&dspl.network.ecu),
				ecu_get_right_leg_ma(&dspl.network.ecu),
				ecu_get_cab_rot_ma(&dspl.network.ecu));
#endif
		uv_ui_refresh(&this->row3_values);
		update_netdev(&dspl.network.ecu);
	}
	else if (dev == R_KEYPAD || dev == L_KEYPAD) {
		keypad_st *keypad;
		if (dev == R_KEYPAD) { keypad = &dspl.network.r_keypad; }
		else { keypad = &dspl.network.l_keypad; }

		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i",
				keypad_get_x(keypad),
				keypad_get_x_err(keypad),
				keypad_get_y(keypad),
				keypad_get_y_err(keypad),
				keypad_get_z(keypad),
				keypad_get_z_err(keypad),
				keypad_get_v(keypad),
				keypad_get_v_err(keypad));
		uv_ui_refresh(&this->row2_values);
		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i",
				keypad_get_button(keypad, 0),
				keypad_get_button(keypad, 1),
				keypad_get_button(keypad, 2),
				keypad_get_button(keypad, 3),
				keypad_get_button(keypad, 4),
				keypad_get_button(keypad, 5),
				keypad_get_button(keypad, 6),
				keypad_get_button(keypad, 7),
				keypad_get_button(keypad, 8),
				keypad_get_button(keypad, 9));
		uv_ui_refresh(&this->row3_values);
		update_netdev(keypad);
	}
	else if (dev == PEDAL) {
		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i", pedal_get_value(&dspl.network.pedal));
		uv_ui_refresh(&this->row2_values);
		strcpy(this->row3_val_str, "");
		uv_ui_refresh(&this->row3_values);
		update_netdev(&dspl.network.pedal);
	}
	else if (dev == UW180S_ECU) {
		strcpy(this->row2_val_str, "");
		uv_ui_refresh(&this->row2_values);
		strcpy(this->row3_val_str, "");
		uv_ui_refresh(&this->row3_values);
		update_netdev(&dspl.network.uw180s_ecu);
	}
	else if (dev == UW180S_MB) {
		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN, "%i\n%i\n%i",
				mb_get_length(&dspl.network.uw180s_mb),
				mb_get_width(&dspl.network.uw180s_mb));
		uv_ui_refresh(&this->row2_values);
		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN, "%i",
				uv_canopen_sdo_read16(UW180S_MB_NODE_ID, 0x2004, 5));
		printf("%s\n", this->row3_val_str);
		uv_ui_refresh(&this->row3_values);
		update_netdev(&dspl.network.uw180s_mb);
	}
	else {

	}
}


static void show(uv_uitreeobject_st *obj) {
	this->dev = ((unsigned int) obj - (unsigned int) &this->objs[0]) / sizeof(this->objs[0]);


	uv_uitreeobject_clear(obj);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0, uv_uitreeobject_get_content_bb(obj).width - 7,
			uv_uitreeobject_get_content_bb(obj).height, 6, 1);
	uv_uigridlayout_set_padding(&grid, 1, 1);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);


	float labelscale = 1.6f;
	float valuescale = 2.0f - labelscale;

	uv_uilabel_init(&this->row1_topics, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			C(0xFFFFFFFF), (char*) netdev_label);
	uv_uitreeobject_add(obj, &this->row1_topics, bb.x, bb.y,
			bb.width * labelscale, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row1_values, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			uv_uistyles[0].window_c, this->row1_val_str);
	uv_uitreeobject_add(obj, &this->row1_values, bb.x + bb.width * (labelscale - 1.0f),
			bb.y, bb.width * valuescale, bb.height);


	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row2_topics, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			C(0xFFFFFFFF), (char*) labels[this->dev].row2);
	uv_uitreeobject_add(obj, &this->row2_topics, bb.x, bb.y, bb.width * labelscale, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row2_values, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			uv_uistyles[0].window_c, this->row2_val_str);
	uv_uitreeobject_add(obj, &this->row2_values, bb.x + bb.width * (labelscale - 1.0f),
			bb.y, bb.width * valuescale, bb.height);


	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row3_topics, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			C(0xFFFFFFFF), (char*) labels[this->dev].row3);
	uv_uitreeobject_add(obj, &this->row3_topics, bb.x, bb.y, bb.width * labelscale, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row3_values, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			uv_uistyles[0].window_c, this->row3_val_str);
	uv_uitreeobject_add(obj, &this->row3_values, bb.x + bb.width * (labelscale - 1.0f),
			bb.y, bb.width * valuescale, bb.height);

	update(this->dev);

}


uv_uiobject_ret_e system_network_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	update(this->dev);

	return ret;
}

