#include "main.h"
#include <unistd.h>

/**
 * print_string_custom - Print a string with special characters
 * @args: Variable arguments list
 *
 * Return: Number of characters printed for the conversion specifier
 */
int print_string_custom(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }

    while (*str)
    {
        if ((*str >= 0 && *str < 32) || *str >= 127)
        {
            write(1, "\\x", 2);
            count += 2;
            count += print_hex(*str);
        }
        else
        {
            write(1, str, 1);
            count++;
        }
        str++;
    }

    return (count);
}

/**
 * print_hex - Print a number in hexadecimal format
 * @num: Number to print in hexadecimal
 *
 * Return: Number of characters printed
 */
int print_hex(int num)
{
    char hex[] = "0123456789ABCDEF";
    int count = 0;

    write(1, &hex[num / 16], 1);
    write(1, &hex[num % 16], 1);

    count += 2;

    return (count);
}
