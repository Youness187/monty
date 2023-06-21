#include "monty.h"

int handle_cmd(char *line, unsigned int l, stack_t **head)
{
    int i = 0;
    char *first;
    instruction_t op[] = {
		{"push", _push},
        {"pall", _pall},
        {"pint", _pint},
        {"pop", _pop},
        {"swap", _swap},
        {"add", _add},
        {"nop", _nop},
		{NULL, NULL}
	};

    first = strtok(line, " \n\t\r\a\v");
    
    if (first == NULL)
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
                    return (1);
            }
            op[i].f(head, l);
            break;
        }
        else
        {
            if (op[i+1].opcode == NULL)
            {
                dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", l, first);
                return (2);
            }
        }
        i++;
    }
    return (0);
}
