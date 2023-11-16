#include "main.h"

/**
 *_printf - Prints a string to the specified output.
 *@string: String to be printed.
 *@x: Output to print.
 *Return: void
 */
void _printf(char *string, int x)
{
int i = 0;

for (; string[i] != '\0'; i++)
write(x, &string[i], 1);
}
