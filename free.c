#include "monty.h"
/**
 * free_all - free *FILE and line
*/
void free_all(void)
{
	fclose(gv.file);
	free(gv.line);
}
/**
 * free_stack - free stack_t
 * @stack: stack head
*/
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;

	for (; current; current = *stack)
	{
		*stack = (*stack)->next;
		free(current);
	}
}
