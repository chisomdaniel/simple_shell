#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 *
 */

int main(void)
{
	char *line = malloc(1);
	size_t n = 0;
	int read = 0;
	char *quit = "exit";


	while (read >= 0)
	{
		printf("$ ");
		read = getline(&line, &n, stdin);
		if (read == -1)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		if (strcmp(line, quit) == 0)
		{
			free(line);
			printf("Exit\n");
			return (0);
		}
		printf("%s", line);
	}
	free(line);

	return (0);
}
