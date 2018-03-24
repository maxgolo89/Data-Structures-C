#pragma once
#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include <stdlib.h>
#include <stdarg.h>


/* Node:
 * 1. Void type pointer to data.
 *	a. Devloper should know what type he is using the list for.
 * 2. Pointer to next node.
 */
typedef struct node_t
{
	void* data;
	struct node_t* next;
} Node;


/* LinkedList:
 * 1. Pointer to head node of the list. 
 * 2. Size of the linked list.
 */
typedef struct linkedlist_t 
{
	struct node_t* head;
	int size;
} LinkedList;

// Insert
void* insert(LinkedList* linkedlist, const void* data);

// Insert first
void* insertFirst(LinkedList* linkedlist, const void* data);

// Insert at index
void* insertByIndex(LinkedList* linkedlist, const void* data, int index);

// Remove first
void* removeFirst(LinkedList* linkedlist);

// Remove last
void* removeLast(LinkedList* linkedlist);

// Remove index
void* removeByIndex(LinkedList* linkedlist, int index);

// Get first
void* getFirstNode(const LinkedList* linkedlist);

// Get last
void* getLastNode(const LinkedList* linkedlist);

// Get at index
void* getNodeByIndex(const LinkedList* linkedlist, int index);

// Initialize new node
Node* initializeNewNode();

// Initialize new linked list
LinkedList* initializeNewLinkedList();

#endif
