#include "hash_tables.h"

/**
 * key_index - returns index of key in a hash table
 * @key: key
 * @size: size of the hash table array
 *
 * Return: index of key in the array
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
