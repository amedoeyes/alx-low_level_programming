#include "hash_tables.h"
#include <stdlib.h>

/**
 * node_delete - frees a node
 *
 * @node: pointer to the node
 */

void node_delete(hash_node_t *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

/**
 * hash_table_delete - frees a hash table
 *
 * @ht: pointer to the hash table
 */

void hash_table_delete(hash_table_t *ht)
{
	size_t i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		hash_node_t *node = ht->array[i];

		while (node != NULL)
		{
			hash_node_t *temp = node;

			node = node->next;
			node_delete(temp);
		}
	}

	free(ht->array);
	free(ht);
}
