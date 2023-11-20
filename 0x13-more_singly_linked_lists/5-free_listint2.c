#include "lists.h"

/**
 * free_listint2 - frees a linked list
 *
 * @head: pointer to head of a linked list
 */

void free_listint2(listint_t **head)
{
	while (head && *head)
	{
		listint_t *temp = *head;

		*head = temp->next;
		free(temp);
	}
}
