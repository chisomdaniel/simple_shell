#include <unistd.h>
#include <stdio.h>

int main()
{
	int rtrn = 0;

	char *argv[] = {"/bin/ls", "-a", NULL};

	rtrn = execve(argv[0], argv, NULL);
	if (rtrn <= -1)
	{
		printf("Error\n");
		return (1);
	}

	return (0);
}
