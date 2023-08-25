#include "monty.h"

/**
 * custom_nop - do nothing
 * @stack_head: pointer to stack
 * @line_num: line number in the file
 */

void custom_nop(stack_t **stack_head, unsigned int line_num)
{
	(void) line_num;
	(void) stack_head;
}
