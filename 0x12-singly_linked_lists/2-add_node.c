#include "lists.h"

/**
 * add_node - add node at the beginning of a linked list
 *
 * @head: pointer to head of linked list
 * @str: string to add
 *
 * Return: pointer to new node or NULL if failed
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = (list_t *)malloc(sizeof(list_t));

	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	new_node->len = strlen(str);
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
