#include "monty.h"

/**
 * custom_pint - prints the value of the top stack
 * @line_num: error line
 * @stack: stack to print
 */

void custom_pint(stack_t *stack, unsigned int line_num)
{
	if (stack == NULL)
	{
		fprintf(stderr, "Line %d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", stack->n);
}
