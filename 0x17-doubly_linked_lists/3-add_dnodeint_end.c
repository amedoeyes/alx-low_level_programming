#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - adds a node into the end of a doubly int linked list
 *
 * @head: head of the linked list
 * @n: data to add
 *
 * Return: pointer to the new node
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *tail = *head;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	while (tail != NULL)
	{
		if (tail->next == NULL)
			break;

		tail = tail->next;
	}

	new_node->n = n;
	new_node->prev = tail;
	new_node->next = NULL;

	if (tail != NULL)
		tail->next = new_node;
	else
		*head = new_node;

	return (new_node);
}
