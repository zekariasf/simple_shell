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

/* buil_alias.c */
int alias_shell(char **args, char __attribute__((__unused__)) **start);
void set_alias(char *v_name, char *val);
void write_alias(alias_t *alias);
char **replace_alias(char **args);

/* buil_helpers.c */
void call_hall(void);
void call_alias(void);
void call_cd(void);
void call_exit(void);
void call_help(void);
void call_env(void);
void call_setenv(void);
void call_unsetenv(void);

/* builtins.c */
int (*find_builtin(char *cmd))(char **args, char **start)
int hshell_exit(char **args, char **start);
int hshell_cd(char **args, char __attribute__((__unused__)) **start);
int hshell_help(char **args, char __attribute__((__unused__)) **start);

/* env_buils.c */
int hshell_env(char **av, char __attribute__((__unused__)) **start);
int hshell_setenv(char **av, char __attribute__((__unused__)) **start);
int hshell_unsetenv(char **av, char __attribute__((__unused__)) **start);

/* error_code.c */
char *env_err(char **av);
char ali_err(char **av);
char *exit_err(char **av);
char *cd_err(char **av);
char *syn_err(char **av);
char *perm_err(char **av);
char *cmd_err(char **av);

/* henviron.c */
char **env_copy(void);
void free_env(void);
char **get_env(const char *v);

/* herrors.c */
int n_length(int x);
char *_itoa(int x);
int throw_error(char **av, int err);
void *re_alloc(void *str, unsigned int old, unsigned int news);
void asi_lineptr(char **lineptr, size_t *n, char *buf, size_t b);
ssize_t get_line(char **lineptr, size_t *n, FILE *str);
void str_free(char **argv, char **frs_argv);
char *pid_value(void);
char *environ_value(char *beg, int n);
void replac_variable(char **argv, int *i);
#endif
