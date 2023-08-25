#include "monty.h"

/**
 * custom_add - adds the two top elements in a stack
 * @stack_head: pointer to the stack's head
 * @line_num: line number in the Monty file
 * Return: No explicit return return value
 */

void custom_add(stack_t **stack_head, unsigned int line_num)
{
	stack_t *temp_stack;
	int stack_length = 0, sum;

	temp_stack = *stack_head;
	while (temp_stack)
	{
		temp_stack = temp_stack->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	temp_stack = *stack_head;
	sum = temp_stack->n + temp_stack->next->n;
	temp_stack->next->n = sum;
	*stack_head = temp_stack->next;
	free(temp_stack);
}
