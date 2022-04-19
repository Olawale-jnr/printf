#ifndef MAIN_MY_H
#define MAIN_MY_H

/*
 * File: main.h
 * Desc: Header file containing prototypes for all functions
 *       used for my printf project .
 */

#include <stdarg.h>

int _putchar(char c);
int _printf_char(va_list arg);
int _printf_str(va_list arg);
int _printf_mine(const char *format, ...);
int _printf_int(va_list arg);
int _printf_unsigned(va_list arg);
int _printf(const char *format, ...);
int print_percent(void);
void print_binary(unsigned int n, unsigned int* printed);
int _printf_unsignedToBinary(va_list arg);
int _printf_oct(va_list arg);
int _printf_unsignedIntToHex(unsigned int num, char _case);
int print_hex_base(va_list arg, char _case);
int _printf_hex(va_list arg);
int _printf_HEX(va_list arg);
int _printf_STR (va_list arg);
/**
 * struct print_type - structure definition for print type
 * @fmt: format to print
 * @_print_type: function to print format type
 */

typedef struct print_type
{
    char *fmt;
    int (*_print_type)(va_list);
} print_type;

#endif
