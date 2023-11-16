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
 * h - process user input
 * @buff: a pointer to the buffer
 * @n: pointer to the size of buffer
 * @copy_bu: pointer to the buffer to store the copied input string
 * @token: pointer to the buffer for tokenization
 * @delim: delimiter used for tokeniztion
 */
void h(char **buff, size_t *n, char **copy_bu, char **token, const char *delim)
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

	*copy_bu = malloc(sizeof(char) * (count + 1));

	if (*copy_bu == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	_strcpy(*copy_bu, *buff);
	*token = strtok(*buff, delim);
}
/**
 * tokenize_input - tokenize input
 * @copy_bu: copy buffer
 * @argv: argument
 * Return: new token
 */
int tokenize_input(char *copy_bu, char ***argv)
{
	char *token;
	const char *delim = " \n";
	int n_token = 0;
	int i;

	token = strtok(copy_bu, " \n");
	while (token != NULL)
	{
		n_token++;
		token = strtok(NULL, delim);
	}
	n_token++;

	*argv = malloc(sizeof(char *) * n_token);
	if (*argv == NULL)
	{
		perror("_strdup");
		exit(EXIT_FAILURE);
	}
	token = strtok(copy_bu, " \n");
	for (i = 0; token != NULL; i++)
	{
		(*argv)[i] = _strdup(token);
		if ((*argv)[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
	}
	(*argv)[i] = NULL;

	return (n_token);
}

/**
 * execute_command - this exec commands
 * @argv: argument
 * @copy_bu: copy buffer
 * @env: environment
 */
void execute_command(char **argv, char *copy_bu, char **env)
{
	int n_token;
	int i;
	(void) **env;

	argv = NULL;

	n_token = tokenize_input(copy_bu, &argv);
	if (handle_path(argv, argv[0]) != NULL || argv[0][0] == '/')
	{
		getpiddd(argv, copy_bu);
	}
	else if (argv[0][0] != '/')
	{
		const char program_name[] = "./hsh: ";
		const char error_message[] = "No such file or directory \n";

		write(STDERR_FILENO, program_name, strlen(program_name));
		write(STDERR_FILENO, error_message, strlen(error_message));
	}
	for (i = 0; i < n_token; i++)
	{
		free(argv[i]);
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
	char *copy_bu;
	char *token;
	const char *delim = " \n";
	(void)argc;
	(void)env;


	signal(SIGINT, sign_handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			const char prompt[] = "$ ";

			write(STDOUT_FILENO, prompt, _strlen(prompt));
		}

		h(&buff, &n, &copy_bu, &token, delim);
		handle_exit(copy_bu);

		if (strcmp(copy_bu, "env") == 0)
		{
			_env(env);
			continue;
		}
		execute_command(argv, copy_bu, env);
		free(copy_bu);
	}

	free(buff);
	return (0);
}
