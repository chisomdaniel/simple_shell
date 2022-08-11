#include "shell.h"

void free_env(void);
void free_args(char **args);

/**
 *free_env - frees the environment
 */
void free_env(void)
{
	int index;

	for (index = 0; environ[index]; index++)
		free(environ[index]);
	free(environ);
}

/**
 *free_args - frees the argument list
 *@args: pointer array of arguments
 */
void free_args(char **args)
{
	int i;

	for (i = 0; args[i] || args[i + 1]; i++)
		free(args[i]);
}
