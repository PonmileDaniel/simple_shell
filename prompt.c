#include "shell.h"
/**
 * sign_handler - this interrupt curent process
 * @signum: signal number
 */
void sign_handler(int signum)
{
	int child_running = 0;

	(void)signum;

	if (child_running)
	{
		write(STDOUT_FILENO, "Terminating process \n", 40);
		kill(child_running, SIGTERM);
	}
	else
	{
		write(STDOUT_FILENO, "\n$", 3);
	}
}
/**
 * main - display prompt
 * @argv: argument
 * @env: the environment variable
 * @argc: this like a boolean
 * Return: 1 if success
 */
int main(int argc, char **argv, char **env)
{
	size_t n = 0;
        char *buff = NULL;
	ssize_t count = 0;
	char *copy_buff;
	char *token;
	const char *delim = " \n";
	int n_token = 0;
	int i;
	(void)argc;
	(void)env;

	signal(SIGINT, sign_handler);
	while(1)
	{
		if (isatty(STDIN_FILENO))
		{
			const char prompt[] = "$ ";
			write(STDOUT_FILENO, prompt, _strlen(prompt));
		}
		count = getline(&buff, &n, stdin);

		if (count == -1)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		if (buff[count - 1] == '\n')
			buff[count - 1] = '\0';

		copy_buff = malloc(sizeof(char) * count);

		strcpy(copy_buff, buff);

		token = strtok(buff, delim);

		while(token == NULL)
		{
			n_token++;
			token = strtok(NULL, delim);
		}
		n_token++;
		argv = malloc(sizeof(char *) * n_token);

		token = strtok(copy_buff, delim);

		/*path_handle(rgv, cmd);*/
		/*handle_path(rgv, cmd);*/

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * _strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		if (handle_path(argv, argv[0]) != NULL)
		{
			getpiddd(argv, copy_buff);
		}
		else
		{
			write(STDERR_FILENO, "Error: Command not found or not executable in PATH.\n", 54);
		}
		for (i = 0; i < n_token; i++)
		{
			free(argv[i]);
		}
	}
	free(copy_buff);
	free(buff);
	return (0);
}
