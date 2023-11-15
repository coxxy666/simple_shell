#include "main.h"
/**
 * tokenizer - Splits the input string into tokens and stores.
 *@str_split: Input string to be parsed.
 *@delim_char: character to be used.
 *Return: Array of tokens
 */
char **tokenizer(char *str_split, char *delim_char)
{
int delim_num = 0;
char **x = NULL;
char *y = NULL;
char *z = NULL;

y = _stringtok(str_split, delim_char, &z);
while (y != NULL)
{
x = _real_mem(x, sizeof(*x) * delim_num, sizeof(*x) * (delim_num + 1));
x[delim_num] = y;
y = _stringtok(NULL, delim_char, &z);
delim_num++;
}

x = _real_mem(x, sizeof(*x) * delim_num, sizeof(*x) * (delim_num + 1));
x[delim_num] = NULL;

return (x);
}

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

/**
 *rem_newline - Removes newline characters from a string.
 *@string: string to be modified.
 *Return: void
 */
void rem_newline(char *string)
{
int i = 0;

while (string[i] != '\0')
{
if (string[i] == '\n')
break;
i++;
}
string[i] = '\0';
}

/**
 *_stringlen - Calculates the length of a string.
 *@string: String to be measured.
 * Return: Length of the string.
 */
int _stringlen(char *string)
{
int x = 0;

if (string == NULL)
return (x);
for (; string[x] != '\0'; x++)
;
return (x);
}

#include "main.h"
/**
 *_stringcopy - Copies a string to destination.
 *@x: string to copy from.
 *@y: destination buffer to copy to.
 * Return: void
 */
void _stringcopy(char *x, char *y)
{
int i = 0;

for (; x[i] != '\0'; i++)
y[i] = x[i];
y[i] = '\0';
}
