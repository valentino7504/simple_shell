#include "main.h"
/**
 * main - This is the main function that runs the shell.
 * @argc: The number of command line arguments.
 * @argv: The command line arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *prompt = "$", *user_entry, **args;
	int token_count = 0, i;

	(void)argc;
	while (1)
	{
		printf("%s ", prompt);
		user_entry = read_user_input();
		if (user_entry == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		if (strcmp(user_entry, "exit") == 0)
			exit(EXIT_SUCCESS);
		args = tokenize(user_entry);
		if (execute_command(args) == -1)
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
		for (i = 0; args[i] != NULL; i++)
			token_count++;
		free_args(args, token_count);
		free(user_entry);
		token_count = 0;
	}
	return (0);
}
