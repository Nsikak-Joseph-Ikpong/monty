#include "monty.h"

/**
 * printTopElement -  Printsd the element at the top of the stack
 * @head: Pointer to the head
 * @counter: Line Number
 */
void printTopElement(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		handleEmptyStackError(counter);
	}

	printf("%d\n", (*head)->n);
}
/**
 * handleEmptyStackError - Prints an error message for empty stack
 * @counter: Line Number
 */
void handleEmptyStackError(unsigned int counter)
{
	fprintf(stderr, "L%u: can't print, stack empty\n", counter);
	cleanupAndExit(void);
}
