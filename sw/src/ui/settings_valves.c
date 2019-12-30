/*
 * settings_valves.c
 *
 *  Created on: Oct 30, 2016
 *      Author: usevolt
 */


#include "settings_valves.h"
#include "main.h"
#include "gui.h"
#include "network.h"
#include "tr.h"

#define this (&gui.windows.settings.valves)

#define SLIDERS_HEIGHT		270


static void sliders_show(uv_uitreeobject_st *obj);



void settings_valves_show() {
	uv_uitabwindow_st *window = (uv_uitabwindow_st*) &gui.windows.settings.tabs;
	uv_uitabwindow_clear(window);

	uv_uitreeview_init(&this->treeview, this->treebuffer, &uv_uistyles[0]);
	uv_uitabwindow_add(window, &this->treeview, 0, 0,
			uv_uitabwindow_get_contentbb(window).width,
			uv_uitabwindow_get_contentbb(window).height);

	// read ccu assembly settings if telescope, back steer or cabrot is installed
	uint8_t ccu_assembly[CCU_ASSEMBLY_ARRAY_SIZE];
	for (uint8_t i = 0; i < CCU_ASSEMBLY_ARRAY_SIZE; i++) {
		uv_canopen_sdo_read(CCU_NODE_ID, CCU_ASSEMBLY_INDEX, i + 1,
				CANOPEN_TYPE_LEN(CCU_ASSEMBLY_TYPE), &ccu_assembly[i]);
	}
	// read hcu assembly settings to check if boom telescope is installed
	uint8_t hcu_assembly[HCU_ASSEMBLY_ARRAY_SIZE];
	for (uint8_t i = 0; i < HCU_ASSEMBLY_ARRAY_SIZE; i++) {
		uv_canopen_sdo_read(HCU_NODE_ID, HCU_ASSEMBLY_INDEX, i + 1,
				CANOPEN_TYPE_LEN(HCU_ASSEMBLY_TYPE), &hcu_assembly[i]);
	}

	for (int16_t i = 0; i < BASE_VALVE_COUNT; i++) {
		if ((dspl.user->base_valves[i].name == STR_SETTINGS_VALVES_TREECABROTATE &&
				!ccu_assembly[CCU_ASSEMBLY_CABROT_INDEX - 1]) ||
			(dspl.user->base_valves[i].name == STR_SETTINGS_VALVES_TREETELESCOPE &&
					!ccu_assembly[CCU_ASSEMBLY_TELESCOPE_INDEX - 1]) ||
			(dspl.user->base_valves[i].name == STR_SETTINGS_VALVES_TREESTEERBACK &&
					!ccu_assembly[3 - 1]) ||
			(dspl.user->base_valves[i].name == STR_SETTINGS_VALVES_TREEBOOMTELESCOPE &&
					!hcu_assembly[HCU_ASSEMBLY_BOOMTELESCOPE_INDEX - 1]) ||
			(dspl.user->base_valves[i].name == STR_SETTINGS_VALVES_TREEGEAR2 &&
					ccu_assembly[CCU_ASSEMBLY_INSTALLED_GEARS_INDEX - 1] < 2) ||
			(dspl.user->base_valves[i].name == STR_SETTINGS_VALVES_TREEGEAR3 &&
					ccu_assembly[CCU_ASSEMBLY_INSTALLED_GEARS_INDEX - 1] < 3) ||
			(dspl.user->base_valves[i].name == STR_SETTINGS_VALVES_TREESTEERBACK &&
					!ccu_assembly[CCU_ASSEMBLY_BACKSTEER_INDEX - 1]) ||
			(dspl.user->base_valves[i].name == STR_SETTINGS_VALVES_TREETCUDRIVE &&
					!netdev_get_connected(&dspl.network.tcu)) ||
			(dspl.user->base_valves[i].name == STR_SETTINGS_VALVES_TREETCUTELESCOPE &&
					!netdev_get_connected(&dspl.network.tcu))
			) {
			// jump over valves which depend on the assembly settings
			continue;
		}
		else {
			uv_uitreeobject_init(&this->valves[i], this->buffer,
					uv_str(dspl.user->base_valves[i].name), &sliders_show, &uv_uistyles[0]);
			uv_uitreeobject_set_step_callback(&this->valves[i], &settings_valves_step);
			uv_uitreeview_add(&this->treeview, &this->valves[i], SLIDERS_HEIGHT, false);
		}
	}

	this->valve = NULL;

}



static void sliders_show(uv_uitreeobject_st *obj) {
	this->valve = &dspl.user->base_valves[
					 ((unsigned int) obj - (unsigned int) &this->valves[0])
					  / sizeof(this->valves[0])];
	uv_uitreeobject_clear(obj);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0,
			uv_uitreeobject_get_content_bb(obj).width,
			uv_uitreeobject_get_content_bb(obj).height,
			3, 3);
	uv_uigridlayout_set_padding(&grid, 10, 0);
	uv_bounding_box_st bb = uv_uigridlayout_next(&grid);

	uv_uislider_init(&this->min_speed_p, 0, VALVE_MAX_CURRENT_MA / 2,
			this->valve->min_speed_p, &uv_uistyles[0]);
	uv_uislider_set_inc_step(&this->min_speed_p, 10);
	uv_uitreeobject_add(obj, &this->min_speed_p,
			bb.x, bb.y, bb.width, bb.height / 2);
	uv_uilabel_init(&this->min_speed_p_label, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), uv_str(STR_SETTINGS_VALVES_SLIDERFORMINSPEED));
	uv_uitreeobject_add(obj, &this->min_speed_p_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->max_speed_p, VALVE_MIN_CURRENT_MA, VALVE_MAX_CURRENT_MA,
			this->valve->max_speed_p, &uv_uistyles[0]);
	uv_uislider_set_inc_step(&this->max_speed_p, 25);
	uv_uitreeobject_add(obj, &this->max_speed_p,
			bb.x, bb.y, bb.width, bb.height / 2);
	uv_uilabel_init(&this->max_speed_p_label, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), uv_str(STR_SETTINGS_VALVES_SLIDERFORMAXSPEED));
	uv_uitreeobject_add(obj, &this->max_speed_p_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->acc, VALVE_ACC_MIN, 100,
			this->valve->acc, &uv_uistyles[0]);
	uv_uitreeobject_add(obj, &this->acc,
			bb.x, bb.y, bb.width, bb.height / 2);
	uv_uilabel_init(&this->acc_label, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), uv_str(STR_SETTINGS_VALVES_SLIDERACC));
	uv_uitreeobject_add(obj, &this->acc_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->min_speed_n, 0, VALVE_MAX_CURRENT_MA / 2,
			this->valve->min_speed_n, &uv_uistyles[0]);
	uv_uislider_set_inc_step(&this->min_speed_n, 10);
	uv_uitreeobject_add(obj, &this->min_speed_n,
			bb.x, bb.y, bb.width, bb.height / 2);
	uv_uilabel_init(&this->min_speed_n_label, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), uv_str(STR_SETTINGS_VALVES_SLIDERBACKMINSPEED));
	uv_uitreeobject_add(obj, &this->min_speed_n_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->max_speed_n, VALVE_MIN_CURRENT_MA, VALVE_MAX_CURRENT_MA,
			this->valve->max_speed_n, &uv_uistyles[0]);
	uv_uislider_set_inc_step(&this->max_speed_n, 25);
	uv_uitreeobject_add(obj, &this->max_speed_n,
			bb.x, bb.y, bb.width, bb.height / 2);
	uv_uilabel_init(&this->max_speed_n_label, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), uv_str(STR_SETTINGS_VALVES_SLIDERBACKMAXSPEED));
	uv_uitreeobject_add(obj, &this->max_speed_n_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2);

	bb = uv_uigridlayout_next(&grid);
	uv_uislider_init(&this->dec, VALVE_DEC_MIN, 100,
			this->valve->dec, &uv_uistyles[0]);
	uv_uitreeobject_add(obj, &this->dec,
			bb.x, bb.y, bb.width, bb.height / 2);
	uv_uilabel_init(&this->dec_label, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), uv_str(STR_SETTINGS_VALVES_SLIDERDEC));
	uv_uitreeobject_add(obj, &this->dec_label,
			bb.x, bb.y + bb.height / 2, bb.width, bb.height / 2);

	bb = uv_uigridlayout_next(&grid);
	uv_uitogglebutton_init(&this->invert,
			this->valve->invert, uv_str(STR_SETTINGS_VALVES_BUTTONINVERT), &uv_uistyles[0]);
	uv_uitreeobject_add(obj, &this->invert, bb.x, bb.y,
			bb.width, CONFIG_UI_SLIDER_WIDTH);

	bb = uv_uigridlayout_next(&grid);
	sprintf(this->assinv_str, "%s: %u", uv_str(STR_SETTINGS_VALVES_BUTTONASSINV), this->valve->assembly_invert);
	uv_uilabel_init(&this->assinv_label, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), this->assinv_str);
	uv_ui_hide(&this->assinv_label);
	uv_uitreeobject_add(obj, &this->assinv_label, bb.x, bb.y, bb.width, bb.height / 2);

	uv_uitoucharea_init(&this->assinv_touch);
	uv_uitreeobject_add(obj, &this->assinv_touch, bb.x, bb.y, bb.width, bb.height / 2);
	uv_delay_init(1000, &this->assinv_delay);

}




uv_uiobject_ret_e settings_valves_step(const uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	if (uv_uislider_value_changed(&this->max_speed_n)) {
		if (uv_uislider_get_max_value(&this->min_speed_n) > uv_uislider_get_value(&this->max_speed_n)) {
			uv_uislider_set_max_value(&this->min_speed_n, uv_uislider_get_value(&this->max_speed_n));
		}
		else {
			uv_uislider_set_max_value(&this->min_speed_n,
					uv_mini(uv_uislider_get_value(&this->max_speed_n), VALVE_MAX_CURRENT_MA / 2));
		}
		this->valve->max_speed_n = uv_uislider_get_value(&this->max_speed_n);
		this->valve->setter(this->valve);
	}
	else {
		uv_uislider_set_value(&this->max_speed_n, this->valve->max_speed_n);
	}
	if (uv_uislider_value_changed(&this->max_speed_p)) {
		if (uv_uislider_get_max_value(&this->min_speed_p) > uv_uislider_get_value(&this->max_speed_p)) {
			uv_uislider_set_max_value(&this->min_speed_p, uv_uislider_get_value(&this->max_speed_p));
		}
		else {
			uv_uislider_set_max_value(&this->min_speed_p,
					uv_mini(uv_uislider_get_value(&this->max_speed_p), VALVE_MAX_CURRENT_MA / 2));
		}
		this->valve->max_speed_p = uv_uislider_get_value(&this->max_speed_p);
		this->valve->setter(this->valve);
	}
	else {
		uv_uislider_set_value(&this->max_speed_p, this->valve->max_speed_p);
	}
	if (uv_uislider_value_changed(&this->min_speed_n)) {
		this->valve->min_speed_n = uv_uislider_get_value(&this->min_speed_n);
		this->valve->setter(this->valve);
	}
	else {
		uv_uislider_set_value(&this->min_speed_n, this->valve->min_speed_n);
	}
	if (uv_uislider_value_changed(&this->min_speed_p)) {
		this->valve->min_speed_p = uv_uislider_get_value(&this->min_speed_p);
		this->valve->setter(this->valve);
	}
	else {
		uv_uislider_set_value(&this->min_speed_p, this->valve->min_speed_p);
	}
	if (uv_uislider_value_changed(&this->acc)) {
		this->valve->acc = uv_uislider_get_value(&this->acc);
		this->valve->setter(this->valve);
	}
	else {
		uv_uislider_set_value(&this->acc, this->valve->acc);
	}
	if (uv_uislider_value_changed(&this->dec)) {
		this->valve->dec = uv_uislider_get_value(&this->dec);
		this->valve->setter(this->valve);
	}
	else {
		uv_uislider_set_value(&this->dec, this->valve->dec);
	}
	if (uv_uitogglebutton_clicked(&this->invert)) {
		this->valve->invert = uv_uitogglebutton_get_state(&this->invert);
		this->valve->setter(this->valve);
	}
	else {
		uv_uitogglebutton_set_state(&this->invert, this->valve->invert);
	}
	if (uv_uitoucharea_is_down(&this->assinv_touch, NULL, NULL)) {
		if (uv_delay(step_ms, &this->assinv_delay)) {
			this->valve->assembly_invert = !this->valve->assembly_invert;
			this->valve->setter(this->valve);
			sprintf(this->assinv_str, "%s: %u",
					uv_str(STR_SETTINGS_VALVES_BUTTONASSINV),
					this->valve->assembly_invert);
			uv_ui_show(&this->assinv_label);
		}
	}
	else {
		uv_delay_init(1000, &this->assinv_delay);
	}
	return ret;
}
