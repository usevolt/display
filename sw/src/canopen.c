/*
 * dspl_canopen.c
 *
 *  Created on: Mar 15, 2016
 *      Author: usevolt
 */

#include <canopen.h>
#include <uv_canopen.h>
#include "can_display.h"
#include "can_keypad.h"
#include "can_pedal.h"
#include "can_esb.h"
#include "can_fsb.h"
#include "can_csb.h"
#include "can_hcu.h"
#include "can_ccu.h"
#include "can_icu.h"


extern dspl_st dspl;

const canopen_object_st obj_dict[] = {
		{
				.main_index = DSPL_LKEYP_OFFSET + KEYP_JOYX_INDEX,
				.array_max_size = KEYP_JOYX_ARRAY_MAX_SIZE,
				.permissions = CANOPEN_WO,
				.type = KEYP_JOYX_TYPE,
				.data_ptr = (void*) &dspl.network.l_keypad.x
		},
		{
				.main_index = DSPL_LKEYP_OFFSET + KEYP_JOYY_INDEX,
				.array_max_size = KEYP_JOYY_ARRAY_MAX_SIZE,
				.permissions = CANOPEN_WO,
				.type = KEYP_JOYY_TYPE,
				.data_ptr = (void*) &dspl.network.l_keypad.y
		},
		{
				.main_index = DSPL_LKEYP_OFFSET + KEYP_JOYZ_INDEX,
				.array_max_size = KEYP_JOYZ_ARRAY_MAX_SIZE,
				.permissions = CANOPEN_WO,
				.type = KEYP_JOYZ_TYPE,
				.data_ptr = (void*) &dspl.network.l_keypad.z
		},
		{
				.main_index = DSPL_LKEYP_OFFSET + KEYP_JOYV_INDEX,
				.array_max_size = KEYP_JOYV_ARRAY_MAX_SIZE,
				.permissions = CANOPEN_WO,
				.type = KEYP_JOYV_TYPE,
				.data_ptr = (void*) &dspl.network.l_keypad.v
		},
		{
				.main_index = DSPL_LKEYP_OFFSET + KEYP_BUTTON1_INDEX,
				.array_max_size = KEYP_BUTTON_COUNT,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) dspl.network.l_keypad.b
		},
		{
				.main_index = DSPL_RKEYP_OFFSET + KEYP_JOYX_INDEX,
				.array_max_size = KEYP_JOYX_ARRAY_MAX_SIZE,
				.permissions = CANOPEN_WO,
				.type = KEYP_JOYX_TYPE,
				.data_ptr = (void*) &dspl.network.r_keypad.x
		},
		{
				.main_index = DSPL_RKEYP_OFFSET + KEYP_JOYY_INDEX,
				.array_max_size = KEYP_JOYY_ARRAY_MAX_SIZE,
				.permissions = CANOPEN_WO,
				.type = KEYP_JOYY_TYPE,
				.data_ptr = (void*) &dspl.network.r_keypad.y
		},
		{
				.main_index = DSPL_RKEYP_OFFSET + KEYP_JOYZ_INDEX,
				.array_max_size = KEYP_JOYZ_ARRAY_MAX_SIZE,
				.permissions = CANOPEN_WO,
				.type = KEYP_JOYZ_TYPE,
				.data_ptr = (void*) &dspl.network.r_keypad.z
		},
		{
				.main_index = DSPL_RKEYP_OFFSET + KEYP_JOYV_INDEX,
				.array_max_size = KEYP_JOYV_ARRAY_MAX_SIZE,
				.permissions = CANOPEN_WO,
				.type = KEYP_JOYV_TYPE,
				.data_ptr = (void*) &dspl.network.r_keypad.v
		},
		{
				.main_index = DSPL_RKEYP_OFFSET + KEYP_BUTTON1_INDEX,
				.array_max_size = KEYP_BUTTON_COUNT,
				.permissions = CANOPEN_WO,
				.type = CANOPEN_ARRAY8,
				.data_ptr = (void*) dspl.network.r_keypad.b
		},
		{
				.main_index = DSPL_PEDAL_OFFSET + DSPL_PEDAL_VALUE_INDEX,
				.array_max_size = DSPL_PEDAL_VALUE_ARRAY_SIZE,
				.permissions = DSPL_PEDAL_VALUE_PERMISSIONS,
				.type = DSPL_PEDAL_VALUE_TYPE,
				.data_ptr = (void*) dspl.network.pedal.value
		},
		{
				.main_index = DSPL_ESB_OFFSET + ESB_TOTAL_CURRENT_INDEX,
				.sub_index = ESB_TOTAL_CURRENT_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = ESB_TOTAL_CURRENT_TYPE,
				.data_ptr = (void*) &dspl.network.esb.total_current
		},
		{
				.main_index = DSPL_ESB_OFFSET + ESB_RPM_INDEX,
				.sub_index = ESB_RPM_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = ESB_RPM_TYPE,
				.data_ptr = (void*) &dspl.network.esb.rpm
		},
		{
				.main_index = DSPL_ESB_OFFSET + ESB_ALT_L_INDEX,
				.sub_index = ESB_ALT_L_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = ESB_ALT_L_TYPE,
				.data_ptr = (void*) &dspl.network.esb.alt_l
		},
		{
				.main_index = DSPL_ESB_OFFSET + ESB_MOTOR_WATER_TEMP_INDEX,
				.sub_index = ESB_MOTOR_WATER_TEMP_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = ESB_MOTOR_WATER_TEMP_TYPE,
				.data_ptr = (void*) &dspl.network.esb.motor_water
		},
		{
				.main_index = DSPL_ESB_OFFSET + ESB_MOTOR_OIL_PRESS_INDEX,
				.sub_index = ESB_MOTOR_OIL_PRESS_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = ESB_MOTOR_OIL_PRESS_TYPE,
				.data_ptr = (void*) &dspl.network.esb.motor_oil_press
		},
		{
				.main_index = DSPL_ESB_OFFSET + ESB_MOTOR_TEMP_INDEX,
				.sub_index = ESB_MOTOR_TEMP_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = ESB_MOTOR_TEMP_TYPE,
				.data_ptr = (void*) &dspl.network.esb.motor_temp
		},
		{
				.main_index = DSPL_ESB_OFFSET + ESB_OIL_TEMP_INDEX,
				.sub_index = ESB_OIL_TEMP_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = ESB_OIL_TEMP_TYPE,
				.data_ptr = (void*) &dspl.network.esb.oil_temp
		},
		{
				.main_index = DSPL_ESB_OFFSET + ESB_OIL_LEVEL_INDEX,
				.sub_index = ESB_OIL_LEVEL_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = ESB_OIL_LEVEL_TYPE,
				.data_ptr = (void*) &dspl.network.esb.oil_level
		},
		{
				.main_index = DSPL_ESB_OFFSET + ESB_VDD_INDEX,
				.sub_index = ESB_VDD_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = ESB_VDD_TYPE,
				.data_ptr = (void*) &dspl.network.esb.voltage
		},
		{
				.main_index = DSPL_FSB_OFFSET + FSB_TOTAL_CURRENT_INDEX,
				.sub_index = FSB_TOTAL_CURRENT_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = FSB_TOTAL_CURRENT_TYPE,
				.data_ptr = (void*) &dspl.network.fsb.total_current
		},
		{
				.main_index = DSPL_FSB_OFFSET + FSB_FUEL_LEVEL_INDEX,
				.sub_index = FSB_FUEL_LEVEL_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = FSB_FUEL_LEVEL_TYPE,
				.data_ptr = (void*) &dspl.network.fsb.fuel_level
		},
		{
				.main_index = DSPL_FSB_OFFSET + FSB_IGNKEY_INDEX,
				.sub_index = FSB_IGNKEY_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = FSB_IGNKEY_TYPE,
				.data_ptr = (void*) &dspl.network.fsb.ignkey
		},
		{
				.main_index = DSPL_FSB_OFFSET + FSB_EMCY_INDEX,
				.sub_index = FSB_EMCY_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = FSB_EMCY_TYPE,
				.data_ptr = (void*) &dspl.network.fsb.emcy
		},
		{
				.main_index = DSPL_FSB_OFFSET + FSB_DOORSW1_INDEX,
				.sub_index = FSB_DOORSW1_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = FSB_DOORSW1_TYPE,
				.data_ptr = (void*) &dspl.network.fsb.doorsw1
		},
		{
				.main_index = DSPL_FSB_OFFSET + FSB_DOORSW2_INDEX,
				.sub_index = FSB_DOORSW2_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = FSB_DOORSW2_TYPE,
				.data_ptr = (void*) &dspl.network.fsb.doorsw2
		},
		{
				.main_index = DSPL_FSB_OFFSET + FSB_SEATSW_INDEX,
				.sub_index = FSB_SEATSW_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = FSB_SEATSW_TYPE,
				.data_ptr = (void*) &dspl.network.fsb.seatsw
		},
		{
				.main_index = DSPL_FSB_OFFSET + FSB_HEATER_SPEED_INDEX,
				.sub_index = FSB_HEATER_SPEED_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = FSB_HEATER_SPEED_TYPE,
				.data_ptr = (void*) &dspl.network.fsb.heater_speed
		},
		{
				.main_index = DSPL_CSB_OFFSET + CSB_TOTAL_CURRENT_INDEX,
				.sub_index = CSB_TOTAL_CURRENT_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = CSB_TOTAL_CURRENT_TYPE,
				.data_ptr = (void*) &dspl.network.csb.total_current
		},
		{
				.main_index = DSPL_CSB_OFFSET + CSB_WIPER_SPEED_INDEX,
				.sub_index = CSB_WIPER_SPEED_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = CSB_WIPER_SPEED_TYPE,
				.data_ptr = (void*) &dspl.network.csb.wiper_speed
		},
		{
				.main_index = DSPL_HCU_OFFSET + HCU_TOTAL_CURRENT_INDEX,
				.sub_index = HCU_TOTAL_CURRENT_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = HCU_TOTAL_CURRENT_TYPE,
				.data_ptr = (void*) &dspl.network.hcu.total_current
		},
		{
				.main_index = DSPL_HCU_OFFSET + HCU_IMPLEMENT_INDEX,
				.sub_index = HCU_IMPLEMENT_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = HCU_IMPLEMENT_TYPE,
				.data_ptr = (void*) &dspl.network.hcu.implement
		},
		{
				.main_index = DSPL_HCU_OFFSET + HCU_PRESSURE_INDEX,
				.sub_index = HCU_PRESSURE_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = HCU_PRESSURE_TYPE,
				.data_ptr = (void*) &dspl.network.hcu.pressure
		},
		{
				.main_index = DSPL_CCU_OFFSET + CCU_TOTAL_CURRENT_INDEX,
				.sub_index = CCU_TOTAL_CURRENT_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = CCU_TOTAL_CURRENT_TYPE,
				.data_ptr = (void*) &dspl.network.ccu.total_current
		},
		{
				.main_index = DSPL_CCU_OFFSET + CCU_GEAR_INDEX,
				.sub_index = CCU_GEAR_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = CCU_GEAR_TYPE,
				.data_ptr = (void*) &dspl.network.ccu.gear
		},
		{
				.main_index = DSPL_ICU_OFFSET + ICU_TOTAL_CURRENT_INDEX,
				.sub_index = ICU_TOTAL_CURRENT_SUBINDEX,
				.permissions = CANOPEN_WO,
				.type = ICU_TOTAL_CURRENT_TYPE,
				.data_ptr = (void*) &dspl.network.icu.total_current
		},
		{
				.main_index = DSPL_ICU_OFFSET + ICU_LENGTH_UM_INDEX,
				.sub_index = ICU_LENGTH_UM_SUBINDEX,
				.permissions = CANOPEN_RW,
				.type = ICU_LENGTH_UM_TYPE,
				.data_ptr = (void*) &dspl.network.icu.length_um
		}
};




unsigned int object_dictionary_size(void) {
	return sizeof(obj_dict) / sizeof(canopen_object_st);
}


