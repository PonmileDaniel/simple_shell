#include "shell.h"
/**
 * _strlen - length of string
 * @str: string
 * Return: length
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
