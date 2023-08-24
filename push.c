#include "monty.h"

/**
 * custom_push - pushes an element to the stack
 * @stack: stack to be pushed
 * @line_num: error line
 */

void custom_push(stack_t **stack, unsigned int line_num)
{
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (scanf("%d", &value) != 1)
	{
		fprintf(stderr, "Line %d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	*stack = new_node;
}
