#include "main.h"

/**
 * main - creating a simple shell
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char *line = malloc(1), **command;
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
			return (EXIT_FAILURE);
		}
		command = split_string(line, " ");
		
		child_pid = fork();
		if (child_pid == 0)
			execve(command[0], command, NULL);
		else if (child_pid <= -1)
		{
			free(line);
			return (-1);
		}
		else
			wait(&status);
	}


	free(line);
	return (0);
}

/*
int file_status(char *file)
{
	struct stat st;
	int rtn;

	rtn = stat(file, &st);
	if (rtn == 0)
	{
		return (0);
	}
	else
	{

	}


	return
}
*/
