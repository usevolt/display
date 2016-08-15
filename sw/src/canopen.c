/*
 * dspl_canopen.c
 *
 *  Created on: Mar 15, 2016
 *      Author: usevolt
 */

#include <canopen.h>
#include <uv_canopen.h>


extern dspl_st dspl;

const uv_canopen_object_st obj_dict[] = {
};




unsigned int object_dictionary_size(void) {
	return sizeof(obj_dict) / sizeof(uv_canopen_object_st);
}


