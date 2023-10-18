#include "main.h"

/**
 * print_pointer - prints an hexadcimal number.
 * @val: args.
 * Return: counterr.
 */

int print_pointer(va_list val)
{
	void *ptr = va_arg(val, void*);
	unsigned long int num = (unsigned long int)ptr;
	char hex_chars[] = "0123456789abcdef";
	char buffer[18];
	int charCount = 0;

	if (ptr == NULL)
	{
		char *nil_str = "(nil)";
		while (nil_str[charCount] != '\0')
		{
			_putchar(nil_str[charCount]);
			charCount++;
		}
	}
	else
	{
		_putchar('0');
		_putchar('x');
		int index = 16;
		buffer[index] = '\0';

		while (num > 0)
		{
			index--;
			buffer[index] = hex_chars[num % 16];
			num /= 16;
		}

		while (buffer[index] != '\0')
		{
			_putchar(buffer[index]);
			charCount++;
			index++;
		}
	}

	return (charCount);
}
