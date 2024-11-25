#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "printf_header.h"

/**
 * _printf - Produces output according to a format and send it to 
 * the console.
 * @format: A character string that contains 0 or more directives such as
 * (%c, %s, %d, %i, %%).
 * Return: The quantity of characters printed except the null terminator.
 */
int _printf(const char * const format, ...)
{
	int printed_chars = 0;
	int format_index = 0;

	/* Declare the va_list of arguments and initialize it with va_start */
	va_list args;
	va_start(args, format);


	/* While loop to iterate the format string and it continues until the */
	/* null terminator is found*/
	while (format != NULL && format[format_index] != '\0')
	{
		format_index++;
	}

	va_end(args);
	return (printed_chars);
}
