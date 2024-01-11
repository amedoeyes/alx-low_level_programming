#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes a node at given index of an int doubly
 * linked list
 *
 * @head: head of the linked list
 * @index: index of node to delete
 *
 * Return: 1 if success, -1 if fail
 */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = NULL;

	if (head == NULL)
		return (-1);

	current = *head;

	while (current != NULL && index--)
		current = current->next;

	if (current == NULL)
		return (-1);

	if (current->next)
		current->next->prev = current->prev;
	if (current->prev)
		current->prev->next = current->next;

	if (current == *head)
		*head = current->next;

	free(current);

	return (1);
}
