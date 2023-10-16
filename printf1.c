#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
va_list args;
int count;

va_start(args, format);
count = vprintf(format, args);
va_end(args);
return (count);
}
