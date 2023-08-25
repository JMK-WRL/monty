#include "monty.h"

/**
 * custom_pint - print the top element
 * @stack_head: pointer to the stack's head
 * @line_num: line number in the file
 * Return: nothing
 */

void custom_pint(stack_t **stack_head, unsigned int line_num)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}
