#include "main.h"
#include <unistd.h>

/**
 * print_reversed - Print a reversed string
 * @args: Variable arguments list
 *
 * Return: Number of characters printed for the conversion specifier
 */
int print_reversed(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }

    count += print_reversed_str(str);

    return (count);
}

/**
 * print_reversed_str - Print a reversed string
 * @str: String to print in reverse
 *
 * Return: Number of characters printed
 */
int print_reversed_str(char *str)
{
    int count = 0;
    int length = 0;

    while (str[length] != '\0')
        length++;

    while (length > 0)
    {
        length--;
        write(1, &str[length], 1);
        count++;
    }

    return (count);
}
