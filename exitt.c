#include "shell.h"
/**
 * handle_exit - this handles te exit command
 * @input: user input
 */
void handle_exit(char *input)
{
	if (_strcmp(input, "exit") == 0)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}
}
