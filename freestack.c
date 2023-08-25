#include "monty.h"

/**
 * free_stack - frees a linked list
 * @head: head of the stack
 */

void free_stack(stack_t *head)
{
	stack_t *current_node;

	while (head != NULL)
	{
		current_node = head;
		head = head->next;
		free(current_node);
	}
}
