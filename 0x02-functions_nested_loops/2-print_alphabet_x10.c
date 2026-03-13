#include "main.h"
/**
 * print_alphabet_x10 - prints the alphabets ten times after each new line
 *
 * Return: Always 0
 */
void print_alphabet_x10(void)
{
	int i;

	char c;

	i = 0;

	while (i < 10)
	{
		c = 'a';
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}

		_putchar('\n');
		i++;
	}

}
