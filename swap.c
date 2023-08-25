#include "monty.h"

/**
 * custom_swap - swap the two top elements
 * @stack_head: pointer to stack
 * @line_num: line number in file
 * Return: nothing
 */

void custom_swap(stack_t **stack_head, unsigned int line_num)
{
	stack_t *current_node;
	int stack_length = 0, temp;

	current_node = *stack_head;

	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	current_node = *stack_head;
	temp = current_node->n;
	current_node->n = current_node->next->n;
	current_node->next->n = temp;
}
