#include "monty.h"

stack_t *stack = NULL;

/**
 * main - monty interpretor
 * @argc: arguments
 * @argv: location
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	char line[100];
	unsigned int line_number = 0;
	FILE *file;
	char opcode[100];
	int value;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error:  Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		if (scanf(line, "%99s", opcode) == 1)
		{
			if (strcmp(opcode, "push") == 0)
			{
				if (scanf(line, "%*s %d", &value) == 1)
				{
					push(&stack, value);
				}
				else
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
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
				instruction.f(&stack, line_number);
			}
		}
	}
	fclose(file);

	while (stack != NULL)
	{
		pop(&stack, line_number);
	}

	return (0);
}
