
/* 
 * File:   map_str_str.h
 * Author: gustavo
 *
 * Created on 9 de noviembre de 2018, 19:48
 */

#ifndef MAP_STR_STR_H
#define MAP_STR_STR_H

#include <iostream>
#include <map>
#include <string>
#include <string.h>

using namespace std;

typedef char * c_str;

class map_str_str {
	private:
		map<string, string> mapper;
		c_str * key_array;
		c_str value;
		
		void delete_key_array();
		void delete_value();
		
	public:
		map_str_str();
		virtual ~map_str_str();
	
		void put(c_str key, c_str value);
		unsigned int size();
		bool empty();
		void dump();
		
		void erase(c_str key);
		void clear();
		
		c_str * get_keys();
		c_str get(c_str key);

};

#endif

