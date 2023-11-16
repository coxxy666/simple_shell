#include "main.h"

char **cm_ds = NULL;
char *line = NULL;
int status = 0;
char *shell_name = NULL;


/**
* main - The main function of the shell program.
* @argc: The number of arguments passed to the program.
* @argv: The program arguments to be parsed.
* Return: 0 on success.
*/
int main(int argc __attribute__((unused)), char **argv)
{
char **current_cm_d = NULL;
int i;
int type_cm_d = 0;
size_t n = 0;



signal(SIGINT, ctrl_c_controller);
shell_name = argv[0];
while (1)
{
non_interact();
_printf(" ($) ", STDOUT_FILENO);
if (getline(&line, &n, stdin) == -1)
{
free(line);
exit(status);
}
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

return (status);
}
