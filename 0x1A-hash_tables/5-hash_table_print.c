#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * hash_table_print - prints a hash table
 *
 * @ht: pointer to hash table
 */

void hash_table_print(const hash_table_t *ht)
{
	size_t i;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *temp = ht->array[i];

		while (temp != NULL)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", temp->key, temp->value);
			temp = temp->next;
			first = 0;
		}
	}
	printf("}\n");
}
