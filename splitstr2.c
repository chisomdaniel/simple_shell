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
	int word_count = 0, letter_count = 0, i = 0, j = 0, k = 0;


	if (str[0] != deli[0])
		word_count++;
	while (str[i] != '\0')
	{
		if (str[i] == deli[0] && str[i + 1] != deli[0])
			word_count++;
		letter_count++;
		i++;
	}
	printf("words: %i\nletters: %i\n", word_count, letter_count);

	/* allocate space for the string copy and an array of string */
	strclone = malloc(sizeof(char) * (letter_count + 1));
	strsplit = malloc(sizeof(char *) * (word_count + 1));
	if (strclone == NULL || strsplit == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}
	printf("malloc success\n");
	strcpy(strclone, str);

	while (strclone[j] != '\0')
	{
		if (strclone[0] != deli[0])
		{
			strsplit[k] = strclone;
			k++;
			printf("%s\n", strsplit[0]);
		}
		if (strclone[j] == deli[0] && strclone[j + 1] != deli[0])
		{
			strclone[j] = '\0';
			strsplit[k] = strclone + (j + 1);
			k++;
			printf("%s\n", strsplit[k]);
		}
		j++;
	}
	return (strsplit);
}


/* Testing the function */

int main()
{
	char **string;
	int i = 0;


	string = split_string("Hello World of thurnder", " ");

	while (string[i])
	{
		printf("%s\n", string[i]);
		//free(string[i]);
		i++;
	}
	//free(string);
	return (0);
}

