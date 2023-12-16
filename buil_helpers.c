#include "main.h"
/**
 * call_hall - display all builtin commands
 */
void call_hall(void)
{
	char *info = "Hshell\n These are hshell builtin commands.\n";

	write(STDOUT_FILENO, info, str_len(info));
	info = "Type 'help' to see this list.\n Type 'cmd name' to find ";
	write(STDOUT_FILENO, info, str_len(info));
	info = "out more about the function 'name'. \n\n alias \t";
	write(STDOUT_FILENO, info, str_len(info));
	info = "alias [NAME[='VALUE'] ...]\n  cd  \tcd";
	write(STDOUT_FILENO, info, str_len(info));
	info = "[DIRECTORY]\n exit \texit [STATUS]\n env \tenv";
	write(STDOUT_FILENO, info, str_len(info));
	info = "\n setenv \tsetenv [VARIABLE] [VALUE]\n unsetenv \t";
	write(STDOUT_FILENO, info, str_len(info));
	info = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, info, str_len(info));
}

/**
 * call_alias - information about the hshell alias
 */
void call_alias(void)
{
	char *info = "alias: alais [NAME[='VALUE'] ...]\n\t Handles aliases.\n";

	write(STDOUT_FILENO, info, str_len(info));
	info = "\n\talias : Prints a list of all aliases, one per line, in";
	write(STDOUT_FILENO, info, str_len(info));
	info = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, info, str_len(info));
	info = "the alias name, name2, etc. one per line, in the format";
	write(STDOUT_FILENO, info, str_len(info));
	info = "NAME='VALUE'.\n/talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, info, str_len(info));
	info = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, info, str_len(info));
	info = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, info, str_len(info));
}
/**
 * call_cd - dispalys info about hshell cd
 */
void call_cd(void)
{
	char *info = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, info, str_len(info));
	info = " process to DIRECTORY.\n\n\tIF no argument is given, the ";
	write(STDOUT_FILENO, info, str_len(info));
	info = "command is interpreted as cd $HOME. if the argument '-' is";
	write(STDOUT_FILENO, info, str_len(info));
	info = " given, the command is interpreted as cd $OLDPWD. \n\n";
	write(STDOUT_FILENO, info, str_len(info));
	info = "\tThe environmet variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, info, str_len(info));
	info = "after a change of directory.\n";
	write(STDOUT_FILENO, info, str_len(info));
}
/**
 * call_exit - displays information on hshell builtin command 'exit'
 */
void call_exit(void)
{
	char *info = "exit: exit [STATUS]\n\t Exits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, info, str_len(info));
	info = "STATUS argument is the the integer used to exit the shell.";
	write(STDOUT_FILENO, info, str_len(info));
	info = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, info, str_len(info));
	info = " exit 0.\n";
	write(STDOUT_FILENO, info, str_len(info));
}
/**
 * call_help - Displays information on the hshell builtin command help
 */
void call_help(void)
{
	char *info = "help: help\n\t See all possible Hshell builitin commands.\n";

	write(STDOUT_FILENO, info, str_len(info));
	info = "\n help [BUILTIN NAME]\N\T See specific information on each ";
	write(STDOUT_FILENO, info, str_len(info));
	info = "builtin commands.\n";
	write(STDOUT_FILENO, info, str_len(info));
}
