#include "monty.h"

/**
 * f_div - divides the first two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_div(stack_t **head, unsigned int counter)
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
		handleStackTooShortError(counter);
	}

	current = *head;

	if (current->n == 0)
	{
		handleDivisionByZeroError(counter);
	}

	result = current->next->n / current->n;
	current->next->n = result;

	*head = current->next;

	free(current);
}
/**
 * Print an error message for a stack being too short
 * @counter: Line number
 */
void handleStackTooShortError(unsigned int counter)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", counter);
	cleanupAndExit();
}

/**
 * Printing error message for divvision by zero.
 * @counter: Line number.
 */
void handleDivisionByZeroError(unsigned int counter)
{
	fprintf(stderr, "L%d: division by zero\n", counter);
	cleanupAndExit();
}

/**
 * Clean up and exit with faliure status.
 */
void cleanupAndExit()
{
	fclose(bus.file);
	free(bus.content);
	fre_stack(*head);
	exit(EXIT_FALIULER);
}
