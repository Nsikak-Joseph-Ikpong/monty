#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void performAddition(stack_t **head, unsigned int counter);
void addNodeToStack(stack_t **head, int n);
void f_div(stack_t **head, unsigned int counter);
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void handleAddError(unsigned int counter);
void handleMemoryAllocationError(void);
void handleStackTooShortError(unsigned int counter);
void handleDivisionByZeroError(unsigned int counter);
void cleanupAndExit();
void handleUnknownInstructionError(char *op, unsigned int counter, FILE *file, char *content, stack_t **stack);
void freeStack(stack_t *head);
void computeMod(stack_t **head, unsigned int counter);
void handleModError(unsigned int counter);
void performMultiplication(stack_t **head, unsigned int counter);
void handleMultiplicationError(unsigned int counter);
void f_nothing(stack_t **head, unsigned int counter);
void printCharAtTop(stack_t **head, unsigned int counter);
void handleEmptyStackError(unsigned int counter);
void handleValueOutOfRangeError(unsigned int counter);
void printStack(stack_t **head, unsigned int counter);
void printString(stack_t **head, unsigned int counter);
void printTopElement(stack_t **head, unsigned int counter);
void handleEmptyStackError(unsigned int counter);
void popTopElement(stack_t **head, unsigned int counter);
void handleEmptyStackError(unsigned int counter);
void addNodeToStack(stack_t **head, unsigned int counter);
void addNodeToStackHelper(stack_t **head, int n);
void handleInvalidPushError(unsigned int counter);
void rotateToBottom(stack_t **head, unsigned int counter);
void rotateToTop(stack_t **head, __attribute__((unused)) unsigned int counter);
void setStackMode(stack_t **head, unsigned int counter);
void performSubtraction(stack_t **head, unsigned int counter);
void handleSubtractionError(unsigned int counter);
void swapTopTwoElements(stack_t **head, unsigned int counter);
void handleSwapError(unsigned int counter);
#endif
