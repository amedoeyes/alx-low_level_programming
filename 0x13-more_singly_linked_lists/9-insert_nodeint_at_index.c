#include "lists.h"

/**
 * add_first - adds a node at the beginning of a linked list
 *
 * @head: pointer to the head of linked list
 * @n: integer to be added
 *
 * Return: address of the new node or NULL
 */

listint_t *add_first(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

/**
 * add_last - adds a node at the end of a linked list
 *
 * @head: pointer to the head of linked list
 * @n: integer to be added
 *
 * Return: address of the new node or NULL
 */

listint_t *add_last(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		listint_t *current_node = *head;

		while (current_node->next)
			current_node = current_node->next;

		current_node->next = new_node;
	}

	return (new_node);
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
 * insert_nodeint_at_index - inserts a new node at a given position in a linked
 * list
 *
 * @head: pointer to the head of a linked list
 * @idx: index to insert the new node at
 * @n: data to insert
 *
 * Return: pointer to the new node or NULL
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current_node = *head;
	listint_t *new_node;
	size_t len = list_len(*head);
	size_t i;

	if (idx > len)
		return (NULL);

	if (idx == 0)
		return (add_first(head, n));

	if (idx == len)
		return (add_last(head, n));

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	for (i = 0; i < idx - 1; i++)
		current_node = current_node->next;

	new_node->n = n;
	new_node->next = current_node->next;
	current_node->next = new_node;

	return (new_node);
}
