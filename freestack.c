#include "monty.h"
/**
 * freeStack - Free a doubly linked list
 * @head: Head of the stack
 */
void freeStack(stack_t *head)
{
	stack_t *current, *nextNode;

	current = head;

	while (current)
	{
		nextNode = current->next;
		free(current);
		current = nextNode;
	}
}
