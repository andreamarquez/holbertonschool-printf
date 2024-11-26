#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Structures */
/**
 * struct handler - Structure to map format specifiers to their corresponding
 * print functions.
 * @format_specifier: The format specifier character (ex., 'i' for integers,
 *'s' for strings).
 * @print_func: Pointer to the function that handles printing for the given
 * format specifier. The function takes a va_list of arguments.
 */
typedef struct handler
{
	char format_specifier;
	int (*print_func)(va_list *args, char *buffer, int *p_buffer_index);
} handler_t;


/* Function Prototypes */
int percent_s(va_list *args, char *buffer, int *p_buffer_index);
int percent_percent(va_list *args, char *buffer, int *p_buffer_index);
int percent_di(va_list *args, char *buffer, int *p_buffer_index);
int percent_c(va_list *args, char *buffer, int *p_buffer_index);
int percent_unknown(char unknown_format, char *buffer, int *p_buffer_index);
void init_buffer(int *p_buffer_index);
void append_to_buffer(char *buffer, int *p_buffer_index, char c);
void flush_buffer(char *buffer, int *p_buffer_index);
int _printf(const char *format, ...);
int handle_format(const char *format, handler_t *types, va_list *args,
		char *buffer, int *p_buffer_index);


#endif /* PRINT_H */
