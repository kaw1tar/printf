#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * custom_printf - A custom printf function to print integers
 * @format: The format string
 * @...: The integer values to print
 */

void custom_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int value = va_arg(args, int);
			char buffer[12];
			int n = snprintf(buffer, sizeof(buffer), " %d", value);

			write(1, buffer, n);
			format += 2;
		}
	else
	{
		write(1, format++, 1);
	}

	}

	va_end(args);



