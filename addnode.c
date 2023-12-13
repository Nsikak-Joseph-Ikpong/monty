#include "monty.h"

/**
 * addNodeToStack - Add a new node to the head of the stack
 * @head: Pointer to the head
 * @n: value added to the node
 */
void addNodeToStack(stack_t **head, int n)
{
	stack_t *newNode, *current;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		handleMemoryAllocationError();
	}

	current = *head;

	if (current)
	{
		current->prev = newNode;
	}

	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;

	*head = newNode;
}
/**
 * handleMemoryAllocationError - Print an error message for memory allocation
 */
void handleMemoryAllocationError(void)
{
	fprintf(stderr, "Error:  Memory allocation failure\n");
	cleanupAndExit();
}
