#include "lists.h"

/**
 * add_node_end - add node at the end of a linked list
 *
 * @head: pointer to head of linked list
 * @str: string to add
 *
 * Return: pointer to new node or NULL if failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = (list_t *)malloc(sizeof(list_t));

	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	new_node->len = strlen(str);
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		list_t *current_node = *head;

		while (current_node && current_node->next)
			current_node = current_node->next;

		current_node->next = new_node;
	}

	return (new_node);
}
