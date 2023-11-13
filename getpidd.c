#include "shell.h"
/**
 */
void getpiddd(char **rvg, char *cmd)
{
	pid_t child;
	int stat;
	(void)cmd;

	child = fork();

	if (child == -1)
	{
		perror("Process Error");
		exit(1);
	}
	if (child == 0)
	{
		if(execve(rvg[0], rvg, NULL) == -1)
		{
			perror("Error");
		}
		exit(1);
	}
	else
	{
		wait(&stat);
	}
}
