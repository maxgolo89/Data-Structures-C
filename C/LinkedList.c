#include "LinkedList.h"

/* Insert data pointer to the end of the list.
 * Supports empty list.
 * On success return the argument pointer, on fail NULL returned. */
void* insert(LinkedList* linkedlist, const void* data)
{
	// Check for NULL arguments.
	if(linkedlist == NULL || data == NULL)
	{
		return NULL;
	}

	// Append the data pointer.
	Node* node = linkedlist->head;

	if(node == NULL)
	{
		return insertFirst(linkedlist, data);
	}

	
	// Iterate to last node
	while(node->next != NULL)
	{

		node = node->next;
	}

	// Allocate new node at next pointer of last node
	node->next = initializeNewNode();

	// Progress to next node.
	node = node->next;
	node->data = data;
	node->next = NULL;

	linkedlist->size++;

	return data;
}

/* Insert a data pointer to the top of the list.
 * Supports empty list. 
 * On success return the argument pointer, on fail NULL returned. */
void* insertFirst(LinkedList* linkedlist, const void* data)
{
	// Check for NULL arguments.
	if (linkedlist == NULL || data == NULL)
	{
		return NULL;
	}

	// Create new node.
	Node* node = initializeNewNode();
	
	// Set new node data
	node->data = data;

	// Set node next to current head.
	node->next = linkedlist->head;

	// Set node as current head.
	linkedlist->head = node;
	linkedlist->size++;

	return data;
}

/* Insert a data pointer to the list at a specific index.
 * Supports empty list.
 * On success return the argument pointer, on fail NULL returned. */
void* insertByIndex(LinkedList* linkedlist, const void* data, int index)
{
	int i = 0; // Iteration index

	// Check for NULL arguments.
	if (linkedlist == NULL || data == NULL)
	{
		return NULL;
	}

	// Check valid index.
	if(index < 0)
	{
		return NULL;
	}

	// Check if index is 0.
	if(index == 0)
	{
		return insertFirst(linkedlist, data);
	}

	// Check if index is within list bounds.
	if(index > linkedlist->size)
	{
		return insert(linkedlist, data);
	}
	
	// Create new node.
	Node* newNode = initializeNewNode();
	newNode->data = data;

	// Iterate to the node index-1 on list.
	Node* node = linkedlist->head;
	for(i = 0; i < index-1; i++)
	{
		node = node->next;
	}
	
	// Set new node next to current node next.
	newNode->next = node->next;

	// Set current node next to new node.
	node->next = newNode;
	linkedlist->size++;

	return data;
}

/* Remove head of list. */
void* removeFirst(LinkedList* linkedlist)
{
	// Validate linkedlist.
	if (linkedlist == NULL)
		return NULL;

	Node* node = linkedlist->head;

	// Validate list not empty;
	if (node == NULL)
		return NULL;

	// Mode head to next pointer
	linkedlist->head = linkedlist->head->next;

	// Free removed node
	free(node);

	linkedlist->size--;
	return NULL;
}

/* Remove tail of list. */
void* removeLast(LinkedList* linkedlist)
{
	// Validate linkedlist, Validate list not empty
	if (linkedlist == NULL || linkedlist->head == NULL)
		return NULL;
	
	Node* currentNode = linkedlist->head;

	// Iterate to last node
	while (currentNode->next != NULL)
		currentNode = currentNode->next;
	
	// Free last node memory
	free(currentNode);

	linkedlist->size--;
	return NULL;
}

/* Remove by index */
void* removeByIndex(LinkedList* linkedlist, int index)
{
	int i = 0; // Iterator

	// Validate linked list
	if (linkedlist == NULL || linkedlist->head || index > linkedlist->size || index < 0)
		return NULL;

	// Handle first node
	if (index == 0)
		return removeFirst(linkedlist);

	// Handle last node
	if (index == linkedlist->size - 1)
		return removeLast(linkedlist);


	Node* currentNode = linkedlist->head;

	// Iterate to index-1
	for(i = 0; i < index-1; i++)
	{
		currentNode = currentNode->next;
	}

	// Save current node next to temp
	Node* temp = currentNode->next;

	// Set current node next to next node next
	currentNode->next = currentNode->next->next;

	// free temp
	free(temp);

	linkedlist->size--;
	return NULL;
}

/* Get first node data */
void* getFirstNode(const LinkedList* linkedlist)
{
	if (linkedlist == NULL || linkedlist->head == NULL)
		return NULL;

	return linkedlist->head->data;
}

/* Get last node data */
void* getLastNode(const LinkedList* linkedlist)
{
	if (linkedlist == NULL || linkedlist->head == NULL)
		return NULL;
	
	Node* currentNode = linkedlist->head;
	
	// Iterate to last node
	while (currentNode->next != NULL)
		currentNode = currentNode -> next;

	return currentNode->data;
}

/* Get data by index */
void* getNodeByIndex(const LinkedList* linkedlist, int index)
{
	int itr = 0;

	// Validation
	if (linkedlist == NULL || linkedlist->head == NULL || index > linkedlist->size || index < 0)
		return NULL;

	Node* currentNode = linkedlist->head;
	
	// Iterate to index
	for (itr = 0; itr < index; itr++)
		currentNode = currentNode->next;
		
	// Return
	return currentNode->data;

}

/* Initialize new node 
 * For internal use. */
Node* initializeNewNode()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->data = NULL;

	return node;
}

/* Initialize new linked list. 
 * Use only this method. */
LinkedList* initializeNewLinkedList()
{
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	list->head = NULL;
	list->size = 0;
	return list;
}


