#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - A custom printf function to print integers
 * @format: The format string
 * @...: The integer values to print
 *
 * Return: The number of characters written.
 */
int _printf(const char *format, ...)
{
	int chars_written = 0;
	char buffer[12];

	va_list args;

	va_start(args, format);


	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int value = va_arg(args, int);
			int n = snprintf(buffer, sizeof(buffer), " %d", value);

			chars_written += n;
			write(1, buffer, n);
			format += 2;
		}
		else
		{
			write(1, format, 1);
			chars_written++;
			format++;
		}
	}

	va_end(args);
	return (chars_written);
}

