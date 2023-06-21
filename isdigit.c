#include "monty.h"
/**
 * _isdigit - checking if string is an int
 * @c: string
 * Return: 0 if not and 1 if is
*/
int _isdigit(char *c)
{
	char *aux = c;

	if (c == NULL)
		return (0);
	if (*aux == '-')
		aux++;

	for (; *aux != '\0'; aux++)
	{
		if ((*aux < '0' || *aux > '9'))
		{
			return (0);
		}
	}
	return (1);
}
