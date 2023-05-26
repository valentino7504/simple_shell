#include "main.h"
/**
 * print_error - prints error message and exits
 * @error_message: error message
 * @exit_code: the exit code
 */
void print_error(const char *error_message, const int exit_code)
{
	fprintf(stderr, "%s", error_message);
	exit(exit_code);
}
/**
 * get_token_count - gets the number of tokens in the user's entry
 * @user_entry: the user entry
 * Return: the number of tokens
 */
int get_token_count(char *user_entry)
{
	char *entry_copy = _strdup(user_entry), *token;
	int token_count = 0;

	if (entry_copy == NULL)
		print_error("Memory allocation error\n", -1);
	token = strtok(entry_copy, " ");
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, " ");
	}
	free(entry_copy);
	return (token_count);
}
/**
 * tokenize - tokenizes the user's input
 * @user_entry: the user's input
 * Return: an array of the tokenized input
 */
char **tokenize(char *user_entry)
{
	char **args, *token;
	int i = 0, token_count = get_token_count(user_entry);

	args = malloc(sizeof(char *) * (token_count + 1));
	if (args == NULL)
		print_error("Memory allocation error\n", -1);
	token = strtok(user_entry, " ");
	for (i = 0; i < token_count; i++)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
/**
 * read_user_input - reads user input
 * Shell exits on Ctrl + D
 * Return: Returns the user's input
 */
char *read_user_input()
{
	ssize_t characters_read = 0;
	char *user_entry = NULL;
	size_t n = 0;

	if (isatty(STDIN_FILENO))
		printf("$ ");
	characters_read = getline(&user_entry, &n, stdin);
	if (characters_read == -1)
	{
		free(user_entry);
		return (NULL);
	}
	if (user_entry[characters_read - 1] == '\n')
		user_entry[characters_read - 1] = '\0';
	return (user_entry);
}
/**
 * free_args - frees up the argument list
 * @args: the argument list
 */
void free_args(char **args)
{
	int i = 0;

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}
