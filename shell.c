#include "main.h"

/**
 * main - creating a simple shell
 *
 * @argc: the number of arguments passed
 * @argv: pointer to the arguments passed
 * @env: the environment variables
 *
 * Return: 0 on success
 */

int main(int argc, char **argv, char *env[])
{
	char *line, **command, *path;
	size_t n = 0;
	int read = 0, status;
	pid_t child_pid;
	(void)argc;

	while (read >= 0)
	{
		printf("($)-> ");
		read = getline(&line, &n, stdin);
		if (read <= -1)
		{
			free(line);
			return (0);
		}
		command = split_string(line, " \n");
		path = checkpath(command[0]);
		if (path == NULL)
		{
			printf("%s: %s: not found\n", argv[0], command[0]);
			continue;
		}
		command[0] = path;
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve(command[0], command, env) == -1)
				perror("execve error");
		}
		else if (child_pid <= -1)
		{
			free(line);
			perror("Child process error");
			return (-1);
		}
		else
			wait(&status);
	}
	free(line);
	return (0);
}


