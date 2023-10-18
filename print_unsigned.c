#include "main.h"

/**
 * print_unsigned - prints an unsigned integer
 * @val: argument to print
 * Return: number of characters printed
 */
int print_unsigned(va_list val)
{
	unsigned int number = va_arg(val, unsigned int);
	unsigned int temp = number;
	int count = 0;
	int divisor = 1;

	while (temp / 10 > 0)
	{
		temp /= 10;
		divisor *= 10;
	}

	while (divisor > 0)
	{
		int digit = number / divisor;
		_putchar(digit + '0');
		number %= divisor;
		divisor /= 10;
		count++;
	}

	return (count);
}
