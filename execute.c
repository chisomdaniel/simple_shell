#include "shell.h"

int execute_command(char **args);

/**
 *execute_command - executes a command
 *@args: pointer array of arguments
 *
 *Return: -1 on failure
 */
int execute_command(char **args)
{
	pid_t child_pid;
	char *command, **env;
	int status;

	env = environ;

	check_builtin(args);

	command = get_path(args[0]);

	if (command == NULL)
	{
		return (-1);
	}

	child_pid = fork();

	if (child_pid == 0)
	{
		execve(command, args, env);
		perror(args[0]);
		free_env();
		return (-1);
	}
	else if (child_pid > 0)
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("Error");
		return (-1);
	}
	return (0);
}
