/*
 * alert.h
 *
 *  Created on: Oct 15, 2016
 *      Author: usevolt
 */

#ifndef ALERT_H_
#define ALERT_H_


#include "uv_hal_config.h"
#include <uv_utilities.h>


#define ALERT_NOTIFY_CYCLE_MS			50
#define ALERT_WARNING_CYCLE_MS			500
#define ALERT_FATAL_WARNING_CYCLE_MS	300







typedef enum {
	ALERT_NONE = 0,
	/// @brief: Short double beep only to notify settings etc.
	ALERT_NOTIFY,
	/// @brief: Warning is a short multiple beep sequence
	ALERT_WARNING,
	/// @brief: Fatal warning is a continuous alert which stops only when new alert
	/// is played or alert_stop is called
	ALERT_FATAL_WARNING,
	ALERT_COUNT
} alerts_e;




typedef struct {
	uint16_t volume;
	alerts_e current_alert;
	int delay;
	int second_delay;
} alert_st;



void alert_init(alert_st*);

void alert_reset(alert_st*);

void alert_step(alert_st* me, unsigned int step_ms);


/// @brief: Stops playing of the current alert
void alert_stop(alert_st*);


/// @brief: Plays an alert
void alert_play(alert_st *, alerts_e);


/// @brief: Sets the volume in percents
void alert_set_volume(alert_st*, uint16_t volume);


uint16_t alert_get_volume(alert_st*);

#endif /* ALERT_H_ */
