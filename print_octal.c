#include "main.h"

/**
 * print_octal - Prints an octal number.
 * @val: Argument containing the octal number to print.
 * Return: Number of characters printed.
 */
int print_octal(va_list val)
{
	unsigned int num = va_arg(val, unsigned int);
	int charCount = 0;

	if (num == 0)
	{
		_putchar('0');
		return 1;
	}

	unsigned int temp = num;
	unsigned int power = 1;

	while (temp > 0)
	{
		temp /= 8;
		power *= 8;
	}

	while (power > 1)
	{
		power /= 8;
		_putchar((num / power) + '0');
		num %= power;
		charCount++;
	}

	return (charCount);
}
