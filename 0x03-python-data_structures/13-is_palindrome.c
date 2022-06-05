#include "lists.h"

/**
 * is_palindrome - check if a singly linked list is a palindrome
 * @head: linked list double pointer
 *
 * Return: integer, 1 if list is a palindrome else 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	unsigned int i, l = 0;
	int *p;

	if (current == NULL)
		return (1);
	while (current)
		l++, current = current->next;
	p = malloc(l * sizeof(*p));
	current = *head, i = 0;
	while (current)
		p[i++] = current->n, current = current->next;
	i = 0, l -= 1;
	while (i <= l)
	{
		if (p[i++] != p[l--])
			return (0);
	}
	i = 0;
	free(p);
	return (1);
}

