#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_percent - Prints a percent sign.
 * @args: Argument list.
 *
 * Return: Number of characters printed.
 */
int print_percent(va_list args)
{
    (void)args;  /* Unused parameter */
    return _putchar('%');
}
