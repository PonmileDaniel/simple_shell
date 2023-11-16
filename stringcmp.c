#include "shell.h"
/**
 * _strcmp - this compare
 * @s1: string 1
 * @s2: string 2
 * Return: return the stuff
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
