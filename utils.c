#include "main.h"

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

/**
 * print_hex - Print a number in hexadecimal format
 * @num: Number to print in hexadecimal
 *
 * Return: Number of characters printed
 */
int print_hex(int num)
{
    char hex[] = "0123456789abcdef";
    int count = 0;

    write(1, &hex[num / 16], 1);
    write(1, &hex[num % 16], 1);

    count += 2;

    return (count);
}

/**
 * print_hex_address - Print an address in hexadecimal format
 * @address: Address to print in hexadecimal
 *
 * Return: Number of characters printed
 */
int print_hex_address(unsigned long address)
{
    char hex[] = "0123456789abcdef";
    int count = 0;
    char buffer[16];  // Buffer to store the reversed address

    if (address == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    // Convert address to hexadecimal and store it in the buffer
    int i = 0;
    while (address != 0)
    {
        buffer[i] = hex[address % 16];
        address /= 16;
        i++;
    }

    // Print the reversed buffer
    while (i > 0)
    {
        i--;
        write(1, &buffer[i], 1);
        count++;
    }

    return (count);
}
