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
 * handle_user_input - process user input
 * @buff: a pointer to the buffer
 * @n: pointer to the size of buffer
 * @copy_buff: pointer to the buffer to store the copied input string
 * @token: pointer to the buffer for tokenization
 * @delim: delimiter used for tokeniztion
 */
void handle_user_input(char **buff, size_t *n, char **copy_buff, char **token, const char *delim)
{
	ssize_t count;

	count = getline(buff, n, stdin);

	if (count == -1)
	{
		free(*buff);
		exit(EXIT_SUCCESS);
	}

	if ((*buff)[count - 1] == '\n')
		(*buff)[count - 1] = '\0';

	*copy_buff = malloc(sizeof(char) * (count + 1));

	if (*copy_buff == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(*copy_buff, *buff);
	*token = strtok(*buff, delim);
}
/**
 * main - display prompt
 * /@argv: argument
 * @env: the environment variable
 * argc: this like a boolean
 * Return: 1 if success
 */
int main(int argc, char **argv, char **env)
{
	size_t n = 0;
        char *buff = NULL;
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
		
		handle_user_input(&buff, &n, &copy_buff, &token, delim);
		handle_exit(copy_buff);

		if (strcmp(copy_buff, "env") == 0)
		{
			_env(env);
			continue;
		}

		while(token != NULL)
		{
			n_token++;
			token = strtok(NULL, delim);
		}
		n_token++;
		argv = malloc(sizeof(char *) * n_token);

		if (argv == NULL)
		{
			perror("_strdup");
			return (EXIT_FAILURE);
		}

		token = strtok(copy_buff, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = strdup(token);
			if (argv[i] == NULL)
			{
				perror("_strdup");
				return (EXIT_FAILURE);
			}
			token = strtok(NULL, delim);
		}

		for (; i < n_token; i++)
		{
			argv[i] = NULL;
		}
		argv[i] = NULL;

		if (handle_path(argv, argv[0]) != NULL || argv[0][0] == '/')
		{
			getpiddd(argv, copy_buff);
		}
		else if (argv[0][0] != '/')
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
