#include "main.h"
/**
 * main - main
 *
 *
 */
int main(int ac __attribute((unused)), char **av __attribute((unused)))
{
	char *prompt = "($)";

	while(1)
		write(1,prompt,24);
	return (0);
}


