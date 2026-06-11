#include "main.h"

/**
 * _strlen - returns the lenght of a string
 * @s: string to be measured
 *
 * Return: lenght of the string
 */
int _strlen(char *s)
{
	int len;

	len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}

