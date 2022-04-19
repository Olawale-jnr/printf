#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * init_params - clears struct fields and reset buf
 * @func: the parameters struct
 * @list: the argument pointer
 *
 * Return: void
 */
void init_params(param_func *func, va_list list)
{
	func->unsign = 0;
	func->plus_flag = 0;
	func->space_flag = 0;
	func->hash_flag = 0;
	func->zero_flag = 0;
	func->minus_flag = 0;
	func->width = 0;
	func->precision = UINT_MAX;
	func->h_mod = 0;
	func->l_mod = 0;
	(void)list;
}

/**
 * print_range - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_range(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}
