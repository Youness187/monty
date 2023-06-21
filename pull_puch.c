#include "monty.h"

int value;
/**
 * new_node - create new node
 * @n: value
 * Return: new node
 */
stack_t *new_node(int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		free_stack(&gv.head);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	return (new);
}

/**
 * _push - push item
 * @stack: is a parameter
 * @line_number: is value
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *temp = *stack;
	(void)line_number;

	new = new_node(value);

	if (gv.lifo == 1)
	{
		new->next = *stack;
		if (*stack != NULL)
			(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		if (temp)
		{
			while (temp->next)
				temp = temp->next;
			temp->next = new;
			new->prev = temp;
		}
		else
		{
			*stack = new;
			new->prev = NULL;
		}
	}
}

/**
 * _pall - print elements stack
 * @stack: is a parameter
 * @n: is value
 */
void _pall(stack_t **stack, unsigned int n)
{
	stack_t *current = NULL;
	(void)n;

	current = *stack;

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}
