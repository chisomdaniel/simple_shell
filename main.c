#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

size_t wordCount(char *str);

size_t wordCount(char *str)
{
  size_t count = 0, i = 0;

  while (str[i++])
    {
      if (str[i] == ' ' && str[i + 1] != ' ')
	count++;
    }

  return (count + 1);
}

char **environ;
int main()
{
  char *buffer = NULL, *copy_buffer = NULL;
  char **argv, *token;
  /*pid_t child_pid;*/
  size_t count, i = 0, buffsize = 0;
  int num_read;

  printf("$ ");
  num_read = getline(&buffer, &buffsize, stdin);
  if (num_read == -1)
    {
      printf("Exiting shell...");
      return (-1);
    }

  copy_buffer = malloc(sizeof(char) * num_read);
  if (copy_buffer == NULL)
    {
      perror("Unable to allocate buffer.");
      exit(1);
    }
  strcpy(copy_buffer, buffer);

  count = wordCount(copy_buffer);
  argv = malloc(sizeof(char *) * (count + 1));
  if (argv == NULL)
    printf("Cannot allocate memory.");

  token = strtok(copy_buffer, " \n");
  count = 0;
  while (token != NULL)
    {
      argv[count] = malloc(sizeof(char) * strlen(token));
      strcpy(argv[count], token);
      count++;
      token = strtok(NULL, " \n");
    }
  printf("%lu\n", count);

  argv[count] = NULL;
  i = 0;
  while (i < (count + 1))
    {
      printf("Argv[%lu]: %s\n", i, argv[i]);
      i++;
    }

  if(execve(argv[0], argv, environ) == -1)
    {
      perror("Error:");
    }
  printf("After execve\n");

  return (0);
}
