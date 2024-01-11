#include "lists.h"

/**
 * dlistint_len - returns the length of a doubly int linked list
 *
 * @h: head of the linked list
 *
 * Return: number of elements
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	while (h)
	{
		h = h->next;
		++len;
	}

	return (len);
}
