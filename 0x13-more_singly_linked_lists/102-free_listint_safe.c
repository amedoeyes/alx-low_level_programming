#include "lists.h"

/**
 * free_listint_safe - frees a linked list safely
 *
 * @h: pointer to the head of a linked list
 *
 * Return: number of nodes
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t **visited_nodes = NULL;
	size_t len = 0;
	size_t i;

	while (*h)
	{
		listint_t *temp = *h;

		len++;

		visited_nodes = realloc(visited_nodes, sizeof(listint_t *) * len);
		if (!visited_nodes)
			exit(98);

		visited_nodes[len - 1] = *h;
		*h = (*h)->next;

		free(temp);

		for (i = 0; i < len; i++)
		{
			if (visited_nodes[i] == *h)
			{
				free(visited_nodes);
				(*h) = NULL;
				return (len);
			}
		}
	}

	free(visited_nodes);
	return (len);
}
