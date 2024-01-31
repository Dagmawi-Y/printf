#include "main.h"
#include <unistd.h>

/**
 * print_rot13 - Print a string encoded in ROT13
 * @args: Variable arguments list
 *
 * Return: Number of characters printed for the conversion specifier
 */
int print_rot13(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    if (str == NULL)
    {
        write(1, "(null)", 6);
        return (6);
    }

    count += print_rot13_str(str);

    return (count);
}

/**
 * print_rot13_str - Print a string encoded in ROT13
 * @str: String to print encoded in ROT13
 *
 * Return: Number of characters printed
 */
int print_rot13_str(char *str)
{
    int count = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            char base = (str[i] >= 'a' && str[i] <= 'z') ? 'a' : 'A';
            char rotated_char = ((str[i] - base + 13) % 26) + base;

            write(1, &rotated_char, 1);
            count++;
        }
        else
        {
            write(1, &str[i], 1);
            count++;
        }
    }

    return (count);
}
