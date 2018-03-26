#pragma once
#ifndef __HASHTABLE_H
#define __HASHTABLE_H

typedef struct entry_t {
	int key;
	void* data;
	struct entry_t* chained;
} Entry;


typedef struct hashtable_t {
	Entry* table;
	int size;
} HashTable;

void insert(int key, void* data);
void* search(int key);
void remove(int key);

#endif
