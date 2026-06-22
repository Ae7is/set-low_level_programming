#include "main.h"

/**
 * sqrt_helper - returns the square root of a number
 * @n: number
 * @guess : current guess;
 *
 * Return: square root of -1
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);

	if (guess * guess > n)
		return (-1);

	return (sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - returns natural square root
 * @n: number
 *
 * Return: square root or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_helper(n, 1));
}
