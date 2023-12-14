#include "monty.h"
/**
 * swapTopTwoElements - Swap the top two elements
 * @head: Pointer to the head
 * @counter: Line Numner
 */
void swapTopTwoElements(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;

	int len = 0, temp;

	while (current)
	{
		current = current->next;
		len++;
	}

	if (len < 2)
	{
		handleSwapError(counter);
	}

	current = *head;

	temp = current->n;
	current->n = current->next->n;
	current->next->n = temp;
}

/**
 * handleSwapError - Prints an erro message for a short stack
 * @counter: lline number
 */
void handleSwapError(unsigned int counter)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
	cleanupAndExit(void);
}
