#include "shell.h"

char *_getenv(const char *name);

/**
 *_getenv - gets the value of an environment from the environment
 *          variables list
 *@name: name of the environment variable
 *
 *Return: pointer to the value of the environment variable\
 */
char *_getenv(const char *name)
{
	int i, j;
	int status;

	for (i = 0; environ[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		}
		if (status)
			return (&environ[i][j + 1]);
	}
	return (NULL);
}
