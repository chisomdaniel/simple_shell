#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

char **split_string(char *str, const char *deli);
char *_getenv(const char *name);
char **getpath();
char *checkpath(char *str);


#endif
