#include "monty.h"

/**
 * execute - Execute the opcode
 * @content: line number
 * @stack: pointer to the head of the stack.
 * @counter: line counter.
 * @file: Pointer to the monty file
 * Return: 0 on success, 1 on faliure
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", addNodeToStack}, 
