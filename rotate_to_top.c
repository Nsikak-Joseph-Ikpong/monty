#include "monty.h"

/**
 * rotateToTop - Rotates the stack to the top
 * @head: Pointer to the top of thee stack
 * @counter: Line Number
 */
void rotateToTop(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	stack_t *tmp = *head, *aux;

	aux = (*head)->next;
	aux->prev = NULL;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
