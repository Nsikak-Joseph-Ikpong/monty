#include "monty.h"
/**
 * printCharAtTop - Print the charcters at the top of the stack
 * @head: Pointer ro the head of the circle
 * counter: Line Number
 */
void printCharAtTop(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	if (!current)
	{
		handleEmptyStackError(counter);
	}

	if (current->n > 127 || current-> < 0)
	{
		handleValueOutofRangeError(counter);
	}

	printf("%c\n", current->n);
}
/**
 * handleEmptyStackError - Print an error message 
 * @counter: Line Number
 */
void handleEmptyStackError(unsigned int counter)
{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
	cleanupAndExit();
}
/**
 * handleValueOutOfRangeError - Print an error message for a valeue
 * @counter: Line NUmber
 */
void handleValueOutOfRangeError(unsigned int counter)
{
	fprintf(stderr, "L%d: can't pchar, value out of the rsnger", counter);
	cleanupAnvdExit();
}
