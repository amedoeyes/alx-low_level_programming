#include "lists.h"

/**
 * list_len - prints all the elements of a linked list
 *
 * @h: pointer to head of list
 *
 * Return: number of nodes
 */

size_t list_len(const listint_t *h)
{
	int count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}

	return (count);
}

/**
 * get_nodeint_at_index - gets the nth node of a linked list
 *
 * @head: pointer to the head of a linked list
 * @index: index of the node to return
 *
 * Return: the nth node or NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	size_t i;
	size_t len = list_len(head);

	if (index > len)
		return (NULL);

	for (i = 0; i < index; i++)
		head = head->next;

	return (head);
}
