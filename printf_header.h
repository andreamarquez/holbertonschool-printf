#include <stdarg.h>
#ifndef FUNCTIONS_PRINT_H
#define FUNCTIONS_PRINT_H

int percent_c(va_list *args, char *buffer, int *p_buffer_index);
void init_buffer(int *p_buffer_index);
void append_to_buffer(char *buffer, int *p_buffer_index, char c);
void flush_buffer(char *buffer, int *p_buffer_index);

int _printf(const char *format, ...);

#endif /* FUNCTIONS_PRINT_H */


#ifndef STRUCTURES_PRINT_H
#define STRUCTURES_PRINT_H


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

#endif /* STRUCTURES_PRINT_H */
