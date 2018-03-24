#pragma once
#ifndef __QUEUE_H
#define __QUEUE_H
#include <stdlib.h>

typedef struct node_t {
	void* data;
	struct node_t* next;
} Node;

typedef struct queue_t {
	Node* head;
	Node* tail;
	int size;
} Queue;

void* enqueue(Queue* queue, void* data);
void* dequeue(Queue* queue);
void* peek(Queue* queue);

Queue* initializeNewQueue();
Node* initializeNewNode();

#endif
