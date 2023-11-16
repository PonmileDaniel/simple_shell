#include "shell.h"
/**
 * _strddup - used to duplicate a string
 * @str: string
 * Return: duplicate if successful
 */

char *_strddup(const char *str)
{
	size_t len;
	char *duplicate;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str) + 1;
	duplicate = (char *)malloc(len);

	if (duplicate == NULL)
	{
		return (NULL);
	}

	strcpy(duplicate, str);

	return (duplicate);
}

