#include "monty.h"

int main(int argc, char *argv[]);
int process_line(char *line, stack_t **stack, unsigned int line_number);
void cleanup(stack_t **stack);

/**
 * main - monty interpretor
 * @argc: arguments
 * @argv: files
 * Return: 0 (success))
 */

int main(int argc, char *argv[])
{
	char line[100];
	unsigned int line_number = 0;
	FILE *file;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		if (process_line(line, &stack, line_number) == -1)
		{
			cleanup(&stack);
			fclose(file);
			return (EXIT_FAILURE);
		}
	}

	cleanup(&stack);
	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * process_line - Process a line of Monty bytecode
 * @line: The line of bytecode to process
 * @stack: pointer to the stack
 * @line_number: line number being processed
 * Return: 0 (success, -1 (failure)
 */

int process_line(char *line, stack_t **stack, unsigned int line_number)
{
	char opcode[100];
	int value;

	if (sscanf(line, "%99s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (sscanf(line, "%*s %d", &value) == 1)
			{
				push(stack, value);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				return (-1);
			}
		}
		else
		{
			instruction_t instruction;

			if (strcmp(opcode, "pall") == 0)
				instruction.f = pall;
			else if (strcmp(opcode, "pint") == 0)
				instruction.f = pint;
			else if (strcmp(opcode, "pop") == 0)
				instruction.f = pop;
			else if (strcmp(opcode, "swap") == 0)
				instruction.f = swap;
			else if (strcmp(opcode, "add") == 0)
				instruction.f = add;
			else if (strcmp(opcode, "nop") == 0)
				instruction.f = nop;
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
			instruction.opcode = opcode;
			instruction.f(stack, line_number);
		}
	}
	return (0);
}

/**
 * cleanup - Free memory allocated for the stack
 * @stack: pointer to the stack
 */

void cleanup(stack_t **stack)
{
	while (*stack != NULL)
	{
		pop(stack, 0);
	}
}
