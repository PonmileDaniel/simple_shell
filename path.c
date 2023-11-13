#include "shell.h"

/**
 * path_handle - handle the path func
 * @rgv: rgv argument
 * @cmd: command set
 * Returb: command for
 */

char *get_path(const char *command)
{
	char *path_env = getenv("PATH");
	char *path_env_copy;
	char *path;

	if (path_env == NULL)
	{
		write(STDERR_FILENO, "Error: PATH environment variable not set.\n", 42);
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
		char *full_path = malloc(strlen(path) + strlen(command) + 2);

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
			return (full_path);
		}

		free(full_path);
		path = strtok(NULL, ":");
	}
	write(STDERR_FILENO, "Error: Command not found in PATH.\n", 35);
	return (NULL);
}

/**
 *
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

	return rgv[0];
}
