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
		{"print_stack", printStack},
		{"prints_Top", popTopElement}, {"swap", swapTopTwoElements},
		{"add", performAddition},
		{"nothing", f_nothing},
		{"subtraction", performSubtraction},
		{"dividion", f_div},
		{"multiplication", performMultiplication},
		{"mod", computeMod},
		{"print_char", printCharAtTop},
		{"print_string", printString},
		{"rotate_to_top", rotateToTop},
		{"rotate_to_bottom", rotateToBottom},
		{"stack", setStackMode},
		{NULL, NULL}};

	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);

	bus.arg = strtok(NULL, " \n\t");

	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	if (op && opst[i].opcode == NULL)
	{
		handleUnknownInstructionError(op, counter, file, content, stack);
	}

	return (1);
}

/**
 * handleUnknownInstructionError - Prints error message for an unknown instruction
 * @op: Unknown opcode.
 * @counter: Line number.
 * @file: Pointer to the monty file.
 * @content: Line content
 * @stack: Pointer to the head of the stack.
 */
void handleUnknownInstructionError(char *op, unsigned int counter, FILE *file, char *content, stack_t **stack)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}
