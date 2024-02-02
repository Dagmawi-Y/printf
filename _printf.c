#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;
    char c;
    char *str;
    void *addr;

    va_start(args, format);

    if (format == NULL)
        return (-1);

    for (ptr = format; *ptr != '\0'; ++ptr)
    {
        if (*ptr == '%' && (*(ptr + 1) == 'c' || *(ptr + 1) == 's' || *(ptr + 1) == '%' || *(ptr + 1) == 'p' || *(ptr + 1) == 'd' || *(ptr + 1) == 'i' || *(ptr + 1) == 'u' || *(ptr + 1) == 'b' || *(ptr + 1) == 'x' || *(ptr + 1) == 'X' || *(ptr + 1) == 'S' || *(ptr + 1) == 'o'))
        {
            int plusFlag = 0;
            int spaceFlag = 0;
            int hashFlag = 0;

            while (*(++ptr) == '+' || *(ptr) == ' ' || *(ptr) == '#')
            {
                if (*ptr == '+')
                    plusFlag = 1;
                else if (*ptr == ' ')
                    spaceFlag = 1;
                else if (*ptr == '#')
                    hashFlag = 1;
            }
            --ptr;

            switch (*(ptr + 1))
            {
                case 'c':
                    c = va_arg(args, int);
                    count += write(1, &c, 1);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    count += write(1, str, strlen(str));
                    break;
                case '%':
                    count += write(1, "%", 1);
                    break;
                case 'p':
                    addr = va_arg(args, void *);
                    {
                        /* Assuming a reasonable buffer size */
                        char buffer[20];
                        sprintf(buffer, "%p", addr);
                        count += write(1, buffer, strlen(buffer));
                    }
                    break;
                case 'd':
                case 'i':
                {
                    /* Assuming a reasonable buffer size */
                    char buffer[20];
                    int num = va_arg(args, int);
                    if (plusFlag && num >= 0)
                        count += write(1, "+", 1);
                    else if (spaceFlag && num >= 0)
                        count += write(1, " ", 1);

                    sprintf(buffer, "%d", num);
                    count += write(1, buffer, strlen(buffer));
                }
                    break;
                case 'u':
                {
                    /* Assuming a reasonable buffer size */
                    char buffer[20];
                    unsigned int num = va_arg(args, unsigned int);
                    if (plusFlag)
                        count += write(1, "+", 1);
                    else if (spaceFlag)
                        count += write(1, " ", 1);

                    sprintf(buffer, "%u", num);
                    count += write(1, buffer, strlen(buffer));
                }
                    break;
                case 'b':
                {
                    /* Assuming a reasonable buffer size */
                    char buffer[33];
                    unsigned int num = va_arg(args, unsigned int);
                    itoa_binary(num, buffer);
                    count += write(1, buffer, strlen(buffer));
                }
                    break;
                case 'x':
                case 'X':
                {
                    /* Assuming a reasonable buffer size */

                    unsigned int num = va_arg(args, unsigned int);
                    if (hashFlag && num != 0)
                        count += write(1, (*(ptr + 1) == 'X') ? "0X" : "0x", 2);

                    count += print_hex(num, (*(ptr + 1) == 'X') ? 1 : 0);
                }
                    break;
                case 'S':
                    str = va_arg(args, char *);
                    count += print_custom_string(str);
                    break;
                case 'o':
                {
                    /* Assuming a reasonable buffer size */
                    char buffer[20];
                    unsigned int num = va_arg(args, unsigned int);
                    if (hashFlag && num != 0)
                        count += write(1, "0", 1);

                    sprintf(buffer, "%o", num);
                    count += write(1, buffer, strlen(buffer));
                }
                    break;
                default:
                    fprintf(stderr, "Error: Unknown conversion specifier '%c'\n", *(ptr + 1));
                    return (-1);
            }
        }
        else
        {
            count += write(1, ptr, 1);
        }
    }

    va_end(args);

    return (count);
}
