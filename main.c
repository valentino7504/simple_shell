#include "main.h"
/**
 * main - This is the main function that runs the shell.
 * @argc: The number of command line arguments.
 * @argv: The command line arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *user_entry, **args;

	(void)argc;
	while (1)
	{
		printf("$ ");
		user_entry = read_user_input();
		if (user_entry == NULL)
		{
			printf("\n");
			return (0);
		}
		if (strcmp(user_entry, "exit") == 0)
		{
			free(user_entry);
			break;
		}
		args = tokenize(user_entry);
		if (execute_command(args) == -1)
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
		free_args(args);
		free(user_entry);
	}
	return (0);
}
