#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
void free_args(char **args, int token_count);
void print_error(const char *error_message, const int exit_code);
char *read_user_input();
int get_token_count(char *user_entry);
int quote_checker(char *token, int position);
char **tokenize(char *user_entry);
char *get_command(char *command);
int execute_command(char **arguments);
#endif
