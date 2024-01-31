#include "main.h"
#include <stdio.h>

/**
 * print_int - Print an integer
 * @args: Variable arguments list
 *
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;

    // Assuming you have a function to print individual characters
    // For example, you can use the add_to_buffer function if it's suitable

    // Handle the case of a negative number
    if (num < 0)
    {
        // Print the negative sign and update the count
        // (assuming add_to_buffer is a suitable function)
        add_to_buffer(&buf, '-');
        count++;
        // Convert the negative number to positive for further processing
        num = -num;
    }

    // Print the digits of the number
    count += print_digits(num);

    return count;
}

/**
 * print_digits - Print the digits of a number
 * @num: Number to print
 *
 * Return: Number of digits printed
 */
int print_digits(int num)
{
    int count = 0;
    buffer_t buf;

    // Recursive function to print digits
    if (num / 10 != 0)
        count += print_digits(num / 10);

    // Print the last digit
    add_to_buffer(&buf, num % 10 + '0');
    count++;

    return count;
}
