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


void system_network_show(void) {
	uv_uiwindow_clear(&gui.windows.system.tabs);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_set_step_callb(&this->window, &system_network_step);
	uv_uitabwindow_add(&gui.windows.system.tabs, &this->window, 0, 0,
			uv_uibb(&gui.windows.system.tabs)->width,
			uv_uitabwindow_get_contentbb(&gui.windows.system.tabs).height);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0, uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height, 3, 3);
	uv_uigridlayout_set_padding(&grid, 20, 10);

	this->dev = DEV_NONE;

	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->msb, "MSB", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->msb, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->csb, "CSB", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->csb, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->ecu, "ECU", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->ecu, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->l_keypad, "Left Keypad", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->l_keypad, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->r_keypad, "Right Keypad", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->r_keypad, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->pedal, "Pedal", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->pedal, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->uw180s, "UW180s", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->uw180s, bb.x, bb.y, bb.width, bb.height);

	bb = uv_uigridlayout_next(&grid);
	uv_uibutton_init(&this->uw180s_mb, "UW180s MB", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->uw180s_mb, bb.x, bb.y, bb.width, bb.height);

}

typedef struct {
	const char *name;
	const char *row2;
	const char *row3;
} data_st;

static const char netdev_label[] =
		"Connected\n"
		"Node ID";

static const data_st labels[] = {
		// DEV_NONE
		{},
		// MSB
		{
				.name = "MSB",
				.row2 = "Fuel level (%)\n"
						"Oil level (%)\n"
						"Oil temp (C)\n"
						"Motor temp (C)\n"
						"Rpm\n"
						"Voltage (mV)",
				.row3 = "Glow plugs\n"
						"Starter\n"
						"Engine water\n"
						"Crane lights\n"
						"Engine oil press\n"
						"Aux\n"
		},
		// CSB
		{
				.name = "CSB",
				.row2 = "Drive light\n"
						"Work light\n"
						"Cabin light\n"
						"Beacon\n"
						"Wiper\n"
						"Oil Cooler",
				.row3 = ""
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
				.row2 = "Length\nWidth\nVolume\n",
				.row3 = ""
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
	if (dev == MSB) {
		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i",
				msb_get_fuel_level(&dspl.network.msb),
				msb_get_oil_level(&dspl.network.msb),
				msb_get_oil_temp(&dspl.network.msb),
				msb_get_motor_temp(&dspl.network.msb),
				msb_get_rpm(&dspl.network.msb),
				msb_get_voltage(&dspl.network.msb));
		uv_ui_refresh(&this->row2_values);
		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i",
				msb_get_power_glow_plugs(&dspl.network.msb),
				msb_get_power_starter(&dspl.network.msb),
				msb_get_power_engine_water(&dspl.network.msb),
				msb_get_power_crane_light(&dspl.network.msb),
				msb_get_power_engine_oil_press(&dspl.network.msb),
				msb_get_power_aux(&dspl.network.msb));
		uv_ui_refresh(&this->row3_values);
		update_netdev(&dspl.network.msb);
	}
	else if (dev == CSB) {
		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i\n%i\n%i\n%i",
				csb_get_drive_light(&dspl.network.csb),
				csb_get_work_light(&dspl.network.csb),
				csb_get_cabin_light(&dspl.network.csb),
				csb_get_beacon(&dspl.network.csb),
				csb_get_wiper(&dspl.network.csb),
				csb_get_oil_cooler(&dspl.network.csb));
		snprintf(this->row3_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN, " ");
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
				ecu_get_stop(&dspl.network.ecu),
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
		snprintf(this->row2_val_str, SYSTEM_NETWORK_ROW_VALUE_LEN,
				"%i\n%i\n%i",
				mb_get_length(&dspl.network.uw180s_mb),
				mb_get_width(&dspl.network.uw180s_mb),
				mb_get_volume(&dspl.network.uw180s_mb));
		uv_ui_refresh(&this->row2_values);
		strcpy(this->row3_val_str, "");
		uv_ui_refresh(&this->row3_values);
		update_netdev(&dspl.network.uw180s_mb);
	}
}


static void show(devices_e dev) {
	this->dev = dev;

	uv_uiwindow_clear(&this->window);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0, uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height, 6, 4);
	uv_uigridlayout_set_padding(&grid, 5, 5);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);


	uv_uibutton_init(&this->back, "Back", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->back, bb.x, bb.y, bb.width * 2, bb.height);

	uv_uilabel_init(&this->name, &UI_FONT_BIG, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), (char*) labels[dev].name);
	uv_uiwindow_add(&this->window, &this->name, uv_uibb(&this->window)->width / 2,
			bb.y, 0, bb.height);

	float labelscale = 1.6f;
	float valuescale = 2.0f - labelscale;

	uv_uilabel_init(&this->row1_topics, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			C(0xFFFFFFFF), (char*) netdev_label);
	uv_uiwindow_add(&this->window, &this->row1_topics, bb.x, bb.y + bb.height + grid.vpadding,
			bb.width * labelscale, uv_uibb(&this->window)->height - bb.y - bb.height - grid.vpadding);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row1_values, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			uv_uistyles[0].window_c, this->row1_val_str);
	uv_uiwindow_add(&this->window, &this->row1_values, bb.x + bb.width * (labelscale - 1.0f),
			bb.y + bb.height + grid.vpadding, bb.width * valuescale,
			uv_uibb(&this->window)->height - bb.y - bb.height - grid.vpadding);


	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row2_topics, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			C(0xFFFFFFFF), (char*) labels[dev].row2);
	uv_uiwindow_add(&this->window, &this->row2_topics, bb.x, bb.y + bb.height + grid.vpadding,
			bb.width * labelscale, uv_uibb(&this->window)->height - bb.y - bb.height - grid.vpadding);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row2_values, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			uv_uistyles[0].window_c, this->row2_val_str);
	uv_uiwindow_add(&this->window, &this->row2_values, bb.x + bb.width * (labelscale - 1.0f),
			bb.y + bb.height + grid.vpadding, bb.width * valuescale,
			uv_uibb(&this->window)->height - bb.y - bb.height - grid.vpadding);


	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row3_topics, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			C(0xFFFFFFFF), (char*) labels[dev].row3);
	uv_uiwindow_add(&this->window, &this->row3_topics, bb.x, bb.y + bb.height + grid.vpadding,
			bb.width * labelscale, uv_uibb(&this->window)->height - bb.y - bb.height - grid.vpadding);

	bb = uv_uigridlayout_next(&grid);
	uv_uilabel_init(&this->row3_values, &UI_FONT_SMALL, ALIGN_TOP_LEFT, C(0xFFFFFF),
			uv_uistyles[0].window_c, this->row3_val_str);
	uv_uiwindow_add(&this->window, &this->row3_values, bb.x + bb.width * (labelscale - 1.0f),
			bb.y + bb.height + grid.vpadding, bb.width * valuescale,
			uv_uibb(&this->window)->height - bb.y - bb.height - grid.vpadding);

	update(dev);
}


void system_network_step(const uint16_t step_ms) {
	if (this->dev == DEV_NONE) {
		if (uv_uibutton_clicked(&this->msb)) {
			show(MSB);
		}
		else if (uv_uibutton_clicked(&this->csb)) {
			show(CSB);
		}
		else if (uv_uibutton_clicked(&this->ecu)) {
			show(ECU);
		}
		else if (uv_uibutton_clicked(&this->r_keypad)) {
			show(R_KEYPAD);
		}
		else if (uv_uibutton_clicked(&this->l_keypad)) {
			show(L_KEYPAD);
		}
		else if (uv_uibutton_clicked(&this->pedal)) {
			show(PEDAL);
		}
		else if (uv_uibutton_clicked(&this->uw180s)) {
			show(UW180S_ECU);
		}
		else if (uv_uibutton_clicked(&this->uw180s_mb)) {
			show(UW180S_MB);
		}
	}
	else {
		if (uv_uibutton_clicked(&this->back)) {
			system_network_show();
			return;
		}
		update(this->dev);
	}
}

