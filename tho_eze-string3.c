#include "main.h"
/**
 *_stringtok - Tokenizes a string.
 *@string:string to be tokenized.
 *@delim_char: delimeter used to tokenize the string.
 *@y: Pointer to keep track of the next token.
 *Return: The next available token.
 */
char *_stringtok(char *string, char *delim_char, char **y)
{
char *x;

if (string == NULL)
string = *y;

if (*string == '\0')
{
*y = string;
return (NULL);
}

string += _stringmatch(string, delim_char);
if (*string == '\0')
{
*y = string;
return (NULL);
}

x = string + _stringcomp(string, delim_char);
if (*x == '\0')
{
*y = x;
return (string);
}

*x = '\0';
*y = x + 1;
return (string);
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 * Return: The converted integer.
 */
int _atoi(char *s)
{
unsigned int n = 0;

do {
if (*s == '-')
return (-1);
else if ((*s < '0' || *s > '9') && *s != '\0')
return (-1);
else if (*s >= '0'  && *s <= '9')
n = (n * 10) + (*s - '0');
else if (n > 0)
break;
} while (*s++);
return (n);
}


/**
 *  _real_mem - Reallocates a memory block.
 * @ptr: Pointer to the memory previously allocated with malloc.
 * @original_size: Size of the original memory block.
 * @new_size: Size of the new memory block.
 * Return: Pointer to the address of the new memory block.
 */
void *_real_mem(void *ptr, unsigned int original_size, unsigned int new_size)
{
void *block;
unsigned int i;

if (ptr == NULL)
{
block = malloc(new_size);
return (block);
}
else if (new_size == original_size)
return (ptr);
else if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
else
{
block = malloc(new_size);
if (block != NULL)
{
for (i = 0; i < min(original_size, new_size); i++)
*((char *)block + i) = *((char *)ptr + i);
free(ptr);
return (block);
}
else
return (NULL);
}
}

/**
 * ctrl_c_controller- Handles the signal raised by CTRL-C.
 * @signum: Signal number.
 * Return: void
 */
void ctrl_c_controller(int signum)
{
if (signum == SIGINT)
_printf("\n($) ", STDIN_FILENO);
}

/**
 * ignore - ignores everything after a '#' character.
 * @input: The input string.
 * Return: void
 */
void ignore(char *input)
{
int i = 0;

if (input[i] == '#')
input[i] = '\0';
while (input[i] != '\0')
{
if (input[i] == '#' && input[i - 1] == ' ')
break;
i++;
}
input[i] = '\0';
}
