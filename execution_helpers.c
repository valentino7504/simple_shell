#include "main.h"
/**
 * prepend_bin - adds /bin/ to the beginning of a string
 * @command: the string
 * Return: the modified string
 */
char *prepend_bin(char *command)
{
	char *command_path = NULL;
	int command_length = _strlen(command);

	command_path = malloc(5 + command_length + 1);
	_strcpy(command_path, "/bin/");
	_strcat(command_path, command);
	_strcat(command_path, "\0");
	return (command_path);
}
/**
 * get_command - gets the location for a command
 * @command: the command
 * Return: the command path
 */
char *get_command(char *command)
{
	char *path, *path_copy, *path_token, *command_path = prepend_bin(command);
	int command_length = _strlen(command), directory_length;
	struct stat stat_buffer;

	if (stat(command_path, &stat_buffer) == 0)
		return (command_path);
	if (stat(command, &stat_buffer) == 0)
	{
		free(command_path);
		command_path = _strdup(command);
		return (command_path);
	}
	path = getenv("PATH");
	if (!path)
	{
		free(command_path);
		return (NULL);
	}
	path_copy = _strdup(path);
	path_token = strtok(path_copy, ":");
	free(command_path);
	while (path_token != NULL)
	{
		directory_length = _strlen(path_token);
		command_path = malloc(command_length + directory_length + 2);
		_strcpy(command_path, path_token);
		_strcat(command_path, "/");
		_strcat(command_path, command);
		_strcat(command_path, "\0");
		if (stat(command_path, &stat_buffer) == 0)
		{
			free(path_copy);
			return (command_path);
		}
		free(command_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
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
	char *arg_copy;
	char *command;
	int status, command_status = 0;

	if (arguments == NULL)
		return (-1);
	arg_copy = _strdup(arguments[0]);
	command = get_command(arg_copy);
	if (command == NULL)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		free(command);
		perror("Failed to create child process\n");
		return (-1);
	}
	else if (pid == 0)
	{
		command_status = execve(command, arguments, NULL);
		if (command_status == -1)
		{
			free(command);
			perror("Failed to execute command");
			return (-1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			command_status = WEXITSTATUS(status);
		free(command);
		free(arg_copy);
	}
	return (command_status);
}
