#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - adds a node to the hash table
 *
 * @node: pointer to the node
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 on failure
 */

int add_node(hash_node_t **node, const char *key, const char *value)
{
	hash_node_t *new_node = NULL;

	if (node == NULL)
		return (0);

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
		return (0);

	new_node->value = strdup(value);
	if (new_node->value == NULL)
		return (0);

	if (*node == NULL)
		*node = new_node;
	else
		(*node)->next = new_node;

	return (1);
}

/**
 * hash_table_set - sets a value in a hash table
 *
 * @ht: pointer to hash table
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 on failure
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t **node = NULL;
	size_t index = key_index((unsigned char *)key, ht->size);

	if (ht == NULL || key == NULL || value == NULL || *key == '\0')
		return (0);

	node = &(ht->array[index]);

	return (add_node(node, key, value));
}
