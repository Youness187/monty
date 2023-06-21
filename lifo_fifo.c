#include "monty.h"

void _stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	gv.lifo = 1;
}

void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	gv.lifo = 0;
}