#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - prints a doubly int linked list
 *
 * @h: head of the linked list to print
 *
 * Return: number of printed elements
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		++count;
	}

	return (count);
}
