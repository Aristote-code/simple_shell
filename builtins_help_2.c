#include "shell.h"

/* Displays information on the shellby builtin command 'env'. */
void help_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/* Displays information on the shellby builtin command 'setenv'. */
void help_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new "
	            "environment variable, or modifies an existing one.\n"
	            "\tUpon failure, prints a message to stderr.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}

/* Displays information on the shellby builtin command 'unsetenv'. */
void help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an "
	            "environmental variable.\n"
	            "\tUpon failure, prints a message to stderr.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}
