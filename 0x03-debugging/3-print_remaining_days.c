#include "main.h"
#include <stdio.h>

/**
 * print_remaining_days - takes a date and prints how many days are left in the year, taking leap years into account
 * @month: month in number format
 * @day: day of the month
 * @year: year
 * Return: void
 */

void print_remaining_days(int month, int day, int year)
{
	int is_leap = 0;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		is_leap = 1;
	}

	if (!is_leap && month == 2 && day == 60)
	{
		printf("invalid date: %02d/%02d/%04d\n", month, day - 31, year);
		return;
	}

	if (is_leap && month > 2)
	{
		day++;
	}

	printf("Day of the year: %d\n", day);

	if (is_leap)
		printf("Remaining days: %d\n", 366 - day);
	else
		printf("Remaining days: %d\n", 365 - day);
}
