#include "main.h"
#include <stdio.h>

/**
 * _strspn - gets the initial lenght of a prefix substring
 * @s: string to scan
 * @accept: accepted characters
 *
 * Return: number of matching bytes
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;
	unsigned int j;
	unsigned int count;
	int found;

	i = 0;
	count = 0;

	while (s[i] != '\0')
	{
		found = 0;
		j = 0;
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}

			j++;
		}

		if (found == 0)
		{
			return (count);
		}

		count++;
		i++;
	}

	return (count);
}
