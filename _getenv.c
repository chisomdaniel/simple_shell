#include "main.h"

#undef TEST

/**
 * strlength - gets the length of a string
 *
 * @str: the string pointer
 *
 * Return: the lenght or 0 if str is NULL
 */

int strlength(const char *str)
{
	int count = 0;

	if (str == NULL)
		return (0);

	while (str[count] != '\0')
		count++;

	return (count);
}

/**
 * _getenv - get the value of a specified environment variable name
 *
 * @name: the desired environment name
 *
 * Return: the value
 */

char *_getenv(const char *name)
{
	int i, j, k, length;
	char *value = NULL;

	j = k = 0;

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

/**
 * getpath - get the individual PATH locations
 *
 * Return: a pointer to a string of each path
 */

char **getpath()
{
	char *enviro, **paths;

	enviro = _getenv("PATH");
	paths = split_string(enviro, ":"); /* split the PATH variable */

	return (paths);
	/* path needs to be freed */
}

/**
 * checkpath - look for the path of a given executable file
 *
 * @str: the file name
 *
 * Return: the path to the file, or NULL under certain conditions
 */

char *checkpath(char *str)
{
	char **paths, *fullpath;
	int i, len;
	struct stat st;

	if (str == NULL)
		return (NULL);
	/* check to ensure the PATH hasn't been given already */
	if (str[0] == '/' || (str[0] == '.' && str[1] == '/'))
	{
		if (stat(str, &st) == 0)
			return (str);
		else
			return (NULL);
	}

	paths = getpath(); /* path needs to be freed */
	len = strlength(str);
	for (i = 0; paths[i] != NULL; i++)
	{
		len += strlength(paths[i]) + 1; /* extra 1 for the '/' */
		fullpath = malloc(sizeof(char) * (len + 1));
		_strcpy(fullpath, paths[i]);
		_strcat(fullpath, "/");
		_strcat(fullpath, str);
		if (stat(fullpath, &st) == 0)
		{
			freestr(paths);
			return (fullpath);
		}
	}
	freestr(paths);
	return (NULL);
}

#ifdef TEST

/**
 * main - the main function,
 * this function is included only when in TEST mode,
 * i.e when TEST is defined
 *
 * @argc: number of arguments inputed
 * @argv: string arguments
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char *path;

	path = checkpath(argv[1]);

	if (path == NULL)
		printf("No file found\n");
	else
		printf("%s\n", path);
		free(path);

	return (0);
}
#endif
