#include "main.h"

/**
 * print_integer - Prints an integer.
 * @val: Argument containing the integer to print.
 * Return: Number of characters printed.
 */
int print_integer(va_list val)
{
	int n = va_arg(val, int);
	int num, last = n % 10, digit, exp = 1;
	int char_count = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		char_count++;
	}

	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			char_count++;
		}
	}

	_putchar(last + '0');
	return (char_count);
}

/**
 * print_decimal - Prints a decimal.
 * @val: Argument containing the decimal to print.
 * Return: Number of characters printed.
 */
int print_decimal(va_list val)
{
	int n = va_arg(val, int);
	int num, last = n % 10, digit, exp = 1;
	int char_count = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		char_count++;
	}

	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			char_count++;
		}
	}

	_putchar(last + '0');
	return (char_count);
}
