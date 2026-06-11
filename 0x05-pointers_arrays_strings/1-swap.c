#include "main.h"

/*
 * swap_int - Swaps the numbers of a to b and b to a
 * @a: updates to the value of b
 * @b: updates to the value of a
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
