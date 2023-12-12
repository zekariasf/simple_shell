#include "main.h"
/**
 * execut - creat a new process and excute a given excutable file
 * @argv: the path name of the excutable file
 * @envi: enviromental variadles that we went to include in our chiled process
 */
void execut(char **argv, char **envi)
{
	pid_t new_process;
	char *ar;

	ar = full_path(argv[0]);
	argv[0] = ar;
	if (argv[0] == NULL)
	{
		perror(NULL);
		return;
	}
	new_process = fork();

	if (new_process == 0)
	{
		if (execve(argv[0], argv, envi) == -1)
			perror("./hsh");
	}
	if (new_process > 0)
		wait(NULL);
	if (new_process == -1)
		perror("./hsh");
}
