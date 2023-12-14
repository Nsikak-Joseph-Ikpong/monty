#include "monty.h"
/**
 * Perform addition on the first two elements
 * @head: Pointer to the head of the stack
 * @counter: Line number
 */
void performAddition(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	int stackLength = 0, result;

	while (current)
	{
		current = current->next;
		stackLength++;
	}

	if (stackLength < 2)
	{
		handleAddError(counter);
	}

	current = *head;

	result = current->n + current->next->n;
	current->next->n = result;

	*head = current->next;

	free(current);
}
/**
 * Print an error message for a stack that is too short
 * @counter: Line number
 */
void handleAddError(unsigned int counter)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", counter);
	cleanupAndExit();
}

