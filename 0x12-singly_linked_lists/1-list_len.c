#include "lists.h"

/**
 * list_len - returns number of nodes in a linked list
 *
 * @h: pointer to head of linked list
 *
 * Return: number of nodes
 */

size_t list_len(const list_t *h)
{
	int count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}

	return (count);
}
