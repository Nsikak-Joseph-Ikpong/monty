#include "monty.h"
/**
 * printStack - print the contents of the stack
 * @head: Pointer to the head
 * @counter: Unused.
 */
void printStack(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	(void)counter;

	if (current == NULL)
	{
		return;
	}

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
