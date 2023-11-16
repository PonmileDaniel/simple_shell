#include "shell.h"
/**
 * shell_cd - changes the current working directory of the shell
 * @args: array of arguments
 * Return: void
 */
void shell_cd(char **args)
{
	char *directory = args[1];
	int ret;

	/* If no argument is provided, change to HOME directory */
	if (directory == NULL)
	{
		directory = _getenv("HOME");
		if (directory == NULL)
		{
			_puts("cd: No HOME directory found\n");
			return;
		}
	}

	ret = chdir(directory);
	if (ret == -1)
	{
		perror("cd");
		return;
	}
}

