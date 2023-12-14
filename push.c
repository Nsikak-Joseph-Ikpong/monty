#include "monty.h"
/**
 * addNodeToStack - Add a node tot  the stack
 * @head: Pointer to the top of the stack
 * @counter: Line Number
 */
void addNodeToStack(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > '9' || bus.arg[j] < '0')
				flag = 1;
		}
		if (flag == 1)
		{
			handleInvalidPushError(counter);
		}
	}
	else
	{
		handleInvalidPushError(counter);
	}

	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addNodeToStackHelper(head, n);
	else
		addQueueNode(head, n);
}

/**
 * addNodeToStackHelper - Adds a node to the top of the stack
 * @head: Pointer to the head of thre stack
 * @n: Value to be added to the node.
 */
void addNodeToStackHelper(stack_t **head, int n)
{
	stack_t *newNode, *current;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		handleMemoryAllocationError();
	}

	 current = *head;

	 newNode->n = n;
	 newNode->next = current;
	 newNode->prev = NULL;

	if (current != NULL)
	{
		current->prev = newNode;
	}

	  *head = newNode;
}
/**
 * handleInvalidPushError - Prints an error message for invalid push operations
 * @counter: Line Number
 */
void handleInvalidPushError(unsigned int counter)
{
	fprintf(stderr, "L%d: usage: push integer\n", counter);
	cleanupAndExit(void);
}
