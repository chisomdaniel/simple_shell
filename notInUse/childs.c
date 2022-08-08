#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	pid_t child_pid;
	int i = 5, rtrn, status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (i > 0)
	{
		child_pid = fork();
		if (child_pid == -1 || rtrn == -1)
		{
			return (1);
		}
		if (child_pid == 0)
		{
			rtrn = execve(argv[0], argv, NULL);
		}
		else
		{
			wait(&status);
		}
		i--;
	}


	return (0);
}
