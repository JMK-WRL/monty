#include "stack_op.h"

/**
 * custom_pop - removes stack
 * @stack: stack to be removed
 * @line_num: error line
 */

void custom_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *top_node = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "Line %d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	*stack = top_node->next;
	free(top_node);
}
