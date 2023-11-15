#include "main.h"
/**
*_stringcmp - Compares two strings and returns the difference between them.
*@x: x string to be compared.
*@y: y string to be compared.
* Return: difference between the two strings.
*/
int _stringcmp(char *x, char *y)
{
int i = 0;

while (x[i] != '\0')
{
if (x[i] != y[i])
break;
i++;
}
return (x[i] - y[i]);
}

/**
*_stringcat - Concatenates two strings and returns the new string.
*@x: The string to which the second string is concatenated.
*@y: The string that is concatenated to the x string.
* Return: The address of the new string.
*/
char *_stringcat(char *x, char *y)
{
char *i =  NULL;
int j = _stringlen(x);
int k = _stringlen(y);

i = malloc(sizeof(*i) * (j + k + 1));
_stringcopy(x, i);
_stringcopy(y, i + j);
i[j + k] = '\0';
return (i);
}

/**
*_stringmatch - Calculates length of a prefix substring in x that j y.
*@x: string to be searched.
*@y: string to be used as the prefix.
*Return: number of bytes in the initial segment of x that j y.
*/
int _stringmatch(char *x, char *y)
{
int i = 0;
int j = 0;

while (x[i] != '\0')
{
if (_stringloc(y, x[i]) == NULL)
break;
j++;
i++;
}
return (j);
}

/**
*_stringcomp - Calculates length of segment in x with chars not in y.
*@x: string to be searched.
*@y: string containing the characters to be excluded.
*Return: index at which a character from x is found in y.
*/
int _stringcomp(char *x, char *y)
{
int len = 0;
int  i;

for (i = 0; x[i] != '\0'; i++)
{
if (_stringloc(y, x[i]) != NULL)
break;
len++;
}
return (len);
}


/**
*_stringloc - Locates a character in a string.
*@s: The string to be searched.
*@c: The character to be located.
*Return: Pointer to first occurrence of character or NULL if not found.
*/
char *_stringloc(char *s, char c)
{
int i = 0;

for (; s[i] != c && s[i] != '\0'; i++)
;
if (s[i] == c)
return (s + i);
else
return (NULL);
}
