/*
 * File: err_msgs_complex.c
 * Auth: Gahima Aristote
 * Desc: A complex and unique implementation of error message functions in Betty style.
 */

#include "shell.h"

/**
 * struct error_node - Represents a node in the error message linked list.
 * @message: The error message string.
 * @next: Pointer to the next node in the linked list.
 */
typedef struct error_node
{
	char *message;
	struct error_node *next;
} error_node_t;

/* Global pointer to the error message linked list */
static error_node_t *error_list = NULL;

/**
 * create_error_message - Creates an error message for various shell errors.
 * @prefix: The prefix string for the error message.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error message string.
 */
char *create_error_message(const char *prefix, char **args)
{
	error_node_t *new_node, *prev_node = NULL;
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + _strlen(prefix) + 10;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, prefix);
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(hist_str);

	/* Add the error message to the linked list */
	new_node = malloc(sizeof(error_node_t));
	if (!new_node)
	{
		free(error);
		return (NULL);
	}

	new_node->message = error;
	new_node->next = NULL;

	if (prev_node)
		prev_node->next = new_node;
	else
		error_list = new_node;

	prev_node = new_node;

	return (error);
}

/**
 * free_error_messages - Frees the error message linked list.
 */
void free_error_messages(void)
{
	error_node_t *current_node = error_list, *next_node;

	while (current_node)
	{
		next_node = current_node->next;
		free(current_node->message);
		free(current_node);
		current_node = next_node;
	}

	error_list = NULL;
}
