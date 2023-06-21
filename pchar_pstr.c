#include "monty.h"
/**
 * _pchar - print char
 * @head: stack head
 * @counter: lines number
*/
void _pchar(stack_t **head, unsigned int counter)
{
	stack_t *temp = *head;

	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(gv.file);
		free(gv.line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(gv.file);
		free(gv.line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}
/**
 * _pstr - print string
 * @head: stack head
 * @counter: lines number
*/
void _pstr(stack_t **head, unsigned int counter)
{
	stack_t *temp = *head;
	(void)counter;

	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
