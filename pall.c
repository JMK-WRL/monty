#include "monty.h"

/**
 * custom_pall - function that prints all values on the stack
 * @stack: parameter
 */

void custom_pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
