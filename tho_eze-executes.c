#include "main.h"
/**
 * _execute - Executes the given command.
 * @cm_d: command to be executed.
 * @typecm_d: type of the command.
 * Description: This function runs forks for external
 * Return: void.
 */
void _execute(char **cm_d, int typecm_d)
{
pid_t PID;

if (typecm_d == EXTERNAL_COMMAND || typecm_d == PATH_COMMAND)
{
PID = fork();
if (PID == 0)
_execute_(cm_d, typecm_d);
else
{
waitpid(PID, &status, 0);
status >>= 8;
}
}
else
_execute_(cm_d, typecm_d);
}
