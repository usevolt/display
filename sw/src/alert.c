/*
 * alert.c
 *
 *  Created on: Oct 15, 2016
 *      Author: usevolt
 */


#include "alert.h"
#include "pin_mappings.h"


#define this (me)


void alert_init(alert_st *me) {
	this->current_alert = ALERT_NONE;
}

void alert_reset(alert_st *me) {
	alert_init(this);
	this->volume = 100;
}


void alert_step(alert_st *me, unsigned int step_ms) {

	switch(this->current_alert) {
	case ALERT_NOTIFY:
		if (uv_delay(step_ms, &this->delay)) {
			uv_pwm_set(BUZZER, DUTY_CYCLE(
					(this->second_delay % 2) ? ((float) this->volume / 200) : 0.0f ));
			this->second_delay++;
			if (this->second_delay == 3) {
				alert_stop(this);
			}
			else {
				uv_delay_init(ALERT_NOTIFY_CYCLE_MS, &this->delay);
			}
		}
		break;
	case ALERT_WARNING:
		if (uv_delay(step_ms, &this->delay)) {
			uv_pwm_set(BUZZER, DUTY_CYCLE(
					(this->second_delay % 2) ? ((float) this->volume / 200) : 0.0f ));
			this->second_delay++;
			if (this->second_delay == 5) {
				alert_stop(this);
			}
			else {
				uv_delay_init((this->second_delay % 2) ? ALERT_WARNING_CYCLE_MS / 2 : ALERT_WARNING_CYCLE_MS,
						&this->delay);
			}
		}
		break;
	case ALERT_FATAL_WARNING:
		if (uv_delay(step_ms, &this->delay)) {
			uv_pwm_set(BUZZER, DUTY_CYCLE(
					(this->second_delay % 2) ? ((float) this->volume / 200) : 0.0f ));
			this->second_delay++;
			uv_delay_init((this->second_delay % 2) ? ALERT_FATAL_WARNING_CYCLE_MS / 2 : ALERT_FATAL_WARNING_CYCLE_MS,
					&this->delay);
		}
		break;
	default:
		break;
	}
}


void alert_stop(alert_st *me) {
	this->current_alert = ALERT_NONE;
	uv_pwm_set(BUZZER, DUTY_CYCLE(0.0f));
}


void alert_play(alert_st *me, alerts_e alert) {
	this->current_alert = alert;
	switch (alert) {
	case ALERT_NOTIFY:
		uv_delay_init(ALERT_NOTIFY_CYCLE_MS, &this->delay);
		this->second_delay = 0;
		uv_pwm_set(BUZZER, DUTY_CYCLE((float) this->volume / 200));
		break;
	case ALERT_WARNING:
		uv_delay_init(ALERT_WARNING_CYCLE_MS, &this->delay);
		this->second_delay = 0;
		uv_pwm_set(BUZZER, DUTY_CYCLE((float) this->volume / 200));
		break;
	case ALERT_FATAL_WARNING:
		uv_delay_init(ALERT_FATAL_WARNING_CYCLE_MS, &this->delay);
		this->second_delay = 0;
		uv_pwm_set(BUZZER, DUTY_CYCLE((float) this->volume / 200));
		break;
	default:
		alert_stop(this);
		break;
	}
}


void alert_set_volume(alert_st *me, uint16_t volume) {
	if (volume <= 100) this->volume = volume;
}


uint16_t alert_get_volume(alert_st *me) {
	return this->volume;
}
