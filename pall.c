#include "monty.h"

/**
 * pall - opcode
 * @stack: stack
 * @line_num: parameter
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}