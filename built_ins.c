#include "shell.h"

void check_builtin(char **args);
void sh_exit(char **args);
void sh_env(char **args);

/**
 *check_builtin - checks if command is a builtin command
 *@args: pointer array
 */
void check_builtin(char **args)
{
	int i;

	builtin_t builtins[] = {
		{"exit", sh_exit},
		{"env", sh_env},
		{NULL, NULL},
	};

	for (i = 0; builtins[i].name != NULL; i++)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}
}

/**
 *sh_exit - exits the shell
 *@args: argument array
 */
void sh_exit(char **args)
{
	(void)args;
	exit(0);
}

/**
 *sh_env - lists the environment variables
 *@args: argument array
 */
void sh_env(char **args)
{
	(void)args;
	char **env = environ;

	while (*env)
		printf("%s\n", *env++);
}
