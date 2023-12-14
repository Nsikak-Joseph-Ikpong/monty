#include "monty.h"

/**
 * popTopElement - Pop the top element off
 * @head: Pointer to the top of the stck
 * @counter: Line Number
 */
void popTopElement(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		handleEmptyStackError(coubter);
	}

	stack_t *current = *head;
	*head = current->next;
	free(current);
}
/**
 * handleEmptyStackError - Prints the error message for an empty stack
 * @counter: Line number
 */
void handleEmptyStackError(unsigned int counter)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
	cleanupAndExit(void);
}
