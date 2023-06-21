#include "monty.h"
/**
 * _mul - multiplies
 * @head: stack head
 * @counter: lines number
*/
void _mul(stack_t **head, unsigned int counter)
{
	stack_t *temp = *head;
	int mul;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(gv.file);
		free(gv.line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	mul = temp->next->n * temp->n;
	temp->next->n = mul;
	*head = temp->next;
	free(temp);
}
/**
 * _mod - mod
 * @head: stack head
 * @counter: lines number
*/
void _mod(stack_t **head, unsigned int counter)
{
	stack_t *temp = *head;
	int mod;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(gv.file);
		free(gv.line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(gv.file);
		free(gv.line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	mod = temp->next->n % temp->n;
	temp->next->n = mod;
	*head = temp->next;
	free(temp);
}
