#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value in a sorted singly linked list of integers
 * using the Jump search algorithm
 *
 * @list: Pointer to the head of the list to search in
 * @size: Number of nodes in list
 * @value: Value to search for
 *
 * Return: The first node where value is located or NULL if value is not
 * present
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t i, jump;
	listint_t *current, *prev;

	if (list == NULL)
		return (NULL);

	jump = sqrt(size);
	current = list;

	while (current->n < value)
	{
		prev = current;

		for (i = 0; i < jump && current->next != NULL; i++)
			current = current->next;

		printf("Value checked at index [%ld] = [%d]\n", current->index,
			   current->n);

		if (current->next == NULL || current->index + 1 >= size)
			break;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", prev->index,
		   current->index);

	while (prev->index < current->index)
	{
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);

		if (prev->n == value)
			return (prev);

		prev = prev->next;
	}

	printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);

	return (NULL);
}
