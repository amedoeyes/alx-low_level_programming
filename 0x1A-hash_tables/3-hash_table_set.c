#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * create_node - creates a hash node
 *
 * @key: key
 * @value: value
 *
 * Return: pointer to the new node
 */

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new_node = NULL;

	if (key == NULL || value == NULL)
		return (NULL);

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
	}

	new_node->next = NULL;

	return (new_node);
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
	size_t index;
	hash_node_t *temp = NULL;

	if (ht == NULL || ht->array == NULL || ht->size == 0 || key == NULL ||
		value == NULL || *key == '\0')
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[index];

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			char *new_value = strdup(value);

			if (new_value == NULL)
				return (0);

			free(temp->value);
			temp->value = new_value;
			return (1);
		}
		temp = temp->next;
	}

	temp = create_node(key, value);
	if (temp == NULL)
		return (0);

	temp->next = ht->array[index];
	ht->array[index] = temp;
	return (1);
}
