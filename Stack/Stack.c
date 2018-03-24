#include "Stack.h"

/* Push data to the stack */
void* push(Stack* stack, void* data)
{
	// Argument validation.
	if (stack == NULL || data == NULL)
		return NULL;

	Node* newNode = initializeNewNode();
	newNode->data = data;
	newNode->next = stack->head;
	stack->head = newNode;

	return data;
}

/* Pop data from the stack */
void* pop(Stack* stack)
{
	// Argument validation
	if (stack == NULL)
		return NULL;

	Node* popedNode = stack->head;
	stack->head = stack->head->next;

	return popedNode->data;
}

/* Peek at top of stack */
void* peek(Stack* stack)
{
	// Argument validation
	if (stack == NULL || stack->head == NULL)
		return NULL;

	return stack->head->data;
}

/* Init new stack struct. */
Stack* initializeNewStack()
{
	Stack* newStack = (Stack*)malloc(sizeof(Stack));
	newStack->head = NULL;
	newStack->size = 0;
}

/* Init new node stuct. */
Node* initializeNewNode()
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = NULL;
	newNode->next = NULL;
}



