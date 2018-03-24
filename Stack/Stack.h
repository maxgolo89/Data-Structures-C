#pragma once
#ifndef __STACK_H
#define __STACK_H

#include <stdlib.h>

typedef struct node_t {
	void* data;
	struct node_t* next;
} Node;

typedef struct stack_t {
	Node* head;
	int size;
} Stack;

void* push(Stack* stack, void* data);
void* pop(Stack* stack);
void* peek(Stack* stack);
Stack* initializeNewStack();
Node* initializeNewNode();

#endif
