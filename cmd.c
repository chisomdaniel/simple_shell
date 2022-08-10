#include "shell.h"

int main()
{
  char *buffer = NULL;
  char **argv, *command;
  size_t buffsize = 0;
  pid_t child_pid;
  int len, status;

  while (1)
    {
      printf("$ ");
      len = getline(&buffer, &buffsize, stdin);
      if (len == -1)
	{
	  printf("Exiting shell...\n");
	  return (-1);
	}

      argv = strtoarg(buffer);
      if (!is_path(argv[0]))
	{
	  command = get_path(argv[0]);
	  if (command == NULL)
	    {
	      perror("Error");
	      continue;
	    }
	}
      else
	command = argv[0];

      child_pid = fork();
      if (child_pid == -1)
	{
	  perror("Error: fork fails");
	  return (1);
	}
      if (child_pid == 0)
	{
	  if(execve(command, argv, environ))
	    {
	      perror("Error: ");
	    }
	  printf("After execve\n");
	  _exit(status);
	}
      else
	{
	  wait(&status);
	}
    }
   return (0);
}
