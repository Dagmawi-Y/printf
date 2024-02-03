#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_char - Prints a character.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int print_char(va_list args)
{
    return _putchar(va_arg(args, int));
}
