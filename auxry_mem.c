#include "secondmain.h"

/**
 * _memorycpy - This program copies
 * information between void pointers.
 * @newpointer: The destination pointer.
 * @pointer: The source pointer.
 * @size: size of the new pointer.
 * Return: no return.
 */

void _memorycopy(void *nwpoint, const void *point, unsigned int all)
{
	char *char_pointer = (char *)point;
	char *char_newpointer = (char *)nwpoint;
	unsigned int a = 0;

	while (a < all)
	{
		char_newpointer[a] = char_pointer[a];
		a++;
	}
}

/**
 * _reallocate - This program reallocates a memory block.
 * @point: This is pointer to the memory previously allocated.
 * @prevs_size:  This size, in bytes, of the allocated space of ptr.
 * @nw_size: This new size, in bytes, of the new memory block.
 *
 * Return: point.
 * if nw_size == prevs_size, returns point without changes.
 * if malloc fails, returns NULL.
 */

void *_reallocated(void *point, unsigned int previous_size, unsigned int new_size)
{
	void *newpointer;

	if (point == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(point);
		return (NULL);
	}

	if (new_size == previous_size)
		return (point);

	newpointer = malloc(new_size);
	if (newpointer == NULL)
		return (NULL);

	if (new_size < previous_size)
		_memorycopy(newpointer, point, new_size);
	else
		_memorycopy(newpointer, point, previous_size);

	free(point);
	return (newpointer);
}

/**
 * _realocdp - This program reallocates a memory block of a double pointer.
 * @point: This double pointer to the memory
 * previously allocated.
 * @prevs_size: This size, in bytes, of the allocated space of ptr.
 * @nw_size: nw size, in bytes, of the new memory block.
 * Return: point.
 * if nw_size == prevs_size, returns ptr without changes.
 * if malloc fails, returns NULL.
 */

char **_reallocatedp(char **point, unsigned int previous_size, unsigned int new_size)
{
	char **newpointer;
	unsigned int a = 0;

	if (point == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == previous_size)
		return (point);

	newpointer = malloc(sizeof(char *) * new_size);
	if (newpointer == NULL)
		return (NULL);

	while (a < previous_size)
	{
		newpointer[a] = point[a];
		a++;
	}
	free(point);

	return (newpointer);
}
