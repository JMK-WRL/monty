#include "monty.h"

/**
 * custom_swap - swaps the top stacks
 * @stack: stack to be swaped
 * @line_num: error line
 */

void custom_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *top_node = *stack;
	stack_t *second_top_node = top_node->next;


	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "Line %d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	top_node->next = second_top_node->next;
	second_top_node->next = top_node;

	*stack = second_top_node;
}
