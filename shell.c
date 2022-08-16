#include "main.h"

/**
 * main - creating a simple shell
 *
 * Return: 0 on success
 */

int main(int argc, char **argv, char *env[])
{
	char *line = malloc(1), **command, *path;
	size_t n = 0;
	int read = 0, status, i = 0;
	pid_t child_pid;
	/*char *envp[] = {"PATH=/bin", 0};*/

	while (read >= 0)
	{
		printf("simple_shell ($)-> ");
		read = getline(&line, &n, stdin);
		if (read <= -1)
		{
			free(line);
			return (0);
		}
		command = split_string(line, " \n");
		if ((path = checkpath(command[0])) == NULL)
			continue;
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


