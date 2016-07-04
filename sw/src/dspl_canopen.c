/*
 * dspl_canopen.c
 *
 *  Created on: Mar 15, 2016
 *      Author: usevolt
 */

#include <uv_canopen.h>
#include "dspl_canopen.h"


extern dspl_const_obj_dict_st dspl_const_obj_dict;
extern dspl_st dspl;

const uv_canopen_object_st obj_dict[] = {
};




unsigned int dspl_object_dictionary_size(void) {
	return sizeof(obj_dict) / sizeof(uv_canopen_object_st);
}


