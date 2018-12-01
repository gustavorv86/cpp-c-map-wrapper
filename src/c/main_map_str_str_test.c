
/* 
 * File:   main_test.c
 * Author: gustavo
 *
 * Created on 9 de noviembre de 2018, 19:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <map_str_str_c_wrapper.h>

#define STR_SIZE  64

int main(void) {
	
	char buff_key[STR_SIZE];
	char buff_value[STR_SIZE];
	
	map_str_str * map = map_str_str_new();
	
	printf("\n===== START TEST 1 =====\n");
	
	for(int i=1; i<=5; i++) {
		snprintf(buff_key, STR_SIZE, "key_%d", i);
		snprintf(buff_value, STR_SIZE, "value_%d", i);
		map_str_str_put(map, buff_key, buff_value);
	}
	
	map_str_str_erase(map, "key_3");
	
	map_str_str_dump(map);
	printf("size: %u \n", map_str_str_size(map));
	
	printf("===== END TEST 1 =====\n");
	
	printf("\n===== START TEST 2 =====\n");
	
	map_str_str_put(map, "new_key", "new_value");
	
	/**
	 * Don't try free the 'keys' and the 'value' pointer.
	 * 
	 * The reserved memory will freeing when the 'map_str_str_delete' function
	 * is called.
	 * 
	 */
	char ** keys = map_str_str_get_keys(map);
	char * value = NULL;
	int c = 0;
	while(keys[c] != NULL) {
		value = map_str_str_get(map, keys[c]);
		printf("%s => %s \n", keys[c], value);
		c++;
	}
	
	printf("size: %u \n", map_str_str_size(map));
	
	printf("===== END TEST 2 =====\n");
	
	printf("\n===== START TEST 3 =====\n");
	
	map_str_str_clear(map);
	
	keys = map_str_str_get_keys(map);
	value = NULL;
	c = 0;
	while(keys[c] != NULL) {
		value = map_str_str_get(map, keys[c]);
		printf("%s => %s \n", keys[c], value);
		c++;
	}
	
	printf("size: %u \n", map_str_str_size(map));
	
	printf("===== END TEST 3 =====\n");
	
	map_str_str_delete(map);
	
	return (EXIT_SUCCESS);
}

