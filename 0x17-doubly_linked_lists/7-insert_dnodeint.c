#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position in an int
 * doubly linked list
 *
 * @h: head of the linked list
 * @idx: index to add at
 * @n: data to add
 *
 * Return: pointer to the new node
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node = NULL;
	dlistint_t *current = NULL;

	if (h == NULL)
		return (NULL);

	current = *h;

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (current != NULL && idx--)
	{
		if (current->next == NULL && idx > 0)
			return (NULL);

		current = current->next;
	}

	if (current == NULL)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = current->prev;
	new_node->next = current;

	current->prev->next = new_node;
	current->prev = new_node;

	return (new_node);
}
