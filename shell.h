#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

/**
 *struct builtin_s - a structure defining builin commands
 *@name: the name of the builtin command
 *@func: function pointer to the builin command's function
 */
typedef struct builtin_s
{
	char *name;
	void (*func)(char **args);
} builtin_t;

/*Global environment variable*/
extern char **environ;

size_t wordCount(char *str);
char **strtoarg(char *str);
char *get_path(char *str);
int is_path(char *str);
char *_getenv(const char *name);
int execute_command(char **args);
void free_env(void);
void free_args(char **args);

/*strings functions*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strdup(char *str);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);

/*Builtins*/
void check_builtin(char **args);
void sh_env(char **args);
void sh_exit(char **args);

#endif
