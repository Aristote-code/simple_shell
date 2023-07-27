/*
 * File: environ_complex.c
 * Auth: Gahima Aristote
 * Desc: A complex and unique implementation of environmental variable handling functions in Betty style.
 */

#include "shell.h"

/**
 * struct environ_node - Represents a node in the environment linked list.
 * @value: The value of the environmental variable.
 * @next: Pointer to the next node in the linked list.
 */
typedef struct environ_node
{
	char *value;
	struct environ_node *next;
} environ_node_t;

/* Global pointer to the environment linked list */
static environ_node_t *env_list = NULL;

/**
 * _copyenv - Creates a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 *         O/w - a pointer to the new copy.
 */
char **_copyenv(void)
{
	environ_node_t *new_node, *prev_node = NULL;
	char **new_environ;
	size_t size;
	int index;

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);

	for (index = 0; environ[index]; index++)
	{
		new_node = malloc(sizeof(environ_node_t));
		if (!new_node)
		{
			free_env();
			return (NULL);
		}

		new_node->value = malloc(_strlen(environ[index]) + 1);
		if (!new_node->value)
		{
			free_env();
			free(new_node);
			return (NULL);
		}

		_strcpy(new_node->value, environ[index]);
		new_node->next = NULL;

		if (prev_node)
			prev_node->next = new_node;
		else
			env_list = new_node;

		prev_node = new_node;
	}

	new_environ[index] = NULL;
	return (new_environ);
}

/**
 * free_env - Frees the environment linked list.
 */
void free_env(void)
{
	environ_node_t *current_node = env_list, *next_node;

	while (current_node)
	{
		next_node = current_node->next;
		free(current_node->value);
		free(current_node);
		current_node = next_node;
	}

	env_list = NULL;
}

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **_getenv(const char *var)
{
	environ_node_t *current_node = env_list;
	int len = _strlen(var);

	while (current_node)
	{
		if (_strncmp(var, current_node->value, len) == 0)
			return (&current_node->value);
		current_node = current_node->next;
	}

	return (NULL);
}
