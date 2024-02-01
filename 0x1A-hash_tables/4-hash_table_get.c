#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_get - get value associated with key
 *
 * @ht: pointer to hash table
 * @key: key to look up
 *
 * Return: value associated with key, or NULL if key not found
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node = NULL;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	node = ht->array[key_index((unsigned char *)key, ht->size)];

	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);

		node = node->next;
	}

	return (NULL);
}
