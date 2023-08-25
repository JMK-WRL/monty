#include "monty.h"
#include <stdio.h>

int execute_instruction(char *content, stack_t **stack, unsigned int counter, FILE *file);
size_t getline(char **lineptr, size_t *n, FILE *stream);

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	char *line_content;
	FILE *monty_file;
	size_t line_size = 0;
	size_t read_result = 1;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	bus.file = monty_file;

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_result > 0)
	{
		line_content = NULL;
		read_result = getline(&line_content, &line_size, monty_file);
		bus.content = line_content;
		line_number++;

		if (read_result > 0)
		{
			execute_instruction(line_content, &stack, line_number, monty_file);
		}

		free(line_content);
	}

	free_stack(stack);
	fclose(monty_file);

	return (0);
}
