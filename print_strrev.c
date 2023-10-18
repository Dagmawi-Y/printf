#include "main.h"

/**
 * print_strrev - Reverses and prints a string.
 * @args: A va_list containing the string to be reversed and printed.
 * Return: The number of characters printed.
 */
int print_strrev(va_list args)
{
	char *original_str = va_arg(args, char*);
	int str_length = 0;
	int i;

	if (original_str == NULL)
	{
		original_str = "(null)";
	}

	while (original_str[str_length] != '\0')
	{
		str_length++;
	}

	for (i = str_length - 1; i >= 0; i++)
	{
		_putchar(original_str[i]);
	}

	return (str_length);
}
