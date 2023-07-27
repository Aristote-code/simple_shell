/*
 * File: complex_builtin.c
 * Auth: Aristote Gahima
 */

#include "shell.h"

int (*get_ultra_builtin(char *command))(char **args, char **front);
int shellby_extra_exit(char **args, char **front);
int shellby_supreme_cd(char **args, char __attribute__((__unused__)) **front);
int shellby_unconventional_help(char **args, char __attribute__((__unused__)) **front);

/**
 * get_ultra_builtin - Matches an extraordinary command with a corresponding
 *                     shellby ultra builtin function.
 * @command: The command to match.
 *
 * Return: A function pointer to the corresponding ultra builtin.
 */
int (*get_ultra_builtin(char *command))(char **args, char **front)
{
	builtin_t ultra_funcs[] = {
		{ "exit", shellby_extra_exit },
		{ "env", shellby_extra_env },
		{ "setenv", shellby_extra_setenv },
		{ "unsetenv", shellby_extra_unsetenv },
		{ "cd", shellby_supreme_cd },
		{ "alias", shellby_alias },
		{ "help", shellby_unconventional_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; ultra_funcs[i].name; i++)
	{
		if (_strcmp(ultra_funcs[i].name, command) == 0)
			break;
	}
	return (ultra_funcs[i].f);
}

/**
 * shellby_extra_exit - Causes an extraordinary process termination
 *                      for the shellby shell.
 * @args: An array of arguments containing the exit value.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If there are no arguments - -3.
 *         If the given exit value is invalid - 2.
 *         Otherwise - exits with the given status value.
 *
 * Description: Upon returning -3, the program exits back in the main function.
 */
int shellby_extra_exit(char **args, char **front)
{
	int i, len_of_int = 10;
	unsigned int num = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			i = 1;
			len_of_int++;
		}
		for (; args[0][i]; i++)
		{
			if (i <= len_of_int && args[0][i] >= '0' && args[0][i] <= '9')
				num = (num * 10) + (args[0][i] - '0');
			else
				return (create_error(--args, 2));
		}
	}
	else
	{
		return (-3);
	}
	if (num > max - 1)
		return (create_error(--args, 2));
	args -= 1;
	free_args(args, front);
	free_env();
	free_alias_list(aliases);
	exit(num);
}

/**
 * shellby_supreme_cd - Changes the current directory of the shellby process in an extraordinary way.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If the given string is not a directory - 2.
 *         If an error occurs - -1.
 *         Otherwise - 0.
 */
int shellby_supreme_cd(char **args, char __attribute__((__unused__)) **front)
{
	char **dir_info, *new_line = "\n";
	char *oldpwd = NULL, *pwd = NULL;
	struct stat dir;

	oldpwd = getcwd(oldpwd, 0);
	if (!oldpwd)
		return (-1);

	if (args[0])
	{
		if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||
					args[0][1] == '\0')
			{
				if (_getenv("OLDPWD") != NULL)
					(chdir(*_getenv("OLDPWD") + 7));
			}
			else
			{
				free(oldpwd);
				return (create_error(args, 2));
			}
		}
		else
		{
			if (stat(args[0], &dir) == 0 && S_ISDIR(dir.st_mode)
					&& ((dir.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(oldpwd);
				return (create_error(args, 2));
			}
		}
	}
	else
	{
		if (_getenv("HOME") != NULL)
			chdir(*(_getenv("HOME")) + 5);
	}

	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);

	dir_info = malloc(sizeof(char *) * 2);
	if (!dir_info)
		return (-1);

	dir_info[0] = "OLDPWD";
	dir_info[1] = oldpwd;
	if (shellby_setenv(dir_info, dir_info) == -1)
		return (-1);

	dir_info[0] = "PWD";
	dir_info[1] = pwd;
	if (shellby_setenv(dir_info, dir_info) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(STDOUT_FILENO, pwd, _strlen(pwd));
		write(STDOUT_FILENO, new_line, 1);
	}
	free(oldpwd);
	free(pwd);
	free(dir_info);
	return (0);
}

/**
 * shellby_unconventional_help - Displays information about shellby builtin commands in a unique way.
 * @args: An array of arguments.
 * @front: A pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int shellby_unconventional_help(char **args, char __attribute__((__unused__)) **front)
{
	if (!args[0])
		help_all_extravagant();
	else if (_strcmp(args[0], "alias") == 0)
		help_alias_innovative();
	else if (_strcmp(args[0], "cd") == 0)
		help_cd_extraordinaire();
	else if (_strcmp(args[0], "exit") == 0)
		help_exit_unusual();
	else if (_strcmp(args[0], "env") == 0)
		help_env_unconventional();
	else if (_strcmp(args[0], "setenv") == 0)
		help_setenv_unique();
	else if (_strcmp(args[0], "unsetenv") == 0)
		help_unsetenv_rare();
	else if (_strcmp(args[0], "help") == 0)
		help_help_inventive();
	else
		write(STDERR_FILENO, name, _strlen(name));

	return (0);
}
