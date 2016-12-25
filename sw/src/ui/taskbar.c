/*
 * taskbar.c
 *
 *  Created on: Sep 30, 2016
 *      Author: usevolt
 */


#include "taskbar.h"
#include "gui.h"
#include "msb.h"

#define this (&gui.taskbar)


#define LEVEL_PB_WIDTH	30

#define WARNING_COLOR C(0xFF0000)

void taskbar_init(uv_uidisplay_st *display) {
	uv_uiwindow_init(&this->taskbar, this->taskbar_buffer, &uv_uistyles[TASKBAR_STYLE_INDEX]);
	uv_uidisplay_add(display, &this->taskbar,
			0, LCD_H(0.88f), LCD_W(1.0f), LCD_H(0.12f), uv_uiwindow_step);

	uv_uilabel_init(&this->clock, &UI_FONT_BIG, ALIGN_CENTER_RIGHT,
			C(0xFFFFFF), C(0xFFFFFFFF), "12:00");
	uv_uiwindow_add(&this->taskbar, &this->clock,
			uv_ui_get_bb(&this->taskbar)->width - UI_FONT_SMALL.char_width * 5, 0,
			UI_FONT_SMALL.char_width * 5,
			uv_ui_get_bb(&this->taskbar)->height, uv_uilabel_step);

	// Motor temp
	uv_uilabel_init(&this->mtemp, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Motor T");
	uv_uiwindow_add(&this->taskbar, &this->mtemp,
			uv_uibb(&this->clock)->x - uv_uibb(&this->clock)->width - LEVEL_PB_WIDTH - 30,
			uv_uibb(&this->taskbar)->height - UI_FONT_SMALL.char_height,
			LEVEL_PB_WIDTH,
			UI_FONT_SMALL.char_height,
			uv_uilabel_step);

	uv_uiprogressbar_init(&this->mtemp_bar, &uv_uistyles[0], 0, 100);
	uv_uiprogressbar_set_vertical(&this->mtemp_bar);
	uv_uiprogressbar_set_value(&this->mtemp_bar, msb_get_motor_temp(&dspl.network.msb));
	uv_uiprogressbar_set_limit(&this->mtemp_bar, UI_PROGRESSBAR_LIMIT_OVER,
			MOTOR_TEMP_WARNING_LIMIT, WARNING_COLOR);
	uv_uiwindow_add(&this->taskbar, &this->mtemp_bar,
			uv_uibb(&this->mtemp)->x, 0,
			LEVEL_PB_WIDTH, uv_uibb(&this->mtemp)->y - 4, uv_uiprogressbar_step);

	// Oil temp
	uv_uilabel_init(&this->otemp, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Oil T");
	uv_uiwindow_add(&this->taskbar, &this->otemp,
			uv_uibb(&this->mtemp)->x - LEVEL_PB_WIDTH - 30,
			uv_uibb(&this->taskbar)->height - UI_FONT_SMALL.char_height,
			LEVEL_PB_WIDTH,
			UI_FONT_SMALL.char_height,
			uv_uilabel_step);

	uv_uiprogressbar_init(&this->otemp_bar, &uv_uistyles[0], 0, 100);
	uv_uiprogressbar_set_value(&this->otemp_bar, msb_get_oil_temp(&dspl.network.msb));
	uv_uiprogressbar_set_vertical(&this->otemp_bar);
	uv_uiprogressbar_set_limit(&this->otemp_bar, UI_PROGRESSBAR_LIMIT_OVER,
			OIL_TEMP_WARNING_LIMIT, WARNING_COLOR);
	uv_uiwindow_add(&this->taskbar, &this->otemp_bar,
			uv_uibb(&this->otemp)->x, 0,
			LEVEL_PB_WIDTH, uv_uibb(&this->otemp)->y - 4, uv_uiprogressbar_step);

	// Oil level
	uv_uilabel_init(&this->oil, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Oil L");
	uv_uiwindow_add(&this->taskbar, &this->oil,
			uv_uibb(&this->otemp)->x - LEVEL_PB_WIDTH - 30,
			uv_uibb(&this->taskbar)->height - UI_FONT_SMALL.char_height,
			LEVEL_PB_WIDTH,
			UI_FONT_SMALL.char_height,
			uv_uilabel_step);

	uv_uiprogressbar_init(&this->oil_level, &uv_uistyles[0], 0, 100);
	uv_uiprogressbar_set_value(&this->oil_level, msb_get_oil_level(&dspl.network.msb));
	uv_uiprogressbar_set_vertical(&this->oil_level);
	uv_uiprogressbar_set_limit(&this->oil_level, UI_PROGRESSBAR_LIMIT_UNDER,
			OIL_LEVEL_WARNING_LIMIT, WARNING_COLOR);
	uv_uiwindow_add(&this->taskbar, &this->oil_level,
			uv_uibb(&this->oil)->x, 0,
			LEVEL_PB_WIDTH, uv_uibb(&this->oil)->y - 4, uv_uiprogressbar_step);

	// Fuel level
	uv_uilabel_init(&this->fuel, &UI_FONT_SMALL, ALIGN_BOTTOM_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Fuel L");
	uv_uiwindow_add(&this->taskbar, &this->fuel,
			uv_uibb(&this->oil)->x - LEVEL_PB_WIDTH - 30,
			uv_uibb(&this->taskbar)->height - UI_FONT_SMALL.char_height,
			LEVEL_PB_WIDTH,
			UI_FONT_SMALL.char_height,
			uv_uilabel_step);

	uv_uiprogressbar_init(&this->fuel_level, &uv_uistyles[0], 0, 100);
	uv_uiprogressbar_set_value(&this->fuel_level, msb_get_fuel_level(&dspl.network.msb));
	uv_uiprogressbar_set_vertical(&this->fuel_level);
	uv_uiprogressbar_set_limit(&this->fuel_level, UI_PROGRESSBAR_LIMIT_UNDER,
			FUEL_LEVEL_WARNING_LIMIT, WARNING_COLOR);
	uv_uiwindow_add(&this->taskbar, &this->fuel_level,
			uv_uibb(&this->fuel)->x, 0,
			LEVEL_PB_WIDTH, uv_uibb(&this->fuel)->y - 4, uv_uiprogressbar_step);


}

void taskbar_step(uint16_t step_ms) {
	uv_uiprogressbar_set_value(&this->oil_level, msb_get_oil_level(&dspl.network.msb));
	uv_uiprogressbar_set_value(&this->otemp_bar, msb_get_oil_temp(&dspl.network.msb));
	uv_uiprogressbar_set_value(&this->fuel_level, msb_get_fuel_level(&dspl.network.msb));
	uv_uiprogressbar_set_value(&this->mtemp_bar, msb_get_motor_temp(&dspl.network.msb));

}




