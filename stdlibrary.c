#include "main.h"

/**
 * _strlen - get the length of a string
 *
 * @str: the string poiner
 *
 * Return: the length of the string
 */

int _strlen(char *str)
{
	int count = 0;

	while (str[count] && str != NULL)
	{
		count++;
	}
	return (count);
}

/**
 * _strcpy - copy a string from one array to another
 *
 * @to: array to copy to
 * @from: array to copy from
 *
 * Return: the string it copied to
 */

char *_strcpy(char *to, char *from)
{
	int i = 0;

	if (to == NULL || from == NULL)
		return (NULL);
	while (from[i] != '\0')
	{
		to[i] = from[i];
		i++;
	}
	to[i] = '\0';

	return (to);
}

/**
 * _strcat - concatinate two string
 *
 * @strto: concat to this string
 * @strfrom: copy contents from this string
 *
 * Return: the full string
 */

char *_strcat(char *strto, char *strfrom)
{
	int i = 0, len;

	if (strto == NULL || strfrom == NULL)
		return (NULL);

	len = _strlen(strto);
	while (strfrom[i] != '\0')
	{
		strto[len] = strfrom[i];
		len++;
		i++;
	}
	strto[len] = '\0';

	return (strto);
}
