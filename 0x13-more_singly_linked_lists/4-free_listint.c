#include "lists.h"

/**
 * free_listint - frees a linked list
 *
 * @head: pointer to head of a linked list
 */

void free_listint(listint_t *head)
{
	while (head)
	{
		listint_t *temp = head;

		head = temp->next;
		free(temp);
	}
}
