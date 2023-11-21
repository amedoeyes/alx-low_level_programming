#include "lists.h"

/**
 * print_listint_safe - prints a linked list safely
 *
 * @head: pointer to the head of a linked list
 *
 * Return: number of nodes
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t **visited_nodes = NULL;
	size_t len = 0;
	size_t i;

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		len++;

		visited_nodes = realloc(visited_nodes, sizeof(listint_t *) * len);
		if (!visited_nodes)
			exit(98);

		visited_nodes[len - 1] = head;
		head = head->next;

		for (i = 0; i < len; i++)
		{
			if (visited_nodes[i] == head)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(visited_nodes);
				return (len);
			}
		}
	}

	free(visited_nodes);
	return (len);
}
