#ifndef MAIN_H
#define MAIN_H

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

extern char **environ;
char *get_env(char *env_name);
void identify(char **argv);
void enviro_lsit(void);
void exit_shell(void);
int str_cmp(char *s1, char *s2);
int exit_prs(pid_t pid);
void str_cat(char *pest, char *copy);
void str_cpy(char *cpy, char *elem);
char *full_path(char *str);
char **tok_string(char *str, char *delim);
void execut(char **argv, char **envi);
char *letter_identify(char *word, char old_let, char new_let);

#endif
