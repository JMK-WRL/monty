#include "monty.h"

/**
 * custom_pop - remove the top element from the stack
 * @stack_head: pointer to stack
 * @line_num: line number in file
 * Return: nothing
 */

void custom_pop(stack_t **stack_head, unsigned int line_num)
{
	stack_t *current_node;

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		fclose(bus.file);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	current_node = *stack_head;
	*stack_head = current_node->next;
	free(current_node);
}
