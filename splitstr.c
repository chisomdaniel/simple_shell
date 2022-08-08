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
	int word_count = 0, letter_count = 0, i = 0, j = 0;

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
	strsplit = malloc(sizeof(char *) * (word_count + 1));
	if (strclone == NULL || strsplit == NULL)
	{
		perror("couldn't allocate strsplit or strclone: ");
		return(-1);
	}
	strcpy(strclone, str);
	strclone[letter_count] = '\0';

	/* fill up the array of string with pointers to the string */
	word = strtok(strclone, deli);
	while (word != NULL)
	{
		if ((strsplit[j] = malloc(sizeof(char) * strlen(word))) == NULL)
		{
			perror("Malloc error: token: ");
			return(-1);
		}
		strcpy(strsplit[j], word);
		word = strtok(NULL, deli);
		j++;
	}
	strsplit[word_count] = '\0';
	free(strclone);
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
		free(string[i]);
		i++;
	}
	free(string);
	return (0);
}
*/
