#include "shell.h"

size_t wordCount(char *str);
char **strtoarg(char *str);

/**
 *wordCount - counts the number of words in a string
 *@str: string to be counted
 *
 *Return: the number of words in the string
 */
size_t wordCount(char *str)
{
	size_t count = 0, i = 0;

	while (str[i++])
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			count++;
	}

	return (count + 1);
}

/**
 *strtoarg - splits a string into argument
 *@str: string to be splitted
 *
 *Return: an array of arguments
 */
char **strtoarg(char *str)
{
	size_t count;
	char *token, **args, *cpy;

	cpy = malloc(sizeof(char) * _strlen(str));
	if (cpy == NULL)
	{
		printf("Cannot allocate memory\n");
	}
	_strcpy(cpy, str);

	count = wordCount(str);
	args = malloc(sizeof(char *) * (count + 1));
	if (args == NULL)
		printf("Cannot allocate memory.\n");

	token = strtok(cpy, " \n");
	count = 0;
	while (token != NULL)
	{
		args[count] = malloc(sizeof(char) * _strlen(token));
		_strcpy(args[count], token);
		count++;
		token = strtok(NULL, " \n");
	}
	args[count] = NULL;

	free(cpy);
	return (args);
}
