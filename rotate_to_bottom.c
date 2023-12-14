#include "monty.h"

/**
 * rotateToBottom -  to the bottom
 * @head: pointer tot hte head
 * @counter: Line number
 */
void rotateToBottom(stack_t **head, unsigned int counter)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (copy->next)
	{
		copy = copy->next;
	}

	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
