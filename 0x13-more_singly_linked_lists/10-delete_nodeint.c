#include "lists.h"

/**
 * delete_first - deletes the head node of a linked list
 *
 * @head: pointer to the head of a linked list
 *
 * Return: 1
 */

int delete_first(listint_t **head)
{
	listint_t *temp;

	if (*head == NULL)
		return (-1);

	temp = *head;

	*head = (*head)->next;
	free(temp);

	return (1);
}

/**
 * delete_last - deletes the head node of a linked list
 *
 * @head: pointer to the head of a linked list
 *
 * Return: 1
 */

int delete_last(listint_t **head)
{
	listint_t *temp;

	if (*head == NULL)
		return (-1);

	temp = *head;

	while (!temp->next)
		temp = temp->next;

	free(temp->next);
	temp->next = NULL;

	return (1);
}

/**
 * list_len - prints all the elements of a linked list
 *
 * @h: pointer to head of list
 *
 * Return: number of nodes
 */

size_t list_len(const listint_t *h)
{
	int count = 0;

	while (h)
	{
		h = h->next;
		count++;
	}

	return (count);
}

/**
 * delete_nodeint_at_index - deletes the node at index index from a linked list
 *
 * @head: pointer to the head of a linked list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current_node = *head;
	listint_t *temp;
	size_t len = list_len(*head);
	size_t i;

	if (!*head)
		return (-1);

	if (index > len)
		return (-1);

	if (index == 0)
		return (delete_first(head));

	if (index == len - 1)
		return (delete_last(head));

	for (i = 0; i < index - 1; i++)
		current_node = current_node->next;

	temp = current_node->next;
	current_node->next = temp->next;
	free(temp);

	return (1);
}
