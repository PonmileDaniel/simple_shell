#include "shell.h"

/**
 * get_path - handle the path func
 * @command: rgv argument
 * Return: command for
 */

char *get_path(const char *command)
{
	char *path_env = getenv("PATH");
	char *path_env_copy;
	char *path;

	if (path_env == NULL)
	{
		return (NULL);
	}
	path_env_copy = strdup(path_env);

	if (path_env_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}
	path = strtok(path_env_copy, ":");
	while (path != NULL)
	{
		char *full_path = malloc(strlen(path) + strlen(command) + 2 + 1);

		if (full_path == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		strcpy(full_path, path);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, F_OK | X_OK) == 0)
		{
			free(path_env_copy);
			return (full_path);
		}

		free(full_path);
		path = strtok(NULL, ":");
	}
	free(path_env_copy);
	return (NULL);
}

/**
 * handle_path - resolve the fulll path
 * @rgv: array of strings representing
 * @cmd: original command string
 * Return: dynamically allocated string
 */
char *handle_path(char **rgv, const char *cmd)
{
	char *path = get_path(cmd);

	if (path == NULL)
	{
		return (NULL);
	}
	rgv[0] = strdup(path);
	free(path);

	if (rgv[0] == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	return (rgv[0]);
}
