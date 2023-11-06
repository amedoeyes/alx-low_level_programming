#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * new_dog - create a new dog
 *
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to new dog struct
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	char *d_name, *d_owner;

	if (name == NULL || owner == NULL)
		return (NULL);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	d_name = malloc(strlen(name) + 1);
	if (d_name == NULL)
	{
		free(dog);
		return (NULL);
	}
	strcpy(d_name, name);

	d_owner = malloc(strlen(owner) + 1);
	if (d_owner == NULL)
	{
		free(d_name);
		free(dog);
		return (NULL);
	}
	strcpy(d_owner, owner);

	dog->name = d_name;
	dog->age = age;
	dog->owner = d_owner;

	return (dog);
}
