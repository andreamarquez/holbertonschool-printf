#include <stdarg.h>
#include "printf_header.h"
#include <stddef.h>

int percent_di(va_list *args, char *buffer, int *p_buffer_index)
{
	int num = va_arg(*args, int);
	char str[12]; /* Enough to hold the largest int (-2147483648) plus null terminator */
	int i = 0;

	if (num < 0)
	{
		append_to_buffer(buffer, p_buffer_index, '-');
		num = -num;
	}

	if (num == 0)
	{
		append_to_buffer(buffer, p_buffer_index, '0');
		return (1);
	}

	while (num > 0)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}

	while (i > 0)
	{
		append_to_buffer(buffer, p_buffer_index, str[--i]);
	}

	return (i); /* Total characters adde_d */
}

int percent_percent(va_list *args, char *buffer, int *p_buffer_index)
{
    (void)args; /* No arguments needed for %% */
    append_to_buffer(buffer, p_buffer_index, '%');
    return (1);
}

int percent_s(va_list *args, char *buffer, int *p_buffer_index)
{
    char *str = va_arg(*args, char *);
    int count = 0;

    if (str == NULL)
    {
        str = "(null)";
    }

    while (*str != '\0')
    {
        append_to_buffer(buffer, p_buffer_index, *str);
        str++;
        count++;
    }

    return (count);
}

int percent_c(va_list *args, char *buffer, int *p_buffer_index)
{
    char c = va_arg(*args, int);
    append_to_buffer(buffer, p_buffer_index, c);
    return (1); /* One character was added to the buffer */
}
