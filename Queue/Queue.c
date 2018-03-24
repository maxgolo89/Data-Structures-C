#include "Queue.h"

/* Enqueue data to the queue */
void* enqueue(Queue* queue, void* data)
{
	// Validate arguments
	if (queue == NULL || data == NULL)
		return NULL;

	Node* newNode = initializeNewNode();
	newNode->data = data;

	/* queue size 0:
	 * 1. head == tail
	 * 2. head and tail will point to same node after assignment.
	 */
	if(queue->size == 0)
	{
		queue->tail = queue->head = newNode;
	}
	else
	{
		queue->tail->next = newNode;
		queue->tail = newNode;
	}

	queue->size++;
	return data;
}

/* Dequeue data from the queue */
void* dequeue(Queue* queue)
{
	// Validate arguments
	if (queue == NULL || queue->head == NULL || queue->tail == NULL)
		return NULL;

	Node* dequeuedNode = queue->head;

	if(queue->size == 1)
	{
		queue->head = queue->tail = NULL;
	}
	else
	{
		queue->head = queue->head->next;
	}

	queue->size--;
	return dequeuedNode->data;
}

/* Peek at top of queue */
void* peek(Queue* queue)
{
	// Validate arguments
	if (queue == NULL || queue->head == NULL || queue->tail == NULL)
		return NULL;

	return queue->head->data;
}

/* Initialize new queue */
Queue* initializeNewQueue()
{
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
	newQueue->head = newQueue->tail = NULL;
	newQueue->size = 0;
	return newQueue;
}

/* Initialize new node */
Node* initializeNewNode()
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = newNode->data = NULL;
	return newNode;
}




