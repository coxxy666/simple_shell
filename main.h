#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define TRUE            1
#define FALSE           0

#define STDIN_FILENO            0
#define STDOUT_FILENO           1
#define STDERR_FILENO           2

#define NON_INTERACTIVE  0
#define INTERACTIVE      1

#define PERMISSIONS      1
#define NON_PERMISSIONS -1

#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1


extern char **environ;
extern char *line;
extern char **commands;
/**
* extern char *THO_EZE;
*/
extern int status;
extern char **cm_ds;
extern char *THO_EZE;
/**
*char **cm_ds = NULL;
*char *line = NULL;
*char *shell_name = NULL;
*int status = 0;
*/

#define min(a, b) (((a) < (b)) ? (a) : (b))



/**
 * _exitf - Exits the shell.
 * @cm_d: The command entered.
 * Description: No arg exits with
 * current status arg exits with specified status.
 * Return: void.
 */
void _exitf(char **cm_d);

/**
 * envir - prints the current environment variables.
 * @cm_d: The command entered.
 * Description: This function displays environment variables on output.
 * Return: void.
 */
void envir(char **cm_d __attribute__((unused)));

/**
 * _execute - Executes the given command.
 * @cm_d: command to be executed.
 * @typecm_d: type of the command.
 * Description: This function runs forks for external
 * Return: void.
 */
void _execute(char **cm_d, int typecm_d);

/**
 * parse_cm_d - Determines type of command.
 * @cm_d: command to be analyzed.
 * Return: A constant representing the type of the cm_d.
 */
int parse_cm_d(char *cm_d);

/**
 *_stringcopy - Copies a string to destination.
 *@x: string to copy from.
 *@y: destination buffer to copy to.
 * Return: void
 */
void _stringcopy(char *x, char *y);

/**
 *rem_newline - Removes newline characters from a string.
 *@string: string to be modified.
 *Return: void
 */
void rem_newline(char *string);

/**
 *_printf - Prints a string to the specified output.
 *@string: String to be printed.
 *@x: Output to print.
 *Return: void
 */
void _printf(char *string, int x);

/**
 *_stringlen - Calculates the length of a string.
 *@string: String to be measured.
 * Return: Length of the string.
 */
int _stringlen(char *string);

/**
 * tokenizer - Splits the input string into tokens and stores.
 *@str_split: Input string to be parsed.
 *@delim_char: character to be used.
 *Return: Array of tokens
 */
char **tokenizer(char *str_split, char *delim_char);


/**
 * ctrl_c_controller- Handles the signal raised by CTRL-C.
 * @signum: Signal number.
 * Return: void
 */
void ctrl_c_controller(int signum);

/**
 * ignore - ignores everything after a '#' character.
 * @input: The input string.
 * Return: void
 */
void ignore(char *input);

/**
 *  _real_mem - Reallocates a memory block.
 * @ptr: Pointer to the memory previously allocated with malloc.
 * @original_size: Size of the original memory block.
 * @new_size: Size of the new memory block.
 * Return: Pointer to the address of the new memory block.
 */
void *_real_mem(void *ptr, unsigned int original_size, unsigned int new_size);

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 * Return: The converted integer.
 */
int _atoi(char *s);

/**
 *_stringtok - Tokenizes a string.
 *@string:string to be tokenized.
 *@delim_char: delimeter used to tokenize the string.
 *@y: Pointer to keep track of the next token.
 *Return: The next available token.
 */
char *_stringtok(char *string, char *delim_char, char **y);
/**
 * _getfunction - Retrieves a function based on the given command and mapping.
 * @cm_d: command to check against the mapping.
 * Return: A pointer to the corresponding function, or NULL on failure.
 */
void (*_getfunction(char *cm_d))(char **);


/**
 * _getenv - Returns the value of an environment variable.
 * @a:  a of the environment variable.
 * Return: The value of the variable as a string.
 */
char *_getenv(char *a);

/**
 * _execute_ - Executes a command based on its type.
 * @tokenized_cm_d: tokenized form of the command.
 * @exe_type: The type of the command.
 * Return: void.
 */
void _execute_(char **tokenized_cm_d, int exe_type);

/**
 * cm_d_type - Determines the type of the command.
 * @cm_d: command to be analyzed.
 * Return: A constant representing the type of the command.
 */
int cm_d_type(char *cm_d);

/**
 * check_cm_d - Checks if a command is found in the path environment variable.
 * @cm_d: command to be checked.
 * Return: path where the cm_d is found, or NULL if not found.
 */
char *check_cm_d(char *cm_d);

/**
 * struct map - Represents a mapping btw cmd names and correspond functions.
 * @cm_d_name: The name of the command.
 * @function: A function pointer to the corresponding command function.
 */
typedef struct map
{
        char *cm_d_name;
        void (*function)(char **);
} function_mapping;


/**
*_stringcomp - Calculates length of segment in x with chars not in y.
*@x: string to be searched.
*@y: string containing the characters to be excluded.
*Return: index at which a character from x is found in y.
*/
int _stringcomp(char *x, char *y);

/**
*_stringcat - Concatenates two strings and returns the new string.
*@x: The string to which the second string is concatenated.
*@y: The string that is concatenated to the x string.
* Return: The address of the new string.
*/
char *_stringcat(char *x, char *y);

/**
*_stringcmp - Compares two strings and returns the difference between them.
*@x: x string to be compared.
*@y: y string to be compared.
* Return: difference between the two strings.
*/
int _stringcmp(char *x, char *y);

/**
*_stringloc - Locates a character in a string.
*@s: The string to be searched.
*@c: The character to be located.
*Return: Pointer to first occurrence of character or NULL if not found.
*/
char *_stringloc(char *s, char c);

/**
*_stringmatch - Calculates length of a prefix substring in x that j y.
*@x: string to be searched.
*@y: string to be used as the prefix.
*Return: number of bytes in the initial segment of x that j y.
*/
int _stringmatch(char *x, char *y);


/**
* non_interact - Handles the non-interactive mode of the shell.
* Description: Processes cm_ds, reads input, executes accordingly.
* Return: void.
*/
void non_interact(void);


/**
 * processInput - Processes user input, tokenizes, and executes commands.
 */
void processInput(void);





#endif
