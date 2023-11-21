#include "lists.h"

/**
 * find_listint_loop - find the cycle in a linked list
 *
 * @head: pointer to the head of a linked list
 *
 * Return: pointer to the node where the cycle starts
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;

			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			return (slow);
		}
	}

	return (NULL);
}
