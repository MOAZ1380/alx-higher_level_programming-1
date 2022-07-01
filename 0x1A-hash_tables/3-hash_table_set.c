#include "hash_tables.h"

/**
  * hash_table_set - function that adds an element to the hash table
  * @ht: pointer to hash table
  * @key: key of the new element
  * @value: value of the new element
  *
  * Return: 1 on success, 0 on failure
  */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *index_head_node;
	int status = EXIT_FAILURE;

	if (!ht || !ht->array || !key || (strlen(key) == 0))
		return (status);

	index = key_index((unsigned char *) key, ht->size);

	if (index >= ht->size)
		return (status);

	index_head_node = ht->array[index];

	ht->array[index] = insert_node(&index_head_node, key, value, &status);

	return (status);
}

/**
 * insert_node - add a node to the top of the linked list
 * @head: pointer to the linked list
 * @key: string, key of new node added
 * @value: string, value of new node to be added
 * @status: pointer to an integer, to track status of insertion
 *
 * Return: 1 on success, 0 on failure.
 */
hash_node_t *insert_node(hash_node_t **head,
		const char *key, const char *value, int *status)
{
	hash_node_t *new, *h = *head;

	while (h != NULL)
	{
		if (strcmp(h->key, key) == 0)
		{
			free(h->value);
			h->value = strdup(value);
			*status = EXIT_SUCCESS;
			return (*head);
		}
		h = h->next;
	}

	new = malloc(sizeof(hash_node_t));

	if (new == NULL)
		return (*head);

	new->key = strdup(key), new->value = strdup(value);
	new->next = *head, *head = new;

	*status = EXIT_SUCCESS;
	return (*head);
}

