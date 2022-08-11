#include "shell.h"

char *get_path(char *str);
int is_path(char *str);

/**
 *get_path - get the path of a command
 *@str: pointer to the command
 *
 *Return: returns pointer to the path of the command
 */
char *get_path(char *str)
{
	char *copy_path, *path_list, *token, *buffer;
	struct stat st;

	if (is_path(str))
	{
		if (stat(str, &st) == 0)
			return (str);
	}

	path_list = _getenv("PATH");
	if (path_list != NULL)
	{
		copy_path = _strdup(path_list);
		token = strtok(copy_path, ":");
		while (token != NULL)
		{
			buffer = malloc(sizeof(char) * (_strlen(token) + _strlen(str) + 2));
			if (buffer == NULL)
				printf("Can't allocate buffer");
			_strcpy(buffer, token);
			_strcat(buffer, "/");
			_strcat(buffer, str);
			_strcat(buffer, "\0");

			if (stat(buffer, &st) == 0)
			{
				free(copy_path);
				return (buffer);
			}
			free(buffer);
			token = strtok(NULL, ":");
		}

		free(copy_path);
		if (stat(str, &st) == 0)
			return (str);
		return (NULL);
	}
	return (NULL);
}

/**
 *is_path - checks if a command contains a path
 *@str: pointer to the command entered
 *
 *Return: 1 - if the command contains a path
 *        Otherwise, returns 0
 */
int is_path(char *str)
{
	int i = 0, status;

	while (str[i] != '\0')
	{
		if (str[i] == '/')
		{
			status = 1;
			break;
		}
		else
		{
			status = 0;
			break;
		}
		i++;
	}
	return (status);
}
