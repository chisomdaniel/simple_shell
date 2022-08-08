#include "main.h"

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
	char *strclone;
	char **strsplit, *word;
	int word_count = 0, letter_count = 0, i = 0, j = 1;

	/* count the number of words and letters*/
	if (str[0] != ' ')
		word_count++;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			word_count++;
		letter_count++;
		i++;
	}

	/* allocate space for the string copy and an array of string */
	strclone = malloc(sizeof(char) * (letter_count + 1));
	strsplit = malloc(sizeof(strsplit) * (word_count + 1));
	if (strclone == NULL || strsplit == NULL)
		return (0);
	strcpy(strclone, str);
	strclone[letter_count] = '\0';

	/* fill up the array of string with pointers to the string */
	strsplit[0] = strtok(strclone, deli);
	while (j < word_count)
	{
		word = strtok(NULL, deli);
		strsplit[j] = word;
		j++;
	}
	strsplit[word_count] = '\0';
	return (strsplit);
}


/* Testing the function */
/*
int main()
{
	char **string;
	int i = 0;


	string = split_string("Hello World of thurnder", " ");

	while (string[i])
	{
		printf("%s\n", string[i]);
		i++;
	}

	return (0);
}
*/
