/*
 * dspl_main.h
 *
 *  Created on: Mar 8, 2016
 *      Author: usevolt
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <uv_gpio.h>
#include <uv_memory.h>
#include <uv_canopen.h>
#include "network.h"


typedef struct {

	int step_delay;

	uv_data_start_t data_start;

	uv_canopen_st canopen;

	network_st network;

	uv_data_end_t data_endl;

} dspl_st;

void dspl_init(dspl_st *me);
//void dspl_step(void *me, unsigned int step_ms);
void dspl_pin_callback(void *me, uv_gpios_e pin);

void dspl_step(void *me);

#endif /* MAIN_H_ */
