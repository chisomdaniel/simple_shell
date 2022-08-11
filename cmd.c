#include "shell.h"

/**
 *main - Runs a simple LINUX shell interpreter
 *
 *Return: exit status
 */
int main(void)
{
	char **argv, *buffer = NULL;
	size_t buffsize = 0;
	int len, stat = 0;

	while (1)
	{
		printf("$ ");
		len = getline(&buffer, &buffsize, stdin);
		if (len == -1)
		{
			printf("Exiting shell...\n");
			return (-1);
		}

		argv = strtoarg(buffer);
		if (argv[0] != NULL)
		{
			stat = execute_command(argv);
		}


		free_args(argv);
	}

	return (stat);
}
