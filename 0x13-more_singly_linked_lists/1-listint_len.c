#include "lists.h"

/**
 * listint_len - prints all the elements of a linked list
 *
 * @h: pointer to head of list
 *
 * Return: number of nodes
 */

size_t listint_len(const listint_t *h)
{
	int count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}

	return (count);
}
