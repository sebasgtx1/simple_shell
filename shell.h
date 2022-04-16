#ifndef _SHELL_
#define _SHELL_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define BUFSIZE 1024
#define DELIMITERS " =:;\t"

extern char **environ;
/**
 * struct build_in - Struct of pointers to funtions
 * @build_in: build_in identifier
 * @func: function associated
 */

typedef struct build_in
{
	char *build_in;
	int (*func)(char **args);
} build_in_t;
char *read_input(void);
char *_getline(void);
char *_strtok(char *str, char *d);
void shell_start(void);
char **av_line_saver(char *line);
int _process_luncher(char **args);
int _cd(char **args);
int hlp(char **args);
int ext(char **args);
int _process_launcher(char **args);
int _execute(char **args);
int (*get_build_in(char *build_in))(char **args);
int search_no_build_in(char **args);
int _env(char **args __attribute__((unused)));
size_t _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
void _strcat(char *s1, char *s2);
void *_calloc(unsigned int nmemb, unsigned int size);
void _realloc(char *ptr, int new_size);
#endif
