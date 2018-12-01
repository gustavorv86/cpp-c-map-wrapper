
/* 
 * File:   map_str_str_c_wrapper.h
 * Author: gustavo
 *
 * Created on 9 de noviembre de 2018, 19:52
 */

#ifndef MAP_STR_STR_C_WRAPPER_H
#define MAP_STR_STR_C_WRAPPER_H

#include <stdbool.h>

typedef void map_str_str;
typedef char * c_str;

/* constructor */
map_str_str * map_str_str_new();
/* destructor */
void map_str_str_delete(map_str_str * self);
/* methods */
void map_str_str_put(map_str_str * self, c_str key, c_str value);
unsigned int map_str_str_size(map_str_str * self);
bool map_str_str_empty(map_str_str * self);
void map_str_str_dump(map_str_str * self);
void map_str_str_erase(map_str_str * self, c_str key);
void map_str_str_clear(map_str_str * self);
c_str * map_str_str_get_keys(map_str_str * self);
c_str map_str_str_get(map_str_str * self, c_str key);

#endif
