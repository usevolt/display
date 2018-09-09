/*
 * dashboard.c
 *
 *  Created on: Dec 11, 2016
 *      Author: usevolt
 */


#include "dashboard.h"
#include "gui.h"
#include "home.h"
#include "tr.h"

#define this (&gui.windows.dashboard)


void dashboard_show(void) {
	uv_uiwindow_clear(&gui.main_window);
	uv_uiwindow_set_stepcallback(&gui.main_window, &dashboard_step);

	uv_uiwindow_init(&this->window, this->buffer, &uv_uistyles[WINDOW_STYLE_INDEX]);
	uv_uiwindow_add(&gui.main_window, &this->window, 0, 0,
			uv_uibb(&gui.main_window)->width, uv_uibb(&gui.main_window)->height);

	TOPIC_INIT(&this->window, &this->topic, uv_str(STR_HOME_BUTDASHBOARD));

	CANCEL_INIT(&this->window, &this->cancel);

	OK_INIT(&this->window, &this->ok);


	uv_uiwindow_init(&this->impl_window, this->impl_buffer, &uv_uistyles[0]);
	uv_uiwindow_add(&this->window, &this->impl_window, 0, TOPIC_HEIGHT,
			uv_uibb(&this->window)->width,
			uv_uibb(&this->window)->height - TOPIC_HEIGHT);

	// show the active implement's dashboard UI
	implement_st *impl = dspl_get_implement_ptr(&dspl);
	if ((impl != NULL) &&
			impl->callbacks->dashboard_show) {
		impl->callbacks->dashboard_show();
	}
}


uv_uiobject_ret_e dashboard_step(uint16_t step_ms) {
	uv_uiobject_ret_e ret = UIOBJECT_RETURN_ALIVE;

	if (uv_uibutton_clicked(&this->cancel)) {
		home_show();
		ret = UIOBJECT_RETURN_KILLED;
	}
	else if (uv_uibutton_clicked(&this->ok)) {
		uv_memory_save();
		home_show();
		ret = UIOBJECT_RETURN_KILLED;
	}
	// active implement dasboard step
	implement_st *impl = dspl_get_implement_ptr(&dspl);
	if ((impl != NULL) &&
			impl->callbacks->dasboard_step) {
		impl->callbacks->dasboard_step(step_ms);
	}
	return ret;
}
