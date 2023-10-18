#include "main.h"
/**
 * print_string - print a string.
 * @val: argument.
 * Return: the length of the string.
 */

int print_string(va_list val)
{
	char *s = va_arg(val, char*);
	int len = 0;

	if (s == NULL)
		s = "(null)";

	while (s[len] != '\0')
	{
		_putchar(s[len]);
		len++;
	}

	return (len);
}
