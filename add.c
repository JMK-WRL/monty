#include "stack_op.h"

/**
 * custom_add - opcode that adsds the top two elements
 * @stack: stack to add
 * @line_num: indicates the line number with an error
 */

void custom_add(stack_t **stack, unsigned int line_num)
{
	int top_value;
	int second_top_value;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Line %d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	top_value = (*stack)->n;
	second_top_value = (*stack)->next->n;

	(*stack)->n = top_value + second_top_value;

	custom_pop(stack, line_num);
}
