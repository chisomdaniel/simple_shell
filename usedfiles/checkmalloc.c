#include <stdio.h>

/**
 * checkmalloc - a funtion to check the return value of malloc
 *
 * @ptr: the malloc return value
 *
 * Return: -1 on faliure or 1 on success
 */

int checkmalloc(char *ptr)
{
	if (ptr == NULL)
	{
		printf("malloc failed!\n");
		return (-1);
	}
	return (0);
}
