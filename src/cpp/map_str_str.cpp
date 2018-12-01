
/* 
 * File:   map_str_str.cpp
 * Author: gustavo
 * 
 * Created on 9 de noviembre de 2018, 19:48
 */

#include "map_str_str.h"

map_str_str::map_str_str() {
	this->key_array = nullptr;
	this->value = nullptr;
}

map_str_str::~map_str_str() {
	this->delete_key_array();
	this->delete_value();
}

void map_str_str::delete_key_array() {
	if(this->key_array != nullptr) {
		int c = 0;
		while(this->key_array[c] != nullptr) {
			delete this->key_array[c];
			c++;
		}
		delete this->key_array;
		this->key_array = nullptr;
	}
}

void map_str_str::delete_value() {
	if(this->value != nullptr) {
		delete this->value;
		this->value = nullptr;
	}
}

void map_str_str::put(c_str key, c_str value) {
	string s_key(key);
	string s_value(value);
	this->mapper[s_key] = s_value;
}

unsigned int map_str_str::size() {
	return this->mapper.size();
}

bool map_str_str::empty() {
	return this->size() > 0;
}

void map_str_str::dump() {
	for(auto it = this->mapper.cbegin(); it != this->mapper.cend(); it++) {
		cout << it->first << " => " << it->second << endl;
	}
}

void map_str_str::erase(c_str key) {
	string s_key(key);
	this->mapper.erase(s_key);
}

void map_str_str::clear() {
	this->mapper.clear();
}

c_str * map_str_str::get_keys() {
	this->delete_key_array();
	
	unsigned int nkeys = this->size();
	this->key_array = new c_str[nkeys + 1];
	
	int c = 0;
	for(auto it = this->mapper.cbegin(); it != this->mapper.cend(); it++) {
		string key = it->first;
		
		unsigned int key_len = key.length();
		this->key_array[c] = new char[key_len + 1];
		strncpy(this->key_array[c], key.c_str(), key_len + 1);
		
		c++;
	}
	this->key_array[nkeys] = nullptr; // End of keys
	
	return this->key_array;
}

c_str map_str_str::get(c_str key) {
	this->delete_value();
	
	string value = this->mapper[key];
	unsigned int value_len = value.length();
	
	this->value = new char[value_len + 1];
	strncpy(this->value, value.c_str(), value_len + 1);
	
	return this->value;
}

/*----------  WRAPPER FUNCTIONS  ----------*/

extern "C" map_str_str * map_str_str_new() {
	return new map_str_str();
}

extern "C" void map_str_str_delete(map_str_str * self) {
	delete self;
}

extern "C" void map_str_str_put(map_str_str * self, c_str key, c_str value) {
	self->put(key, value);
}

extern "C" unsigned int map_str_str_size(map_str_str * self) {
	return self->size();
}

extern "C" bool map_str_str_empty(map_str_str * self) {
	return self->empty();
}

extern "C" void map_str_str_dump(map_str_str * self) {
	self->dump();
}

extern "C" void map_str_str_erase(map_str_str * self, c_str key) {
	self->erase(key);
}

extern "C" void map_str_str_clear(map_str_str * self) {
	self->clear();
}

extern "C" c_str * map_str_str_get_keys(map_str_str * self) {
	return self->get_keys();
}

extern "C" c_str map_str_str_get(map_str_str * self, c_str key) {
	return self->get(key);
}
