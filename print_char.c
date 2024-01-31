#include "main.h"
#include <unistd.h>

/**
 * print_char - Print a character
 * @args: Variable arguments list
 *
 * Return: Number of characters printed for the conversion specifier
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);

    write(1, &c, 1);

    return (1);
}
