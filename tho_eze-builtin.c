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


