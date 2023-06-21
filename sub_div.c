#include "monty.h"

void _sub(stack_t **head, unsigned int counter)
{
    stack_t *temp = *head;
    int sub;

    if (!*head || !(*head)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(gv.file);
        free(gv.line);
        free_stack(head);
        exit(EXIT_FAILURE);
    }
    sub = temp->next->n - temp->n;
    temp->next->n = sub;
    *head = temp->next;
    free(temp);
}
