#include "shell.h"

char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);

/**
 *_strcmp - compare two strings
 *@s1: pointer to the first string
 *@s2: pointer to the second string
 *
 *Return: the difference between string s1 and  s2
 */
int _strcmp(char *s1, char *s2)
{
  int i;

  for (i = 0; s1[i] == s2[i]; i++)
    if (s1[i] == '\0')
      return (0);
  
  return (s1[i] - s2[i]);
}

/**
 *_strncat - concatenates two strings using at most n bytes from the src string
 *@dest: pointer to the string dest
 *@src: pointer to the string src
 *@n: number of bytes of source string to be appended to dest
 *
 *Return: pointer to the resulting dest string
 */
char *_strncat(char *dest, char *src, int n)
{
  int i = 0, len = 0;

  while (dest[i++])
    len++;
  for (i = 0; src[i] && i < n; i++)
    dest[len++] = src[i];

  return (dest);
}

/**
 *_strcat - appends a string src to another string dest
 *@dest: pointer to the string dest
 *@src: pointer to the string src
 *
 *Return: pointer to the concatenated string
 */
char *_strcat(char *dest, char *src)
{
  int i = 0, len_dest = 0;

  for (i = 0; dest[i] != '\0'; i++)
    len_dest++;

  for (i = 0; src[i]; i++)
    dest[len_dest++] = src[i];

  return (dest);
}

/**
 *_strlen - find the length of a string
 *@str: pointer to the string\
 *
 *Return: the length of the string
 */
int _strlen(char *str)
{
  size_t len = 0;

  while (*str++)
    len++;

  return (len);
}
 
/**
 *_strcpy - copies a string from src to another string dest
 *@dest: pointer to string being copied to
 *@src: pointer to string being copied from
 *
 *Return: pointer to the dest string.
 */
char *_strcpy(char *dest, char *src)
{
  int i = 0;

  while ((dest[i] = src[i]) != '\0')
    i++;
  return (dest);
}
