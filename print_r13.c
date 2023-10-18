#include "main.h"

/**
 * print_r13 - Encodes a string using ROT13 substitution.
 * @args: A va_list containing the string to be encoded.
 * Return: The number of characters printed.
 */
int print_r13(va_list args)
{
	char *input = va_arg(args, char*);
	int counter = 0;

	if (input == NULL)
	{
		input = "(null)";
	}

	while (*input)
	{
		int found = 0;
		char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		char beta[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

		for (int i = 0; alpha[i] && !found; i++)
		{
			if (*input == alpha[i])
			{
				_putchar(beta[i]);
				counter++;
				found = 1;
			}
		}

		if (!found)
		{
			_putchar(*input);
			counter++;
		}

		input++;
	}

	return (counter);
}
