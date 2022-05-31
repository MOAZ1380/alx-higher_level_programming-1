#include "lists.h"

/**
 * insert_node - insert node in an ordered list
 * @head: head node
 * @number: n data value of the new node
 *
 * Return: new node or NULL on failure
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *next, *new = malloc(sizeof(listint_t)), *top = *head;

	if (new == NULL)
		return (NULL);
	new->n = number, new->next = NULL;

	if (top == NULL || top->n >= new->n)
	{
		new->next = top;
		*head = new;
	}
	else
	{
		next = top->next;
		while (next)
		{
			if (top->n <= new->n && new->n <= next->n)
			{
				top->next = new;
				new->next = next;
				return (new);
			}
			top = next, next = next->next;
		}
		top->next = new;
	}
	return (new);
}

