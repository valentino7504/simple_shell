#include "main.h"
/**
 * main - This is the main function that runs the shell.
 * @argc: The number of command line arguments.
 * @argv: The command line arguments.
 * Return: Always 0.
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *user_entry, **args;
	int is_interactive = isatty(STDIN_FILENO), status = 0, command_status = 0;

	while (1)
	{
		user_entry = read_user_input();
		if (user_entry == NULL)
		{
			if (is_interactive)
				printf("\n");
			exit(status);
		}
		if (_strcmp(user_entry, "exit") == 0)
		{
			free(user_entry);
			exit(status);
		}
		if (strspn(user_entry, " \n") == _strlen(user_entry))
		{
			free(user_entry);
			continue;
		}
		args = tokenize(user_entry);
		command_status = execute_command(args);
		if (command_status == -1)
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
		status = command_status;
		free_args(args);
		free(user_entry);
	}
	return (status);
}
