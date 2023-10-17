#include "main.h"

/**
 * print_char - Prints a character.
 * @val: Arguments containing the character to print.
 * Return: 1.
 */
int print_charac(va_list val)
{
	char character = va_arg(val, int);
	_putchar(character);
	return (1);
}
