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


static void new_impl_callb(void *me, uibutton_state_e state);
static void del_impl_callb(void *me, uibutton_state_e state);


#define BW	100
#define BH	50


void settings_implements_show(void) {
	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[0]);
	uv_uiwindow_add(&gui.windows.settings.tabs, &this->window, 0, CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
			uv_uibb(&gui.windows.settings.tabs)->width,
			uv_uibb(&gui.windows.settings.tabs)->height - CONFIG_UI_TABWINDOW_HEADER_HEIGHT,
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
			DEF_IMPL_COUNT + GENERIC_IMPLEMENT_COUNT, &uv_uistyles[0]);

	// todo: Add all default implements here
	uv_uilist_push_back(&this->impls_list, dspl.user->uw180s.super.name);
	uv_uilist_push_back(&this->impls_list, dspl.user->uw40.super.name);


	int16_t i;
	for (i = 0; i < uv_vector_size(&dspl.user->generic_implements); i++) {
		uv_uilist_push_back(&this->impls_list,
			((generic_implement_st*) uv_vector_at(&dspl.user->generic_implements, i))->name);
	}

	if (dspl.user->implement == (void *) &dspl.user->uw180s) {
		uv_uilist_select(&this->impls_list, 0);
	}
	else if (dspl.user->implement == (void *) &dspl.user->uw40) {
		uv_uilist_select(&this->impls_list, 1);
	}
	else {
		for (int16_t i = 0; i < uv_vector_size(&dspl.user->generic_implements); i++) {
			if (dspl.user->implement == uv_vector_at(&dspl.user->generic_implements, i)) {
				uv_uilist_select(&this->impls_list, i);
				break;
			}
		}
	}

	uv_uiwindow_add(&this->window, &this->impls_list, bb.x, bb.y +
			uv_uibb(&this->impls_label)->height + uv_uibb(&this->impls_label)->y,
			bb.width * 2 - BW - 10, bb.height - uv_uibb(&this->impls_label)->x - uv_uibb(&this->impls_label)->height,
			uv_uilist_step);

	// new implement button
	uv_uibutton_init(&this->new_impl, "New\n\rimplement", &uv_uistyles[0], new_impl_callb);
	uv_uiwindow_add(&this->window, &this->new_impl, bb.x + bb.width * 2 - BW,
			bb.y + uv_uibb(&this->impls_label)->y + uv_uibb(&this->impls_label)->height,
			BW, BH, uv_uibutton_step);

	// delete implement button
	uv_uibutton_init(&this->del_impl, "Delete\n\rimplement", &uv_uistyles[0], del_impl_callb);
	uv_uiwindow_add(&this->window, &this->del_impl, bb.x + bb.width * 2 - BW,
			bb.y + BH + 10 + uv_uibb(&this->impls_label)->y + uv_uibb(&this->impls_label)->height,
			BW, BH, uv_uibutton_step);

}


void settings_implements_step(uint16_t step_ms) {

}



static void new_impl_callb(void *me, uibutton_state_e state) {
	char str[GENERIC_IMPLEMENT_NAME_LEN];
	if (uv_vector_size(&dspl.user->generic_implements) ==
			uv_vector_max_size(&dspl.user->generic_implements)) {
		printf("Too many implements\n\r");
		return;
	}
	if (uv_uikeyboard_show("Implement name", str,
			GENERIC_IMPLEMENT_NAME_LEN, &uv_uikeyboard_styles[0])) {
		generic_implement_st temp_impl = generic_implement;
		uv_vector_push_back(&dspl.user->generic_implements, &temp_impl);
		generic_implement_st *impl = uv_vector_at(&dspl.user->generic_implements,
				uv_vector_size(&dspl.user->generic_implements) - 1);
		strcpy(impl->name, str);
		impl->super.name = impl->name;
		log_add(LOG_IMPLEMENT_ADDED, uv_uilist_get_count(&this->impls_list) - 1);
		uv_ui_refresh(&this->impls_list);
	}

}

static void del_impl_callb(void *me, uibutton_state_e state) {
	int16_t i = uv_uislider_get_value(&this->impls_list);
	if (i < DEF_IMPL_COUNT) {
		printf("Default implements cannot be deleted\n\r");
	}
	else if (i >= uv_vector_size(&dspl.user->generic_implements)) {
		printf("Cannot delete generic implement n.o. %i\n\r", i);
	}
	else {
		uv_vector_remove(&dspl.user->generic_implements, i - DEF_IMPL_COUNT);
		if (i - DEF_IMPL_COUNT >= uv_vector_size(&dspl.user->generic_implements)) {
			dspl.user->implement = (void *) &dspl.user->uw180s;
		}
		log_add(LOG_IMPLEMENT_DELETED, i);
	}
}
