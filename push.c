#include "monty.h"

/**
 * custom_push - adds a node to the stack
 * @stack_head: pointer to the stack's head
 * @line_num: line number in the monty file
 * Return: nothing
 */

void custom_push(stack_t **stack_head, unsigned int line_num)
{
	int value;
	int index = 0;
	int invalid_flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			index++;
		for (; bus.arg[index] != '\0'; index++)
		{
			if (bus.arg[index] > 57 || bus.arg[index] < 48)
				invalid_flag = 1;
		}
		if (invalid_flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(bus.file);
			free(bus.content);
			free_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	value = atoi(bus.arg);
	if (bus.lifo == 0)
		addnode(stack_head, value);
	else
		f_queue(stack_head, value);
}
