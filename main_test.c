#include "printf_header.h"


int main(void)
{
	char separator = 'h';
	char separator2 = 'i';
	char *greetings = "Hello Andrea";
	_printf("Test %c%c %s", separator, separator2, greetings);
	return (0);
}
