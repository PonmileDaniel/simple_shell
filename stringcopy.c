#include "shell.h"
/**
 * _strcpy -copy string
 * @dest: string argument
 * @src: string argument for src
 * @n: integer argument
 * Return: dest
 */
char *_trcpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n -1 && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
