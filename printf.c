#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_format - Processes a format specifier
 * and calls the appropriate handler.
 * @format: The format string.
 * @types: Array of handler_t structures mapping specifiers to functions.
 * @args: Pointer to the list of arguments.
 * @buffer: Pointer to the output buffer.
 * @p_buffer_index: Pointer to the index of the current position in the buffer.
 *
 * Return: The number of characters printed for the specifier.
 */
int handle_format(
		const char *format,
		handler_t *types,
		va_list *args,
		char *buffer,
		int *p_buffer_index)
{
	int i, printed_chars = 0;
	/*
	 * Flag to check later if the format specifier is unknown
	 * set to one by default, if the format is valid, it is
	 * set to 0
	 */
	int is_unknown = 1;

	for (i = 0; types[i].format_specifier != '\0'; i++)
	{
		if (*format == types[i].format_specifier)
		{
			is_unknown = 0;
			printed_chars = types[i].print_func(args, buffer, p_buffer_index);
			break;
		}
	}

	/**
	 * If the `is_unknown` condition is true, it means that the format
	 * specifier is not supported/unknown so it has to be printed as
	 * a regular char.
	 */
	if (is_unknown)
		printed_chars = percent_unknown(*format, buffer, p_buffer_index);

	return (printed_chars);
}

/**
 * _printf - Custom implementation of printf.
 * @format: The format string containing the text and format specifiers.
 *
 * Description: This function processes a format string and calls the
 * appropriate handlers for each format specifier.
 *
 * Return: The total number of characters printed.
 */
int _printf(const char * const format, ...)
{
	char buffer[1024];
	int buffer_index = 0, printed_chars = 0, format_index = 0;
	handler_t types[] = {
		{'c', percent_c}, {'d', percent_di}, {'i', percent_di}, {'s', percent_s},
		{'%', percent_percent}, {'\0', NULL}
	};
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	init_buffer(&buffer_index);

	while (format[format_index] != '\0')
	{
		if (format[format_index] == '%')
		{
			format_index++;
			printed_chars += handle_format(&format[format_index], types,
					&args, buffer, &buffer_index);
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

/**
 * init_buffer - Initializes the buffer index to start at the beginning.
 * @p_buffer_index: Pointer to the index of the buffer.
 *
 * Description: This function sets the buffer index to zero, indicating
 * that the buffer is empty and ready to be written to.
 */
void init_buffer(int *p_buffer_index)
{
	*p_buffer_index = 0;
}

/**
 * flush_buffer - Outputs the contents of the buffer and resets it.
 * @buffer: The buffer containing the data to be flushed.
 * @p_buffer_index: Pointer to the index of the current position in the buffer.
 *
 * Description: This function sends the contents of the buffer to the standard
 * output and resets the buffer index to zero.
 */
void flush_buffer(char *buffer, int *p_buffer_index)
{
	write(1, buffer, *p_buffer_index); /* Writes buffer to standard output */
	*p_buffer_index = 0;
}

/**
 * append_to_buffer - Appends a character to the buffer.
 * @buffer: The buffer to append the character to.
 * @buffer_index: Pointer to the index of the current position in the buffer.
 * @c: The character to be appended to the buffer.
 *
 * Description: This function adds a single character to the buffer and
 * increments the buffer index. If the buffer is full, it flushes the buffer
 * before adding the new character.
 */
void append_to_buffer(char *buffer, int *buffer_index, char c)
{
	buffer[*buffer_index] = c;
	(*buffer_index)++;
	if (*buffer_index == 1024)
	{
		flush_buffer(buffer, buffer_index);
	}
}
