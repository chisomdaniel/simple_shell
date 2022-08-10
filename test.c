#include "shell.h"

int main()
{
  char **argv, *copy_buffer, *buffer = NULL, *pth;
  int i;
  size_t num_read, buffsize = 0;

  num_read = getline(&buffer, &buffsize, stdin);
  copy_buffer = strdup(buffer);
  argv = strtoarg(copy_buffer);
  i = is_path(argv[0]);
  printf("%d\n", i);
  pth = get_path(argv[0]);
  printf("%s\n", pth);

  return (0);
}
