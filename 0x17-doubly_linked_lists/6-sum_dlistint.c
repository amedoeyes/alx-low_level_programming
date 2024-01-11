#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data in an int doubly linked list
 *
 * @head: head of the linked list
 *
 * Return: sum of all data
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
