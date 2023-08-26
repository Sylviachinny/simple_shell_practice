#ifndef MAIN_H
#define MAIN_H

/*Libraries*/
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdarg.h>

/*macros*/
#define DIR_SIZE 1024
#define IN 1
#define OUT 0

/*prototypes*/
void exec(char **arg_es, char **arg, char *buf_es, int count);
void *handle_path(char *cmd);
void check_builtin(char **av,, char *buf_es, __attribute__((unused)), int count);
void print_env(void);
void *handle_path(char *cmd);
void shell_env(void);
void handle_ctrl_c(int sig __attribute__((unused)));
void free_all(const unsigned int n, ...);
void free_arg(char **arr);
char *_strchr(const char *s, int c);
char *str_pointer_break(char *str1, const char *str2);
char *_getenv(const char *name);
char *_strcat(char *dest_a, const char *src);
char **argument_separator(char *buf_es, char *separator);
size_t _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
int _putenv(char *string);
int prompt(char ** buf_es);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1_es, const char *s2_es, size_t n);
int _isspace(int c);
bool is_empty(const char *str);
int main(int argc_es, __attribute__((unused)), char **av_es);
void print_prompt(int is_interactive);

/*global variables*/
extern char **environ;
/*strtok struct declaration*/

/**
 * struct s_strtok - strtok struct
 * @current: current position of the string
 * Description: tokenizes a string
 */
typedef struct
{
	char *current;
}
s_strtok;

/*strtok function*/
char *my_token(char *str, const char *delim);
/*setenv function*/
int _setenv(const char *name, const char *value);
/*Unsetenv function*/
int _unsetenv(const char *name);
/*change directory*/
char *check_working_dir(char **pwd, char **path);
char *path_convert(char *pwd, char *path);
/*Handle child function*/
void handle_child(char *line_copy, char **arg_es, int token_count);
/*handle builtin command*/
int handle_builtin_command(char *command_exec, char **argu);
/*handle path conversion*/
char *path_convert(const char *path, const char *cmd);
/*Helper function for cd*/
int cmd_helper(char *current_direc, const char *dir);
int change_direc(const char *dir);
int get_working_dir(const char *dir);
int simple_shell_loop(char **argv, int count);



#endif/*MAIN_H*/
