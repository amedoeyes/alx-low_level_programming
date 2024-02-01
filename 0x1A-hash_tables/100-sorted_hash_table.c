#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - creates a hash table
 *
 * @size: the size of the array
 *
 * Return: a pointer to the newly created hash table
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = NULL;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * create_node - creates a hash node
 *
 * @key: key
 * @value: value
 *
 * Return: pointer to the new node
 */

static shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *new_node = NULL;

	if (key == NULL || value == NULL)
		return (NULL);

	new_node = malloc(sizeof(shash_node_t));
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
	new_node->sprev = NULL;
	new_node->snext = NULL;

	return (new_node);
}

/**
 * add_node - adds a node to the hash table sorted list
 *
 * @ht: pointer to the hash table
 * @node: pointer to the new node
 *
 * Return: 1 on success, 0 on failure
 */

int add_node(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *temp = NULL;

	if (ht == NULL || node == NULL)
		return (0);

	temp = ht->shead;

	if (temp == NULL)
	{
		ht->stail = node;
		ht->shead = node;
	}
	else
	{
		while (temp != NULL && strcmp(temp->key, node->key) < 0)
			temp = temp->snext;

		if (temp == NULL)
		{
			node->sprev = ht->stail;
			ht->stail = node;
		}
		else
		{
			node->snext = temp;
			node->sprev = temp->sprev;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				ht->shead = node;
			temp->sprev = node;
		}
	}

	return (1);
}

/**
 * shash_table_set - sets a value in a hash table
 *
 * @ht: pointer to hash table
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 on failure
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	size_t index;
	shash_node_t *temp = NULL;
	shash_node_t *new_node = NULL;

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

	new_node = create_node(key, value);
	if (new_node == NULL)
		return (0);

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (add_node(ht, new_node));
}

/**
 * shash_table_get - get value associated with key
 *
 * @ht: pointer to hash table
 * @key: key to look up
 *
 * Return: value associated with key, or NULL if key not found
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node = NULL;

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

/**
 * shash_table_print - prints a hash table
 *
 * @ht: pointer to hash table
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node = NULL;

	if (ht == NULL || ht->array == NULL)
		return;

	node = ht->shead;

	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->snext != NULL)
			printf(", ");
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse
 *
 * @ht: pointer to hash table
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node = NULL;

	if (ht == NULL || ht->array == NULL)
		return;

	node = ht->stail;

	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->sprev != NULL)
			printf(", ");
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * node_delete - frees a node
 *
 * @node: pointer to the node
 */

static void node_delete(shash_node_t *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

/**
 * shash_table_delete - frees a hash table
 *
 * @ht: pointer to the hash table
 */

void shash_table_delete(shash_table_t *ht)
{
	if (ht == NULL)
		return;

	while (ht->shead != NULL)
	{
		shash_node_t *node = ht->shead;

		ht->shead = ht->shead->snext;
		node_delete(node);
	}

	node_delete(ht->stail);

	free(ht->array);
	free(ht);
}
