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
	langstr_e name;
	langstr_e row2;
	langstr_e row3;
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
				uv_str(labels[i].name), &show, &uv_uistyles[0]);
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

static const data_st labels[DEV_COUNT] = {
		// ESB
		{
				.name = STR_SYSTEM_DIAG_LABELESB,
				.row2 = STR_SYSTEM_DIAG_LABELESBCOL1,
				.row3 = STR_SYSTEM_DIAG_LABELESBCOL2
		},
		// FSB
		{
				.name = STR_SYSTEM_DIAG_LABELFSB,
				.row2 = STR_SYSTEM_DIAG_LABELFSBCOL1,
				.row3 = STR_SYSTEM_DIAG_LABELFSBCOL2
		},
		// CSB
		{
				.name = STR_SYSTEM_DIAG_LABELCSB,
				.row2 = STR_SYSTEM_DIAG_LABELCSBCOL1,
				.row3 = STR_SYSTEM_DIAG_LABELCSBCOL2
		},
		// HCU
		{
				.name = STR_SYSTEM_DIAG_LABELHCU,
				.row2 = STR_SYSTEM_DIAG_LABELHCUCOL1,
				.row3 = STR_SYSTEM_DIAG_LABELHCUCOL2
		},
		// CCU
		{
				.name = STR_SYSTEM_DIAG_LABELCCU,
				.row2 = STR_SYSTEM_DIAG_LABELCCUCOL1,
				.row3 = STR_SYSTEM_DIAG_LABELCCUCOL2
		},
		// L_KEYPAD
		{
				.name = STR_SYSTEM_DIAG_LABELLEFTKEYPAD,
				.row2 = STR_SYSTEM_DIAG_LABELKEYPADCOL1,
				.row3 = STR_SYSTEM_DIAG_LABELKEYPADCOL2
		},
		// R_KEYPAD
		{
				.name = STR_SYSTEM_DIAG_LABELRIGHTKEYPAD,
				.row2 = STR_SYSTEM_DIAG_LABELKEYPADCOL1,
				.row3 = STR_SYSTEM_DIAG_LABELKEYPADCOL2
		},
		// PEDAL
		{
				.name = STR_SYSTEM_DIAG_LABELPEDAL,
				.row2 = STR_SYSTEM_DIAG_LABELPEDALCOL1,
				.row3 = STR_SYSTEM_DIAG_LABELPEDALCOL2
		},
		// ICU
		{
				.name = STR_SYSTEM_DIAG_LABELICU,
				.row2 = STR_SYSTEM_DIAG_LABELICUCOL1,
				.row3 = STR_SYSTEM_DIAG_LABELICUCOL2
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
				"%i\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%u",
				uv_canopen_sdo_read16(ESB_NODE_ID,
					ESB_TOTAL_CURRENT_INDEX, ESB_TOTAL_CURRENT_SUBINDEX),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_GLOW_STATUS_INDEX, ESB_GLOW_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_STARTER_STATUS_INDEX, ESB_STARTER_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_AC_STATUS_INDEX, ESB_AC_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_ENGINE_MAIN_STATUS_INDEX, ESB_ENGINE_MAIN_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_ENGINE_START_STATUS_INDEX, ESB_ENGINE_START_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_PUMP_STATUS_INDEX, ESB_PUMP_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_ENGINE_IG_STATUS_INDEX, ESB_ENGINE_IG_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_OILCOOLER_STATUS_INDEX, ESB_OILCOOLER_STATUS_SUBINDEX)),
				uv_canopen_sdo_read16(ESB_NODE_ID, ESB_PUMP_ANGLE_INDEX,
						ESB_PUMP_ANGLE_SUBINDEX));
		uv_ui_refresh(&this->row2_values);
		char stop_cause[32] = { '\0' };
		uint8_t cause = uv_canopen_sdo_read8(ESB_NODE_ID,
				ESB_ENGINE_STOP_CAUSE_INDEX, ESB_ENGINE_STOP_CAUSE_SUBINDEX);
		if (cause == ESB_STOP_OIL_PRESS) {
			strcpy(stop_cause, "Oil");
		}
		else if (cause == ESB_STOP_WATER_TEMP) {
			strcpy(stop_cause, "Water");
		}
		else if (cause == ESB_STOP_SOLENOID1_OVERCURRENT) {
			strcpy(stop_cause, "Sol1");
		}
		else if (cause == ESB_STOP_SOLENOID2_OVERCURRENT) {
			strcpy(stop_cause, "Sol2");
		}
		else if (cause == ESB_STOP_FSB_DISCONNECTED) {
			strcpy(stop_cause, "FSB");
		}
		else if (cause == ESB_STOP_EMCY) {
			strcpy(stop_cause, "EMCY");
		}
		else if (cause == ESB_STOP_IGNKEY) {
			strcpy(stop_cause, "key");
		}
		else {
			strcpy(stop_cause, "None");
		}
		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%s\n%s",
				uv_canopen_sdo_read16(ESB_NODE_ID,
						ESB_RPM_INDEX, ESB_RPM_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_ALT_L_INDEX, ESB_ALT_L_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_ENGINE_MAIN_INPUT_INDEX, ESB_ENGINE_MAIN_INPUT_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_ENGINE_START_INPUT_INDEX, ESB_ENGINE_START_INPUT_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_MOTOR_TEMP_INDEX, ESB_MOTOR_TEMP_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_OIL_TEMP_INDEX, ESB_OIL_TEMP_SUBINDEX),
				uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_OIL_LEVEL_INDEX, ESB_OIL_LEVEL_SUBINDEX),
				uv_canopen_sdo_read16(ESB_NODE_ID,
						ESB_VDD_INDEX, ESB_VDD_SUBINDEX),
				get_output_state_str(uv_canopen_sdo_read8(ESB_NODE_ID,
						ESB_RADIATOR_STATUS_INDEX, ESB_RADIATOR_STATUS_SUBINDEX)),
				stop_cause);
		uv_ui_refresh(&this->row3_values);
		update_netdev(&dspl.network.esb);
	}
	else if (dev == FSB) {
		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%s\n%s\n%s\n%s\n%s\n%s",
				uv_canopen_sdo_read16(FSB_NODE_ID,
						FSB_TOTAL_CURRENT_INDEX, FSB_TOTAL_CURRENT_SUBINDEX),
				get_output_state_str(uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_HORN_STATUS_INDEX, FSB_HORN_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_RADIO_STATUS_INDEX, FSB_RADIO_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_AUX_STATUS_INDEX, FSB_AUX_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_HEATER1_STATUS_INDEX, FSB_HEATER1_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_HEATER2_STATUS_INDEX, FSB_HEATER2_STATUS_SUBINDEX)),
				get_output_state_str(uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_COOLAIR_STATE_INDEX, FSB_COOLAIR_STATE_SUBINDEX)));
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
				"%s\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i",
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
						FSB_DOORSW2_INDEX, FSB_DOORSW2_SUBINDEX),
				uv_canopen_sdo_read8(FSB_NODE_ID,
						FSB_FUEL_LEVEL_INDEX, FSB_FUEL_LEVEL_SUBINDEX));
		uv_ui_refresh(&this->row3_values);

		update_netdev(&dspl.network.fsb);

	}
	else if (dev == CSB) {

		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
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
	else if (dev == HCU) {
		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i",
				uv_canopen_sdo_read8(HCU_NODE_ID, HCU_IMPLEMENT_INDEX, HCU_IMPLEMENT_SUBINDEX),
				uv_canopen_sdo_read8(HCU_NODE_ID, HCU_LEFT_FOOT_STATE_INDEX, HCU_LEFT_FOOT_STATE_SUBINDEX),
				uv_canopen_sdo_read8(HCU_NODE_ID, HCU_RIGHT_FOOT_STATE_INDEX, HCU_RIGHT_FOOT_STATE_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_PRESSURE_INDEX, HCU_PRESSURE_SUBINDEX));
		uv_ui_refresh(&this->row2_values);
		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i",
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_BOOM_LIFT_CURRENT_INDEX, HCU_BOOM_LIFT_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_BOOM_FOLD_CURRENT_INDEX, HCU_BOOM_FOLD_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_BOOM_ROTATE_CURRENT_INDEX, HCU_BOOM_ROTATE_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_BOOM_TELESCOPE_CURRENT_INDEX, HCU_BOOM_TELESCOPE_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_LEFT_FOOT_CURRENT_INDEX, HCU_LEFT_FOOT_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_RIGHT_FOOT_CURRENT_INDEX, HCU_RIGHT_FOOT_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_ROTATOR_CURRENT_INDEX, HCU_ROTATOR_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_IMPL1_CURRENT_INDEX, HCU_IMPL1_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_IMPL2_CURRENT1_INDEX, HCU_IMPL2_CURRENT1_SUBINDEX) +
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_IMPL2_CURRENT2_INDEX, HCU_IMPL2_CURRENT2_SUBINDEX) +
				(int16_t) uv_canopen_sdo_read16(HCU_NODE_ID, HCU_D4WD_CURRENT_INDEX, HCU_D4WD_CURRENT_SUBINDEX));

		uv_ui_refresh(&this->row3_values);
		update_netdev(&dspl.network.hcu);
	}
	else if (dev == CCU) {
			snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
					"%s\n%s\n%i\n%i",
					(uv_canopen_sdo_read8(CCU_NODE_ID, CCU_CABROT_DIR_INDEX, CCU_CABROT_DIR_SUBINDEX) == CCU_CABDIR_FORWARD) ?
							"WORK" : "DRIVE",
					get_output_state_str(uv_canopen_sdo_read8(CCU_NODE_ID, CCU_BOOM_VDD_STATE_INDEX, CCU_BOOM_VDD_STATE_SUBINDEX)),
					(int16_t) uv_canopen_sdo_read16(CCU_NODE_ID, CCU_BOOM_VDD_CURRENT_INDEX, CCU_BOOM_VDD_CURRENT_SUBINDEX),
					uv_canopen_sdo_read8(CCU_NODE_ID, CCU_GEAR_INDEX, CCU_GEAR_SUBINDEX) + 1);
			uv_ui_refresh(&this->row2_values);
			snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
					"%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i",
					(int16_t) uv_canopen_sdo_read16(CCU_NODE_ID, CCU_DRIVE_CURRENT1_INDEX, CCU_DRIVE_CURRENT1_SUBINDEX),
					(int16_t) uv_canopen_sdo_read16(CCU_NODE_ID, CCU_DRIVE_CURRENT2_INDEX, CCU_DRIVE_CURRENT2_SUBINDEX),
					(int16_t) uv_canopen_sdo_read16(CCU_NODE_ID, CCU_DRIVE_CURRENT3_INDEX, CCU_DRIVE_CURRENT3_SUBINDEX),
					(int16_t) uv_canopen_sdo_read16(CCU_NODE_ID, CCU_BRAKE_CURRENT_INDEX, CCU_BOOM_VDD_CURRENT_SUBINDEX),
					(int16_t) uv_canopen_sdo_read16(CCU_NODE_ID, CCU_CABBRAKE_CURRENT_INDEX, CCU_CABBRAKE_CURRENT_SUBINDEX),
					(int16_t) uv_canopen_sdo_read16(CCU_NODE_ID, CCU_CABROT_CURRENT_INDEX, CCU_CABROT_CURRENT_SUBINDEX),
					(int16_t) uv_canopen_sdo_read16(CCU_NODE_ID, CCU_TELESCOPE_CURRENT_INDEX, CCU_TELESCOPE_CURRENT_SUBINDEX),
					(int16_t) uv_canopen_sdo_read16(CCU_NODE_ID, CCU_STEER_CURRENT_INDEX, CCU_STEER_CURRENT_SUBINDEX),
					(int16_t) uv_canopen_sdo_read16(CCU_NODE_ID, CCU_D4WD_REQ_INDEX, CCU_D4WD_REQ_SUBINDEX));
			uv_ui_refresh(&this->row3_values);
			update_netdev(&dspl.network.ccu);
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
				"%i\n%i", pedal_get_value1(&dspl.network.pedal), pedal_get_value2(&dspl.network.pedal));
		uv_ui_refresh(&this->row2_values);
		strcpy(this->row3_val_str, "");
		uv_ui_refresh(&this->row3_values);
		update_netdev(&dspl.network.pedal);
	}
	else if (dev == ICU) {
		sprintf(this->row2_val_str, "%i\n%i\n%i\n%i\n%i\n%i\n%i",
				(int32_t) uv_canopen_sdo_read32(ICU_NODE_ID, ICU_LENGTH_UM_INDEX, ICU_LENGTH_UM_SUBINDEX) / 1000,
				(int16_t) uv_canopen_sdo_read16(ICU_NODE_ID, ICU_WIDTH_MM_INDEX, ICU_WIDTH_MM_SUBINDEX),
				(int32_t) uv_canopen_sdo_read32(ICU_NODE_ID, ICU_VOL_DM3_INDEX, ICU_VOL_DM3_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(ICU_NODE_ID, ICU_WIDTH_REL_INDEX, ICU_WIDTH_REL_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(ICU_NODE_ID, ICU_WIDTH_RAW1_INDEX, ICU_WIDTH_RAW1_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(ICU_NODE_ID, ICU_WIDTH_RAW2_INDEX, ICU_WIDTH_RAW2_SUBINDEX),
				(int8_t) uv_canopen_sdo_read8(ICU_NODE_ID, ICU_SAW_IN_INDEX, ICU_SAW_IN_SUBINDEX));
		uv_ui_refresh(&this->row2_values);
		sprintf(this->row3_val_str, "%i\n%i\n%i\n%i\n%i\n%i\n%s",
				(int16_t) uv_canopen_sdo_read16(ICU_NODE_ID, ICU_BLADEOPEN_CURRENT_INDEX, ICU_BLADEOPEN_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(ICU_NODE_ID, ICU_FEEDOPEN_CURRENT_INDEX, ICU_FEEDOPEN_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(ICU_NODE_ID, ICU_TILT_CURRENT_INDEX, ICU_TILT_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(ICU_NODE_ID, ICU_SAW_CURRENT_INDEX, ICU_SAW_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(ICU_NODE_ID, ICU_FEED_CURRENT_INDEX, ICU_FEED_CURRENT_SUBINDEX),
				(int16_t) uv_canopen_sdo_read16(ICU_NODE_ID, ICU_TILTFLOAT_CURRENT_INDEX, ICU_TILTFLOAT_CURRENT_SUBINDEX),
				(uv_canopen_sdo_read8(ICU_NODE_ID, ICU_TILT_DIR_INDEX, ICU_TILT_DIR_SUBINDEX) == ICU_TILT_DIR_UP) ?
						"UP" : "DOWN");
		uv_ui_refresh(&this->row3_values);
		update_netdev(&dspl.network.icu);
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
			C(0xFFFFFFFF), uv_str(STR_SYSTEM_DIAG_LABELNETDEV));
	uv_uitreeobject_add(obj, &this->row1_topics, bb.x, bb.y,
			bb.width * labelscale, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row1_values, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			uv_uistyles[0].window_c, this->row1_val_str);
	uv_uitreeobject_add(obj, &this->row1_values, bb.x + bb.width * (labelscale - 1.0f),
			bb.y, bb.width * valuescale, bb.height);


	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row2_topics, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			C(0xFFFFFFFF), uv_str(labels[this->dev].row2));
	uv_uitreeobject_add(obj, &this->row2_topics, bb.x, bb.y, bb.width * labelscale, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row2_values, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			uv_uistyles[0].window_c, this->row2_val_str);
	uv_uitreeobject_add(obj, &this->row2_values, bb.x + bb.width * (labelscale - 1.0f),
			bb.y, bb.width * valuescale, bb.height);


	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row3_topics, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			C(0xFFFFFFFF), uv_str(labels[this->dev].row3));
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

