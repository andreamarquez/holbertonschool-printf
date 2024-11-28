# holbertonschool-printf

SYNOPSIS:

Welcome to the custom implementation of the _printf function! This project is a simplified version of the standard C library printf function, designed to handle formatted output according to specific format specifiers.


Handler.c file:

this is a file wich contains a function for each specifier.
the supported format specifiers by _printf are:
    
    %c              Prints a single character
    %s              Prints a string
    %d, %i          Prints an integer in decimal notation. Positives and negatives.
    %%              Prints a literal % character
    
        Unsupported format specifiers are printed as %<unknown>

Main.h file:
This file is our own library which contains the prototypes of each functions 
and the structure of handler.


Features and Limitations:

    Internal Buffer: Uses a fixed 1024-byte buffer to optimize output operations.
    Error Handling: Returns -1 if the format string is NULL.
    Minimal Memory Footprint: Uses simple structures and lightweight processing.
    
    No Advanced Formatting: Does not support field width, precision, or flags like +, -, or 0.
    Limited Specifiers: Only the specifiers listed above are implemented.
    Fixed Buffer Size: The buffer is limited to 1024 bytes, and outputs exceeding
    this size are flushed incrementally.

Help:

    If you need more details you can acces the man_3_printf file or contact the authors.
    -9815@holbertonstudents.com
    -9948@holbertonstudents.com


