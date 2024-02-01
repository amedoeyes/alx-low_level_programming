#include "hash_tables.h"

/**
 * key_index - returns index of key in a hash table
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return hash_djb2(key) % size;
}
