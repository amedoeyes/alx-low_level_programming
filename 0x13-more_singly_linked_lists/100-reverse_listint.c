#include "lists.h"

/**
 * reverse_listint - reverse a linked list
 *
 * @head: pointer to the head of a linked list
 *
 * Return: pointer to the head of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;

	while (current)
	{
		*head = current->next;
		current->next = prev;
		prev = current;
		current = *head;
	}

	*head = prev;

	return (prev);
}
