#include "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 *
 * @head: pointer to the head of linked list
 * @n: integer to be added
 *
 * Return: address of the new node or NULL
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
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
