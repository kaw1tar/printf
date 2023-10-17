#include "main.h"
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
	va_list args;

	va_start(args, format);

	int chars_written = 0;

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int value = va_arg(args, int);
			char buffer[12];
			int n = snprintf(buffer, sizeof(buffer), " %d", value);

			write(1, buffer, n);
			chars_written += n;
			format += 2;
		}
		else
		{
			write(1, format++, 1);
			chars_written++;
		}

	}

	va_end(args);



