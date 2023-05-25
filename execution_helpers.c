#include "main.h"
/**
 * get_command - gets the location for a command
 * @command: the command
 * Return: the command path
 */
char *get_command(char *command)
{
	char *path, *path_copy, *path_token, *command_path;
	int command_length = strlen(command), directory_length;
	struct stat stat_buffer;

	command_path = malloc(5 + command_length + 1);
	strcpy(command_path, "/bin/");
	strcat(command_path, command);
	if (stat(command_path, &stat_buffer) == 0)
		return (command_path);
	free(command_path);
	path = getenv("PATH");
	if (!path)
		return (NULL);
	path_copy = strdup(path);
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		directory_length = strlen(path_token);
		command_path = malloc(command_length + directory_length + 2);
		strcpy(command_path, path_token);
		strcat(command_path, "/");
		strcat(command_path, command);
		strcat(command_path, "\0");
		if (stat(command_path, &stat_buffer) == 0)
		{
			free(path_copy);
			return (command_path);
		}
		free(command_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	if (stat(command, &stat_buffer) == 0)
		return (command);
	return (NULL);
}
/**
 * execute_command - executes a command
 * @arguments: the arguments
 * Return: 0 if successful, -1 if not
 */
int execute_command(char **arguments)
{
	pid_t pid;
	char *command = get_command(arguments[0]);
	int status;

	if (command == NULL)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		perror("Failed to create child process\n");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(command, arguments, NULL) == -1)
		{
			perror("Failed to execute command");
			return (-1);
		}
	}
	else
		waitpid(pid, &status, 0);
	return (0);
}
