#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - frees a doubly int linked list
 *
 * @head: head of the linked list
 */

void free_dlistint(dlistint_t *head)
{
	while (head != NULL)
	{
		dlistint_t *temp = head;

		head = head->next;
		free(temp);
	}
}
