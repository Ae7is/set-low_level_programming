#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: memory are to fill
 * @b: byte used for filling
 * @n: number of bytes to fill
 *
 * Return: pointer to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}

	return (s);
}
