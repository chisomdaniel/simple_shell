#include "main.h"

#undef TEST_MODE

/**
 * wordcount - count the number of words in a string
 *
 * @str: the string
 * @deli: the separation character
 *
 * Return: an int which is the number of words
 */

int wordcount(char *str, const char *deli)
{
	int word_count = 0, i;

	if (str[0] != deli[0] && str[0] != '\0')
		word_count++;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == deli[0] && str[i + 1] != deli[0])
			word_count++;
	}
	return (word_count);
}

/**
 * split_string - a function that separates words in a string
 *
 * @str: a pointer the string
 * @deli: the string delimeter
 *
 * Return: a pointer to an array of the strings that is null terminated
 */

char **split_string(char *str, const char *deli)
{
	char *strclone, **strsplit;
	int word_count, letter_count = 0, i = 0, m = 0;

	if (str == NULL)
		return (NULL);
	word_count = wordcount(str, deli);
	letter_count = _strlen(str);

	/* allocate space for the string copy and an array of string */
	strclone = malloc(sizeof(char) * (letter_count + 1));
	strsplit = malloc(sizeof(char *) * (word_count + 1));
	if (strclone == NULL || strsplit == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}
	_strcpy(strclone, str);

	for (i = 0; strclone[i] != '\0'; i++)
	{
		if (strclone[i] == deli[0] || strclone[i] == '\n')
		{
			strclone[i] = '\0';
		}
	}
	for (i = 0; i < letter_count; i++) /* changed from i < word_count */
	{
		if (strclone[i] != '\0' && (strclone[i - 1] == '\0' || i == 0))
		{
			strsplit[m] = malloc(sizeof(char) * (_strlen(strclone + i) + 1));
			_strcpy(strsplit[m], strclone + i);
			m++;
		}
	}
	strsplit[word_count] = '\0';
	free(strclone);
	return (strsplit);
}

/**
 * freestr - a function that frees the pointers created by the function above
 *
 * @str: the pointers to be freed
 *
 * Return: Nothing
 */

void freestr(char **str)
{
	int i = 0;

	if (str == NULL)
		return;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}


#ifdef TEST_MODE

/**
 * main - define TEST_mode if you want to test
 *	how the function above work
 *
 * @argc: number of arguments passed
 * @argv: pointer to an array of arguments passed
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char **string;
	int i = 0;

	string = split_string(argv[1], argv[2]);

	while (string[i])
	{
		printf("%s\n", string[i]);
		i++;
	}
	freestr(string);
	return (0);
}
#endif
