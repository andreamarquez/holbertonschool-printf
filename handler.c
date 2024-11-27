#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * percent_di - Handles the `%d` and `%i` format specifiers in printf.
 * @args: Pointer to the list of arguments.
 * @buffer: Pointer to the output buffer.
 * @p_buffer_index: Pointer to the index of the current position in the buffer.
 *
 * Description: Converts an integer to its string representation and appends
 * it to the buffer. Handles negative integers by adding a '-' sign
 * to the buffer before converting the absolute value of the number.
 *
 * Return: The total number of characters added to the buffer.
 */
int percent_di(va_list *args, char *buffer, int *p_buffer_index)
{
	int num = va_arg(*args, int);
	char str[12]; /* Enough to hold the largest int (-2147483648) */
	int i = 0, char_count = 0;

	if (num < 0)
	{
		append_to_buffer(buffer, p_buffer_index, '-');
		char_count++; /* Count the '-' */
		num = -num;
	}

	if (num == 0)
	{
		append_to_buffer(buffer, p_buffer_index, '0');
		return (1); /* Only one character added */
	}

	while (num > 0)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}

	char_count += i; /* Add the number of digits */

	while (i > 0)
	{
		append_to_buffer(buffer, p_buffer_index, str[--i]);
	}

	return (char_count); /* Return the total characters added */
}

/**
 * percent_percent - Handles the `%%` format specifier in printf.
 * @args: Pointer to the list of arguments (unused).
 * @buffer: Pointer to the output buffer.
 * @p_buffer_index: Pointer to the index of the current position in the buffer.
 *
 * Description: Adds a literal '%' character to the buffer.
 *
 * Return: Always 1, as only one character is added to the buffer.
 */
int percent_percent(va_list *args, char *buffer, int *p_buffer_index)
{
	(void)args; /* No arguments needed for %% */
	append_to_buffer(buffer, p_buffer_index, '%');
	return (1);
}

/**
 * percent_s - Handles the `%s` format specifier in printf.
 * @args: Pointer to the list of arguments.
 * @buffer: Pointer to the output buffer.
 * @p_buffer_index: Pointer to the index of the current position in the buffer.
 *
 * Description: Appends a string to the buffer. If the string is NULL,
 * appends "(null)" to the buffer instead.
 *
 * Return: The total number of characters added to the buffer.
 */
int percent_s(va_list *args, char *buffer, int *p_buffer_index)
{
	char *str = va_arg(*args, char *);
	int count = 0;

	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str)
	{
		append_to_buffer(buffer, p_buffer_index, *str++);
		count++;
	}

	return (count); /* Total characters added */
}


/**
 * percent_c - Handles the `%c` format specifier in printf.
 * @args: Pointer to the list of arguments.
 * @buffer: Pointer to the output buffer.
 * @p_buffer_index: Pointer to the index of the current position in the buffer.
 *
 * Description: Extracts a character from the arguments and appends it
 * to the buffer.
 *
 * Return: Always 1, as one character is added to the buffer.
 */
int percent_c(va_list *args, char *buffer, int *p_buffer_index)
{
	char c = va_arg(*args, int);

	append_to_buffer(buffer, p_buffer_index, c);
	return (1); /* One character was added to the buffer */
}


/**
 * percent_unknown - Handles unknown format specifiers in printf.
 * @unknown_format: The unknown format specifier character.
 * @buffer: The buffer to which the character should be appended.
 * @p_buffer_index: Pointer to the current index in the buffer.
 *
 * This function appends the unknown format specifier to the buffer
 * and increments the buffer index.
 *
 * Return: Always returns 1, indicating one character was added to the buffer.
 */
int percent_unknown(char unknown_format, char *buffer, int *p_buffer_index)
{
	/* Append the '%' character */
	append_to_buffer(buffer, p_buffer_index, '%');
	/* Append the unknown format specifier */
	append_to_buffer(buffer, p_buffer_index, unknown_format);
	/* Return 2 because two characters were added to the buffer */
	return (2);
}
