#include "main.h"

/**
 * print_hex_a - Prints a hexadecimal number.
 * @num: The number to print in hexadecimal.
 * Return: The number of characters printed.
 */
int print_hex_a(unsigned long int num)
{
	int counter = 0;
	unsigned long int temp = num;
	unsigned long int *array = NULL;

	while (temp / 16 != 0)
	{
		temp /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(unsigned long int));

	if (array == NULL)
	{
		free(array);
		return (-1);
	}

	temp = num;
	for (int i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (int i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			_putchar(array[i] + 'a' - 10);
		else
			_putchar(array[i] + '0');
	}

	free(array);
	return (counter);
}
