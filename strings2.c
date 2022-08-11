#include "shell.h"

char *_strdup(char *str);

/**
 *_strdup - duplicates a string
 *@str: pointer to string to be duplicated
 *
 *Return: pointer to the duplicated string
 *        if string = NULL or memory is insuficient, NULL
 */
char *_strdup(char *str)
{
	int i, len;
	char *ptr;

	i = len = 0;
	if (str == NULL)
		return (NULL);
	while (str[i++])
		len++;

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		ptr[i] = str[i];
	ptr[len] = '\0';

	return (ptr);
}
