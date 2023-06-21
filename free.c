#include "monty.h"

void free_all()
{
	fclose(gv.file);
	free(gv.line);
}

void free_stack(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
}