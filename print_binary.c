#include "main.h"

/**
 * print_binary - Prints a binary number.
 * @val: Arguments containing the number to print in binary.
 * Return: The number of characters printed.
 */
int print_binary(va_list val)
{
	unsigned int num = va_arg(val, unsigned int);
	int cont = 0;
	int leading_zeros = 1;

	for (int i = 31; i >= 0; i--)
	{
		unsigned int bit = (num >> i) & 1;

		if (bit == 1)
			leading_zeros = 0;

		if (!leading_zeros)
		{
			_putchar(bit + '0');
			cont++;
		}
	}

	if (cont == 0)
	{
		_putchar('0');
		cont = 1;
	}

	return (cont);
}
