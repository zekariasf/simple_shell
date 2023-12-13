#include "main.h"
/**
 * exit_shell - used to close a shell
 */
void exit_shell(void)
{
	pid_t pid;

	pid = getpid();
	kill(pid, SIGINT);
}
