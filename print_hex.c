#include "main.h"

/**
 * print_hex - Prints a hexadecimal number.
 * @val: Arguments containing the number to print in hexadecimal.
 * Return: The number of characters printed.
 */
int print_hex(va_list val)
{
	unsigned int num = va_arg(val, unsigned int);
	int counter = 0;
	unsigned int temp = num;
	unsigned int *array = NULL;

	while (temp / 16 != 0)
	{
		temp /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(unsigned int));

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
