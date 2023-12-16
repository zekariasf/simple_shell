#ifndef MAIN_H
#define MAIN_H

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/type.h>
#include <fcntl.h>

#define EXIT -3
#define END_FILE -2
/**
 * struct builtin_s - builtin commands
 * @name: name of command
 * @f: function pointer
 */
typedef struct list_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

int hist;

extern char **environ;


void *re_alloc(void *str, unsigned int old, unsigned int news);
void asi_lineptr(char **lineptr, size_t *n, char *buf, size_t b);
ssize_t get_line(char **lineptr, size_t *n, FILE *str);

void str_free(char **argv, char **frs_argv);
char *pid_value(void);
char *environ_value(char *beg, int n);
void replac_variable(char **argv, int *i);

void line_handler(char **argv, ssize_t len);
ssize_t new_line(char *len);
void opretors_log(char *len, ssize_t *len_new);

char *argv_get(char *len, int*ret);
int argv_run(char **argv, char **big, int *ret);
int argv_handle(int *ret);
int argv_call(char **argv, char **big, int *ret);
int argv_check(char **argv);
#endif
