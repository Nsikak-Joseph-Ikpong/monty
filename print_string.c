#include "monty.h"

/**
 * printString - Prints the string starting the top of the stack
 * @head: Pointeer to the top of the stack
 * @counter: Line Number
 */
void printString(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	(void)counter;

	while (current && (current->n > 0 && current->n <= 127))
	{
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
