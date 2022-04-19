#include "main_my.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _printf_char - prints a character
 * @arg: character to be printed
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printf_char(va_list arg)
{
return (_putchar(va_arg(arg, int)));
}


/**
 * _printf_str - prints a string
 * @arg: string to be printed
 * Return: On success returns number of char printed.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _printf_str(va_list arg)
{
int i = 0;
char *str = va_arg(arg, char*);
if (str == NULL)
{
str = "(null)";
}
else if (*str == '\0')
{
return (-1);
}

while (*str)
{
_putchar(*str);
str++;
i++;
}

return (i);
}


/**
 * _printf_int - prints an integer.
 * @arg: argument
 * Return: 0
 */

int _printf_int(va_list arg)
{

unsigned int div = 1, i, resp, numOfcharP = 0;
int n = va_arg(arg, int);

if (n < 0)
{
	_putchar('-');
	numOfcharP++;
	n *= -1;
}

for (i = 0; n / div > 9; i++, div *= 10)
;

for (; div >= 1; n %= div, div /= 10, numOfcharP++)
{
	resp = n / div;
	_putchar('0' + resp);
}
return (numOfcharP);
}



/**
 * _printf_STR - prints a string with a `S` (upper case) specificer
 * @arg: argument
 * Return: number of character printed
 */

int _printf_STR(va_list arg)
{
int i;
char *str = va_arg(arg, char*);

if (str == NULL)
	str = "(null)";
else if (*str == '\0')
	return (-1);

for (i = 0; str[i]; i++)
{
	if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
	{
		_putchar('\\');
		_putchar('x');
		if (i < 16)
			_putchar('0');

		_printf_unsignedIntToHex(str[i], 'A');
	}
	else
		_putchar(str[i]);
}

return (i);
}


/**
 * _printf_unsigned - prints an unsigned int.
 * @arg: argument
 * Return: 0
 */

int _printf_unsigned(va_list arg)
{
int div = 1, i, resp;
unsigned int n = va_arg(arg, unsigned int);

for (i = 0; n / div > 9; i++, div *= 10)
;

for (; div >= 1; n %= div, div /= 10)
{
	resp = n / div;
	_putchar('0' + resp);
}
return (i + 1);
}


