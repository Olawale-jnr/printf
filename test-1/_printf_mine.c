#include "main_my.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * get_print_type_func - select appropriate printer for
 * a specfic format
 * @fmt: format type
 * @arg: argument
 * Return: on success , numbers of char printed
 * else zero
 */
int get_print_type_func(char fmt, va_list arg)
{
int i = 0;
print_type funcs[] = {
{"c", _printf_char},
{"s", _printf_str},
{"d", _printf_int},
{"i", _printf_int},
{"b", _printf_unsignedToBinary},
{"u", _printf_unsigned},
{"o", _printf_oct},
{"x", _printf_hex},
{"X", _printf_HEX},
{"S", _printf_STR},
{NULL, NULL}
};

while (*funcs[i].fmt != fmt)
{
if (funcs[i].fmt == NULL)
{
return (0);
}
i++;
}
return (funcs[i]._print_type(arg));
}

/**
 * _printf - printf
 * Description: just like standard printf
 * @format: characters
 * Return: the number of characters printed
 */

int _printf_mine(const char *format, ...)
{
va_list arg;
int numOfCharPrinted = 0, numOfCharPrintedByExtP = 0;
va_start(arg, format);

if (format == NULL)
return (-1);
while (*format)
{
if (*format != '%')
{
_putchar(*format);
format++, numOfCharPrinted++;
continue;
}
if (*(format + 1) == '%')
{
_putchar('%');
format += 2, numOfCharPrinted++;
continue;
}
if (*(format + 1) == '\0')
	return (-1);
numOfCharPrintedByExtP = get_print_type_func(*(format + 1), arg);
if (numOfCharPrintedByExtP == -1 || numOfCharPrintedByExtP != 0)
{
format++;
}
if (numOfCharPrintedByExtP > 0)
numOfCharPrinted += numOfCharPrintedByExtP;
else if (numOfCharPrintedByExtP == 0)
{
_putchar('%');
numOfCharPrinted++;
}
format++;
}
va_end(arg);
return (numOfCharPrinted);
}
