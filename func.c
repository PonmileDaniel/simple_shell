#include "shell.h"
/**
 * _strcat - concat two string
 * @dest: the destintion string
 * @src: the source string to be appended
 * Return: pointer to the result string
 */
char *_strcat(char *dest, const char *src)
{
	size_t i;

	i = 0;

	while ((dest[i] = src[i]) != '\0')
	{
		i++;
	}
	return (dest);
}

/**
 * _strdup - duplicate a string
 * @str: the string to be duplicated
 * Return: a pointer to the newly allocated dup
 */
char *_strdup(const char *str)
{
	size_t len;
	char *new_str;
	size_t i;

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	new_str = (char *)malloc(len + 1);

	for (i = 0; i <= len; i++)
	{
		new_str[i] = str[i];
	}
	return (new_str);
}

/**
 * _strcpy - copy string from src to dest
 * @dest: the dest bufer
 * @src: the source str to be copied
 * Return: apointer to the resulting string
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;

	while ((dest[i] = src[i]) != '\0')
	{
		i++;
	}
	return (dest);
}
