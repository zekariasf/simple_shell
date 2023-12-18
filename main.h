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
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;


/**
 * struct alias_s - defining aliases.
 * @name: alias name
 * @value: alias value
 * @next: pointer
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/**
 * struct list_s - linkeed list
 * @die: directory path
 * @next: pointer
 */
typedef struct list_s
{
	char *die;
	struct list_s *next;
} list_t;


int hist;
char *name;
alias_t *aliases;

/* global environ*/
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

void line_handler(char **argv, ssize_t len);
ssize_t new_line(char *len);
void opretors_log(char *len, ssize_t *len_new);

char *argv_get(char *len, int *ret);
int argv_run(char **argv, char **big, int *ret);
int argv_handle(int *ret);
int argv_call(char **argv, char **big, int *ret);
int argv_check(char **argv);

alias_t *alias_add(alias_t **top, char *input, char *value);
void alias_free(alias_t *input);
list_t *node_add(list_t **input, char *dir);
void list_free(list_t *input);


char *path_finde(char *command);
list_t *path_get(char *command);
char *locatin_find(char *command);


void handle_signal(int sig);
int execut_e(char **argv, char **beg);
int main(int argc, char *argv[]);


int open_fel(char *path_file);
int file_command(char *path_file, int *exe);


#endif
