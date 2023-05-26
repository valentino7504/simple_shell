#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
void free_args(char **args);
void print_error(const char *error_message, const int exit_code);
char *read_user_input();
int get_token_count(char *user_entry);
char **tokenize(char *user_entry);
char *prepend_bin(char *command);
char *get_command(char *command);
int execute_command(char **arguments);
#endif
