#include "lists.h"

/**
 * free_list - frees a linked list
 *
 * @head: pointer to head of linked list
 */

void free_list(list_t *head)
{
	while (head)
	{
		list_t *temp = head;

		free(temp->str);
		head = temp->next;
		free(temp);
	}
}
