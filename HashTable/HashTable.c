#include "HashTable.h"
#include <stdlib.h>

void insert(HashTable* hashTable, int key, void* data)
{
	Entry* temp = NULL;
	int hashCode;

	// Validate hash table.
	if (hashTable == NULL || hashTable->table == NULL || hashTable->capacity < 1)
		return;

	if(hashTable->size == hashTable->capacity)
	{
		resize(hashTable);
	}

	// Compute hash
	hashCode = hash(hashTable, key);

	/* Probe entry, 
	 * if taken - chain, 
	 * else - insert */
	if(hashTable->table[hashCode] != NULL)
	{
		temp = hashTable->table[hashCode];												// Test the first
		if (temp->key == key)
			return;
		while(temp->chained != NULL)													// Test chained
		{
			temp = temp->chained;
			if (temp->key == key)
				return;
		}
		temp->chained = initEntry(key, data);											// Insert
	}
	else
	{
		hashTable->table[hashCode] = initEntry(key, data);
	}
	hashTable->size++;
}

void insertEntry(HashTable* hashTable, Entry* entry)
{
	Entry* temp = NULL;
	int hashCode = 0;

	// Validate hash table.
	if (hashTable == NULL || hashTable->table == NULL || hashTable->capacity < 1)
		return;

	if (hashTable->size == hashTable->capacity)
	{
		resize(hashTable);
	}

	// Compute hash
	hashCode = hash(hashTable, entry->key);

	/* Probe entry,
	* if taken - chain,
	* else - insert */
	if (hashTable->table[hashCode] != NULL)
	{
		temp = hashTable->table[hashCode];												// Test the first
		if (temp->key == entry->key)
			return;
		while (temp->chained != NULL)													// Test chained
		{
			temp = temp->chained;
			if (temp->key == entry->key)
				return;
		}
		temp->chained = entry;															// Insert
	}
	else
	{
		hashTable->table[hashCode] = entry;
	}
	hashTable->size++;
}

void* search(HashTable* hashTable, int key)
{
	int hashCode = 0;
	Entry* entry = NULL;
	
	// Validate hash table.
	if (hashTable == NULL || hashTable->table == NULL || hashTable->capacity < 1)
		return;

	hashCode = hash(hashTable, key);
	entry = hashTable->table[hashCode];
	if (entry->key == key)
		return entry->data;

	while(entry->chained != NULL)
	{
		entry = entry->chained;
		if (entry->key == key)
			return entry->data;
	}
	return NULL;
}

void deleteEntry(HashTable* hashTable, int key)
{
	
}

int hash(HashTable* hashTable, int key)
{
	// Validate hash table.
	if (hashTable == NULL)
		return -1;

	// Compute hash
	key = key % hashTable->capacity;

	return key;
}

void resize(HashTable* hashTable)
{
	int i, oldCapacity;
	Entry* temp = NULL;
	Entry* tempChained = NULL;
	Entry** newHashTable = NULL;
	Entry** oldHashTable = NULL;

	// Validate hash table.
	if (hashTable == NULL)
		return;
	
	oldCapacity = hashTable->capacity;										// Save old capacity
	hashTable->capacity *= 2;												// Increment capacity
	hashTable->size = 0;
	newHashTable = (Entry**)malloc(sizeof(Entry*) * hashTable->capacity);	// Allocate memory for new table
	for (i = 0; i < hashTable->capacity; i++)								// NULL pointer
	{
		newHashTable[i] = NULL;												
	}
	oldHashTable = hashTable->table;										// Save old table
	hashTable->table = newHashTable;										// Set the hashtable with new table.
	
	
	for(i = 0; i < oldCapacity; i++)										// move old entries to new table
	{
		if(oldHashTable[i] != NULL)											// Validation
		{
			temp = oldHashTable[i];											// Hook the entry
			tempChained = temp->chained;
			temp->chained = NULL;
			insertEntry(hashTable, temp);									// insert the first entry to the new table
			while(tempChained != NULL)										// insert all chained entries to the new table
			{
				temp = tempChained;
				tempChained = temp->chained;
				temp->chained = NULL;
				insertEntry(hashTable, temp);
			}
		}
	}

	free(oldHashTable);
}



HashTable* initHashTable()
{
	int i;
	HashTable* newHashTable = (HashTable*)malloc(sizeof(HashTable));
	newHashTable->table = (Entry**)malloc(sizeof(Entry*) * 5);
	for(i = 0; i < 5; i++)													// NULL pointer
	{
		newHashTable->table[i] = NULL;										
	}
	newHashTable->capacity = 5;
	newHashTable->size = 0;
	
	return newHashTable;
}

Entry* initEntry(int key, void* data)
{
	Entry* newEntry = (Entry*)malloc(sizeof(Entry));
	newEntry->key = key;
	newEntry->data = data;
	newEntry->chained = NULL;
	return newEntry;
}


