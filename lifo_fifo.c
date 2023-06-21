#include "monty.h"
/**
 * _stack - LIFO to 1
 * @head: stack head
 * @counter: lines number
*/
void _stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	gv.lifo = 1;
}
/**
 * _queue - LIFO to 0
 * @head: stack head
 * @counter: lines number
*/
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	gv.lifo = 0;
}
