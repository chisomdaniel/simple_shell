#include "shell.h"

char *get_path(char *str);
int is_path(char *str);

/**
 *get_path - get the path of a command
 *@str: pointer to the command
 *
 *Return: returns pointer to the path of the command
 */
char *get_path(char *str)
{
  char *path_list, *token, *buffer;
  struct stat st;
  
  path_list = _getenv("PATH");

  token = strtok(path_list, ":");
  while (token != NULL)
    {
      buffer = malloc(sizeof(char) * (_strlen(token) + _strlen(str) + 2));
      if (buffer == NULL)
	perror("Can't allocate buffer");
      _strcpy(buffer, token);
      _strcat(buffer, "/");
      _strcat(buffer, str);
      if (stat(buffer, &st) == 0)
	{
	  return (buffer);
	}
      token = strtok(NULL, ":");
    }
}

/**
 *is_path - checks if a command contains a path
 *@str: pointer to the command entered
 *
 *Return: 1 - if the command contains a path
 *        Otherwise, returns 0
 */
int is_path(char *str)
{
  int i = 0, status;

  while (str[i] != '\0')
    {
      if (str[i] == '/')
	{
	  status = 1;
	  break;
	}
      else
	{
	  status = 0;
	  break;
	}
      i++;
    }
  return (status);
}
