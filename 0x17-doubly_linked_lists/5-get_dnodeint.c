#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of an int doubly linked list
 *
 * @head: head of the linked list
 * @index: index of the node
 *
 * Return: nth node or NULL
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (head != NULL && index--)
		head = head->next;

	return (head);
}
