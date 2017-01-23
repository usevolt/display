/*
 * settings_implements.c
 *
 *  Created on: Nov 3, 2016
 *      Author: usevolt
 */


#include "settings_implements.h"
#include "gui.h"
#include "vehicle.h"
#include "log.h"


#define this (&gui.windows.settings.implements)




#define BW	100
#define BH	50


void settings_implements_show(void) {
	uv_uiwindow_st *window = (uv_uiwindow_st*) &gui.windows.settings.tabs;
	uv_uiwindow_clear(window);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_add(window, &this->window, 0, CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uibb(window)->width,
			uv_uibb(window)->height - CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uiwindow_step);

	uv_uigridlayout_st grid;
	uv_uigridlayout_init(&grid, 0, 0, uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height, 3, 1);
	uv_uigridlayout_set_padding(&grid, 10, 10);
	uv_bounding_box_st bb;
	bb = uv_uigridlayout_next(&grid);

	uv_uilabel_init(&this->impls_label, &UI_FONT_SMALL, ALIGN_CENTER, C(0xFFFFFF),
			C(0xFFFFFFFF), "Active implement");
	uv_uiwindow_add(&this->window, &this->impls_label, bb.x, bb.y,
			bb.width * 2 - BW - 10, UI_FONT_SMALL.char_height * 2, uv_uilabel_step);

	uv_uilist_init(&this->impls_list, this->impl_names,
			UW_IMPLEMENT_COUNT + GENERIC_IMPLEMENT_COUNT, &uv_uistyles[0]);

	// todo: Add all default implements here
	uv_uilist_push_back(&this->impls_list, dspl.user->uw180s.super.name);
	uv_uilist_push_back(&this->impls_list, dspl.user->uw100.super.name);
	uv_uilist_push_back(&this->impls_list, dspl.user->uw50.super.name);


	int16_t i;
	for (i = 0; i < uv_vector_size(&dspl.user->generic_implements); i++) {
		uv_uilist_push_back(&this->impls_list,
			((implement_st*) uv_vector_at(&dspl.user->generic_implements, i))->name);
	}
	uv_uilist_select(&this->impls_list, dspl.user->active_implement);

	uv_uiwindow_add(&this->window, &this->impls_list, bb.x, bb.y +
			uv_uibb(&this->impls_label)->height + uv_uibb(&this->impls_label)->y,
			bb.width * 2 - BW - 10, bb.height - uv_uibb(&this->impls_label)->x - uv_uibb(&this->impls_label)->height,
			uv_uilist_step);

	// new implement button
	uv_uibutton_init(&this->new_impl, "New\n\rimplement", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->new_impl, bb.x + bb.width * 2 - BW,
			bb.y + uv_uibb(&this->impls_label)->y + uv_uibb(&this->impls_label)->height,
			BW, BH, uv_uibutton_step);

	// delete implement button
	uv_uibutton_init(&this->del_impl, "Delete\n\rimplement", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->del_impl, bb.x + bb.width * 2 - BW,
			bb.y + BH + 10 + uv_uibb(&this->impls_label)->y + uv_uibb(&this->impls_label)->height,
			BW, BH, uv_uibutton_step);

	// implement specific settings
	uv_uibutton_init(&this->impl_settings, "Implement settings", &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->impl_settings,
			uv_uibb(&this->new_impl)->x + uv_uibb(&this->new_impl)->width + 10,
			uv_uibb(&this->window)->height / 2 - BH,
			BW * 2, BH * 2, uv_uibutton_step);
	uv_ui_set_enabled(&this->impl_settings, (uv_uilist_get_selected(&this->impls_list) != -1));
	this->implement_dialog = false;
}


void settings_implements_step(uint16_t step_ms) {

	// if active implement settings dialog is visible, call it's step function.
	// otherwise continue with this module's step function.
	if (this->implement_dialog) {
		dspl.user->implement->callbacks->settings_step(step_ms);
		return;
	}

	int16_t select = uv_uilist_get_selected(&this->impls_list);
	if (select >= 0) {
		implement_set(select);
	}

	if (uv_uibutton_clicked(&this->new_impl)) {
		char str[GENERIC_IMPLEMENT_NAME_LEN];
		if (uv_vector_size(&dspl.user->generic_implements) ==
				uv_vector_max_size(&dspl.user->generic_implements)) {
			printf("Too many implements\n\r");
			return;
		}
		if (uv_uikeyboard_show("Implement name", str,
				GENERIC_IMPLEMENT_NAME_LEN, &uv_uistyles[0])) {

			generic_implement_st impl = generic_implement;
			strcpy(impl.name, str);
			uv_vector_push_back(&dspl.user->generic_implements, &impl);
			generic_implement_init(uv_vector_at(&dspl.user->generic_implements,
					uv_vector_size(&dspl.user->generic_implements) - 1));
			uv_ui_refresh(&gui.display);
			settings_implements_show();
			return;
		}
	}
	else if (uv_uibutton_clicked(&this->del_impl)) {
		int16_t i = uv_uilist_get_selected(&this->impls_list);
		if (i < UW_IMPLEMENT_COUNT) {
			printf("Default implements cannot be deleted\n\r");
		}
		else if (i - UW_IMPLEMENT_COUNT >= uv_vector_size(&dspl.user->generic_implements)) {
			printf("Cannot delete generic implement n.o. %i\n\r", i - UW_IMPLEMENT_COUNT);
		}
		else {
			uv_vector_remove(&dspl.user->generic_implements, i - UW_IMPLEMENT_COUNT, 1);
			if (i - UW_IMPLEMENT_COUNT >= uv_vector_size(&dspl.user->generic_implements)) {
				dspl.user->implement = (void *) &dspl.user->uw180s;
			}
			settings_implements_show();
			return;
		}
	}

	uv_ui_set_enabled(&this->impl_settings, dspl.user->implement ? true : false);
	if (uv_uibutton_clicked(&this->impl_settings)) {
		this->implement_dialog = true;
		dspl.user->implement->callbacks->settings_show();
	}
}

