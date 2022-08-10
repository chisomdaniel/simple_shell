#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/*Global environment variable*/
extern char **environ;

size_t wordCount(char *str);
char **strtoarg(char *str);
char *get_path(char *str);
int is_path(char *str);
char *_getenv(const char *name);

/*strings functions*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);


#endif
