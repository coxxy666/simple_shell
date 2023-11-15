#include "main.h"
/**
* non_interact - Handles the non-interactive mode of the shell.
* Description: Processes cm_ds, reads input, executes accordingly.
* Return: void.
*/
void non_interact(void)
{
char **current_cm_d = NULL;
int i;
int type_cm_d = 0;
size_t n = 0;

if (!(isatty(STDIN_FILENO)))
{
while (getline(&line, &n, stdin) != -1)
{
rem_newline(line);
ignore(line);
cm_ds = tokenizer(line, ";");
for (i = 0; cm_ds[i] != NULL; i++)
{
current_cm_d = tokenizer(cm_ds[i], " ");
if (current_cm_d[0] == NULL)
{
free(current_cm_d);
break;
}
type_cm_d = cm_d_type(current_cm_d[0]);
_execute(current_cm_d, type_cm_d);
free(current_cm_d);
}
free(cm_ds);
}
free(line);
exit(status);
}
}
