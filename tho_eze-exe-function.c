#include "main.h"
/**
 * cm_d_type - Determines the type of the command.
 * @cm_d: command to be analyzed.
 * Return: A constant representing the type of the command.
 */
int cm_d_type(char *cm_d)
{
int i;
char *internal_cm_d[] = {"thoeze", "exit", NULL};
char *x = NULL;

for (i = 0; cm_d[i] != '\0'; i++)
{
if (cm_d[i] == '/')
return (EXTERNAL_COMMAND);
}
for (i = 0; internal_cm_d[i] != NULL; i++)
{
if (_stringcmp(cm_d, internal_cm_d[i]) == 0)
return (INTERNAL_COMMAND);
}
x = check_x(cm_d);
if (x != NULL)
{
free(x);
return (PATH_COMMAND);
}

return (INVALID_COMMAND);
}


/**
 * _execute_ - Executes a command based on its type.
 * @tokenized_cm_d: tokenized form of the command.
 * @exe_type: The type of the command.
 * Return: void.
 */
void _execute_(char **tokenized_cm_d, int exe_type)
{
void (*function)(char **cm_d);

if (exe_type == EXTERNAL_COMMAND)
{
if (execve(tokenized_cm_d[0], tokenized_cm_d, NULL) == -1)
{
perror(_getenv("PWD"));
exit(2);
}
}
if (exe_type == PATH_COMMAND)
{
if (execve(check_cm_d(tokenized_cm_d[0]), tokenized_cm_d, NULL) == -1)
{
perror(_getenv("PWD"));
exit(2);
}
}
if (exe_type == INTERNAL_COMMAND)
{
func = _getfunction(tokenized_cm_d[0]);
func(tokenized_cm_d);
}
if (exe_type == INVALID_COMMAND)
{
_printf(THO_EZE, STDERR_FILENO);
_printf(": 1: ", STDERR_FILENO);
_printf(tokenized_cm_d[0], STDERR_FILENO);
_printf(": not found\n", STDERR_FILENO);
status = 127;
}
}


/**
 * check_cm_d - Checks if a command is found in the path environment variable.
 * @cm_d: command to be checked.
 * Return: path where the cm_d is found, or NULL if not found.
 */
char *check_cm_d(char *cm_d)
{
char **a= NULL;
char *b;
 char *c;
 char *d;
char *e = _getenv("path");
int i;

if (e == NULL || _stringlen(e) == 0)
return (NULL);
d = malloc(sizeof(*d) * (_stringlen(e) + 1));
_stringcopy(e, d);
a= tokenizer(d, ":");
for (i = 0; a[i] != NULL; i++)
{
c = _stringcat(a[i], "/");
b = _stringcat(c, cm_d);
if (access(b, F_OK) == 0)
{
free(c);
free(a);
free(d);
return (b);
}
free(b);
free(c);
}
free(d);
free(a);
return (NULL);
}

/**
 *  _getfunction- Retrieves a function based on the given cm_d and mapping.
 * @cm_d: cm_d to check against the mapping.
 * Return: A pointer to the corresponding function, or NULL on failure.
 */
void (*_getfunction(char *cm_d))(char **)
{
int i;
function_mapping mapping[] = {
{"env", env}, {"exit", quit}};

for (i = 0; i < 2; i++)
{
if (_stringcmp(cm_d, mapping[i].cm_d_name) == 0)
return (mapping[i].function);
}
return (NULL);
}

/**
 * _getenv - Returns the value of an environment variable.
 * @a:  a of the environment variable.
 * Return: The value of the variable as a string.
 */
char *_getenv(char *a)
{
char **x;
char *y;
char *z;

for (x = environ; *x != NULL; x++)
{
for (y = *x, z = a;
*y == *z; y++, z++)
{
if (*y == '=')
break;
}
if ((*y == '=') && (*z == '\0'))
return (y + 1);
}
return (NULL);
}


