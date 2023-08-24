#include "stack_op.h"


/**
 * main - calls all the function
 * Return: 0
 */

int main(void)
{
	stack_t *stack = NULL;

	custom_push(&stack, __LINE__);
	custom_push(&stack, __LINE__);
	custom_push(&stack, __LINE__);

	custom_pall(stack);

	custom_pint(stack, __LINE__);

	custom_pop(&stack, __LINE__);

	custom_swap(&stack, __LINE__);

	custom_add(&stack, __LINE__);

	custom_nop();

	return (0);
}
