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

extern char **environ;


void *re_alloc(void *str, unsigned int old, unsigned int news);
void asi_lineptr(char **lineptr, size_t *n, char *buf, size_t b);
ssize_t get_line(char **lineptr, size_t *n, FILE *str);
void str_free(char **argv, char **frs_argv);
char *pid_value(void);
char *environ_value(char *beg, int n);
void replac_variable(char **argv, int *i);
#endif
