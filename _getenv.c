#include "main.h"


extern char **environ;

int strlength(const char *str)
{
	int count = 0;

	while (str[count] != '\0')
		count++;

	return (count);
}


char *_getenv(const char *name)
{
	int i, j, k, length, count;
	char *value = NULL;

	count = j = k = 0;

	if (name == NULL)
		return (NULL);

	length = strlength(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		while (environ[i][j] == name[j])
		{
			j++;
			if (j == length && environ[i][j] == '=')
			{
				value = environ[i];
				/* Return the values after the '=' sign */
				return (value + (j + 1));
			}
		}
		j = 0;
	}
	return (value); /* Returns NULL also if no match */

}

char **getpath()
{
	char *enviro, **paths;

	enviro = _getenv("PATH");
	paths = split_string(enviro, ":"); /* split the PATH variable */

	return (paths);
}

char *checkpath(char *str)
{
	char **paths = getpath(), *fullpath;
	int i, len;
	struct stat st;

	if (str == NULL)
		return (NULL);
	/* check to ensure the PATH hasn't been given already */
	if (str[0] == '/' || (str[0] == '.' && str[1] == '/'))
		return (str);

	len = strlength(str);
	for (i = 0; paths[i] != NULL; i++)
	{
		len += strlength(paths[i]) + 1; /* extra 1 for the '/' */
		fullpath = malloc(sizeof(char) * (len + 1));
		strcpy(fullpath, paths[i]);
		strcat(fullpath, "/");
		strcat(fullpath, str);
		if (stat(fullpath, &st) == 0)
		{
			return (fullpath);
		}
	}
	perror("stat");
	return (NULL);
}
/*
int main(int argc, char **argv)
{
	char *path;

	if ((path = checkpath(argv[1])) == NULL)
		printf("No file found\n");
	else
		printf("%s\n", path);

	return (0);
}
*/
