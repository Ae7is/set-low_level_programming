#include "main.h"

/**
 * cap_string - capitaalizes the first letter of every word
 * @s: string to be modified
 *
 * Return: pointer to s
 */
char *cap_string(char *s)
{
	int i;
	int j;
	char sep[] =  " \t\n,;.!?\"(){}";

	if (s[0] >= 'a' && s[0] <= 'z')
	{
		s[0] = s[0] - 32;
	}

	i = 1;

	while (s[i] != '\0')
	{
		j = 0;

		while (sep[j] != '\0')
		{
			if (s[i - 1] == sep[j] &&
				s[i] >= 'a' &&
				s[i] <= 'z')
			{
			s[i] = s[i] - 32;
			}

			j++;
		}

		i++;
	}

	return (s);
}

