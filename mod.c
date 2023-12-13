#include "monty.h"
/**
 * computeMod - Compute the rest of the division
 * @head: Pointer to the heaad
 * @counter: Line number
 */
void computeMod(stack_t **head, unsigned int counter)
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
		handleModError(counter);
	}

	current = *head;

	if (current->n == 0)
	{
		handleDivisionByZeroError(counter);
	}

	result = current->next->n % current->n;
	current->next->n = result;

	*head = current->next;

	free(current);
}
/**
 * handleModError - Prints the error message for the stack
 * @counter: Line Number.
 */
void handleModError(unsigned int counter)
{
	fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
	cleanupAndExit();
}
