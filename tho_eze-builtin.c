#include "main.h"
/**
 * envir - prints the current environment variables.
 * @cm_d: The command entered.
 * Description: This function displays environment variables on output.
 * Return: void.
 */
void envir(char **cm_d __attribute__((unused)))
{
int i;

for (i = 0; environ[i] != NULL; i++)
{
_printf(environ[i], STDOUT_FILENO);
_printf("\n", STDOUT_FILENO);
}
}

/**
 * _exit - Exits the shell.
 * @cm_d: The command entered.
 * Description: No arg exits with
 * current status arg exits with specified status.
 * Return: void.
 */
void _exit(char **cm_d)
{
int cmd_number = 0;
int arg;

for (; cm_d[num_token] != NULL; num_token++)
;
if (cmd_number == 1)
{
free(cm_d);
free(line);
free(commands);
exit(status);
}
else if (cmd_number == 2)
{
arg = _atoi(cm_d[1]);
if (arg == -1)
{
_printf(shell_name, STDERR_FILENO);
_printf(": 1: exit: Illegal number: ", STDERR_FILENO);
_printf(cm_d[1], STDERR_FILENO);
_printf("\n", STDERR_FILENO);
status = 2;
}
else
{
free(line);
free(cm_d);
free(commands);
exit(arg);
}
}
else
_printf("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
