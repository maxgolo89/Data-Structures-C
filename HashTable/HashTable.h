#pragma once
#ifndef __HASHTABLE_H
#define __HASHTABLE_H

typedef struct entry_t {
	int key;
	void* data;
	struct entry_t* chained;
} Entry;

typedef struct hashtable_t {
	Entry** table;
	int size;
	int capacity;
} HashTable;

void insert(HashTable* hashTable, int key, void* data);
void insertEntry(HashTable* hashTable, Entry* entry);
void* search(HashTable* hashTable, int key);
void deleteEntry(HashTable* hashTable, int key);
int hash(HashTable* hashTable, int key);
void resize(HashTable* hashTable);
Entry* initEntry(int key, void* data);
HashTable* initHashTable();

#endif
