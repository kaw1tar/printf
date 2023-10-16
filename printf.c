#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int cnt = 0;
	va_list listf;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(listf, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}

		format++;
	}

	return (cnt);
}
