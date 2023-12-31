#include "monty.h"
/**
 * handle_cmd - handle all commands
 * @line: line from getline
 * @l: line number
 * @head: stack head
 * Return: 0
*/
int handle_cmd(char *line, unsigned int l, stack_t **head)
{
	int i = 0;
	char *first;
	instruction_t op[] = { {"push", _push}, {"pall", _pall}, {"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};

	first = strtok(line, " \n\t\r\a\v");

	if (first == NULL || first[0] == '#')
		return (0);

	while (op[i].opcode != NULL)
	{
		if (strcmp(op[i].opcode, first) == 0)
		{
			if (strcmp(first, "push") == 0)
			{
				first = strtok(NULL, " \n\t\r\a\v");
				if (_isdigit(first) == 1)
					value = atoi(first);
				else
				{
					fprintf(stderr, "L%u: usage: push integer\n", l);
					free_all();
					free_stack(head);
					exit(EXIT_FAILURE);
				}
			}
			op[i].f(head, l);
			return (0);
		}
		else
		{
			if (op[i + 1].opcode == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", l, first);
				free_all();
				free_stack(head);
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
	return (0);
}
