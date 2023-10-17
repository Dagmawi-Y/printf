#include "main.h"

/**
 * print_es - Prints exclusive string.
 * @val: Arguments containing the string to print.
 * Return: The length of the string.
 */
int print_es(va_list val)
{
	char *str;
	int len = 0;

	str = va_arg(val, char *);
	if (str == NULL)
		str = "(null)";

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len += 2;
			int cast = (int)str[i];

			if (cast < 16)
			{
				_putchar('0');
				len++;
			}

			len += printf_HEX_aux(cast);
		}
		else
		{
			_putchar(str[i]);
			len++;
		}
	}

	return (len);
}
