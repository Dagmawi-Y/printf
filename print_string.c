#include "main.h"
#include <unistd.h>

/**
 * print_string - Print a string
 * @args: Variable arguments list
 *
 * Return: Number of characters printed for the conversion specifier
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);

    if (str == NULL)
        str = "(null)";

    write(1, str, _strlen(str));

    return (_strlen(str));
}

/**
 * _strlen - Calculate the length of a string
 * @str: Input string
 *
 * Return: Length of the string
 */
int _strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;

    return (len);
}
