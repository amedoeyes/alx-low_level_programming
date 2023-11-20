#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 *
 * @head: pointer to the head of a linked list
 *
 * Return: the head node's data
 */

int pop_listint(listint_t **head)
{
	int n = (*head)->n;
	listint_t *temp = *head;

	*head = (*head)->next;
	free(temp);

	return (n);
}
