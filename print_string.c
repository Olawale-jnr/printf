#include "main.h"

/**
 *print_chars - prints a char
 *@list: list of arguments
 *@func: pointer to the struct flags in which we turn the flags on
 *Return: number of characters printed.
 */
int print_chars(va_list list, param_func *func)
{
	unsigned int i = 1;
	unsigned int count = 0;
	unsigned int str = va_arg(list, int);

	if (func->minus_flag)
		count += _putchar(str);
	while (i++ < func->width)
		count += _putchar(' ');
	if (!func->minus_flag)
		count += _putchar(str);
	return (count);
}

/**
 *print_strings - prints strings
 *@list: list of arguments
 *@func: pointer to the struct flags in which we turn the flags on/off
 *Return: number of characters printed
 */
int print_strings(va_list list, param_func *func)
{
	char *str;
	unsigned int i, count, str_len, j;

	i = 0;
	count = 0;
	str = va_arg(list, char *);
	str_len = _strlen(str);
	j = str_len;
	(void)func;

	switch ((int)(!str))
		case 1:
			str = "(null)";
	if (func->precision < str_len)
		j = str_len = func->precision;
	if (func->minus_flag)
	{
		if (func->precision != UINT_MAX)
			for (i = 0; i < str_len; i++)
				count += _putchar(*str++);
		else
			count += _puts(str);
	}
	while (j++ < func->width)
		count += _putchar(' ');
	if (!func->minus_flag)
	{
		if (func->precision != UINT_MAX)
			for (i = 0; i < str_len; i++)
				count += _putchar(*str++);
		else
			count += _puts(str);

	}
	return (count);

}
