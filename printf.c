#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "printf_header.h"

#define BUFFER_SIZE 512

/**
 * _printf - Produces output according to a format and send it to 
 * the console.
 * @format: A character string that contains 0 or more directives such as
 * (%c, %s, %d, %i, %%).
 * Return: The quantity of characters printed except the null terminator.
 */
int _printf(const char * const format, ...)
{
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	int printed_chars = 0;
	int format_index = 0;
	int i;

	handler_t types[] = {
		{'c', percent_c},
		{'d', percent_di},
		{'i', percent_di},
		{'s', percent_s},
		{'%', percent_percent},
		{'\0', NULL}
	};

	/* Declare the va_list of arguments and initialize it with va_start */
	va_list args;
	va_start(args, format);
	init_buffer(&buffer_index);


	/* While loop to iterate the format string and it continues until the */
	/* null terminator is found*/
	while (format != NULL && format[format_index] != '\0')
	{
		if (format[format_index] == '%')
		{
			format_index++;
			for (i = 0; types[i].format_specifier != '\0'; i++)
			{
				if (format[format_index] == types[i].format_specifier)
				{
					printed_chars += types[i].print_func(&args, buffer, &buffer_index);
					break;
				}
			}
		}
		else
		{
			append_to_buffer(buffer, &buffer_index, format[format_index]);
			printed_chars++;
		}

		format_index++;
	}

	flush_buffer(buffer, &buffer_index);
	va_end(args);
	return (printed_chars);
}

void init_buffer(int *p_buffer_index)
{
	*p_buffer_index = 0;
}

void flush_buffer(char *buffer, int *p_buffer_index) {
	if (*p_buffer_index > 0) {
		write(1, buffer, *p_buffer_index);
		*p_buffer_index = 0;
	}
}

void append_to_buffer(char *buffer, int *p_buffer_index, char c) {
	if (*p_buffer_index >= BUFFER_SIZE) {
		flush_buffer(buffer, p_buffer_index);
	}
	buffer[*p_buffer_index] = c;
	(*p_buffer_index)++;
}
