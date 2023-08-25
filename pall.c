#include "monty.h"

/**
 * custom_pall - print the elements fo the stack
 * @stack_head: pointer to the stack head
 * @line_num: line number
 * Return: nothing
 */

void custom_pall(stack_t **stack_head, unsigned int line_num)
{
	stack_t *current_node;
	(void)line_num;

	current_node = *stack_head;
	if (current_node == NULL)
	{
		return;
	}
	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
