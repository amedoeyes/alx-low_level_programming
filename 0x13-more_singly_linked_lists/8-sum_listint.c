#include "lists.h"
/**
 * sum_listint - sums all the data of a linked list
 *
 * @head: pointer to the head of a linked list
 *
 * Return: sum of the data
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
