#include "main.h"

/***********MY_TOKEN FUNCTION************/
/**
 * my_token - tokenizes a string
 * @str: string to tokenize
 * @delim: delimeter
 * Return: pointer to the next token
 */
char *my_token(char *str, const char *delim)
{
	static s_strtok my_strtok;
	char *start, *end;

	if (str != NULL)
		my_strtok.current = str;

	if (my_strtok.current == NULL || *(my_strtok.current) == '\0')
		return (NULL);/*no more tokens*/
	while (*(my_strtok.current) != '\0'
			&& _strchr(delim, *(my_strtok.current)) != NULL)
		(my_strtok.current)++; /*skip delimiters*/
	if (*(my_strtok.current) == '\0')
		return (NULL); /*no more token*/

	start = my_strtok.current;
	end = str_pointer_break(start, delim);

	if (end != NULL)
	{
		*end = '\0';
		my_strtok.current = end + 1; /*move current to the next token*/
	}
	else
	{
		my_strtok.current = NULL;
	}
	return (start);
}

/**
 * exec - executes a command
 * @arg_es: array of arguments
 * @arg: arguments
 * @buf_es: buffer
 * @count: number of commands
 * Return: 0 0n success, 1 on failure
 */
void exec(char **arg_es, char **arg, char *buf_es, int count)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(arg[0], arg, environ) == -1)
		{
			printerror(arg_es, count, arg);
			free_all(1, buf_es);
			free_arg(arg);
			exit(98);
		}
	}
	else if (pid < 0)
	{
		printerror(arg_es, count, arg);
		free_all(1, buf_es);
		return (1);
	}
	else
	{
		wait(&status);
	}
	return (status);
}

/**
 * handle_path - handles the path
 * @cmd: command
 * Return: pointer to the path
 */
void *handle_path(char *cmd)
{
	char **arr = NULL, *path, *pwd, *str, *dir;
	unsigned int b = 0, c = 0, length = 0;
	struct stat st;

	if (cmd != NULL)
		return (NULL);
	pwd = _strdup(_getenv("PWD"));
	if (pwd == NULL)
		return (NULL);
	path = path_initialize(&pwd);
	if (path == NULL)
		return (NULL);
	str = check_working_dir(&pwd, &path), b = c = 0;
	arr = argument_separator(str, ":");
	if (arr == NULL)
		return (NULL);
	while (arr[b])
	{
		length = _strlen(arr[b]) + _strlen(*cmd) + 2;
		dir = malloc(sizeof(char) * length);
		if (dir == NULL)
		{
			free_all(3, str, path, pwd), free_arg(arr);
			return (NULL);
		}
		_strcpy(dir, arr[b]), _strcat(dir, "/"), _strcat(dir, *cmd);
		if (stat(dir, &st) == 0)
		{
			*cmd = _strdup(dir);
			if (*cmd == NULL)
			{
				free_all(4, str, path, pwd, dir), free_arg(arr);
				return (NULL);
			}
			free_all(4, dir, str, path, pwd), free_arg(arr);
			return (*cmd);
		}
		free_all(1, dir), b++, c = 0;
	}
	free_all(3, str, path, pwd), free_arg(arr);
	return (NULL);
}

/**
 * simple_shell_loop - runs the shell loop
 * @argv: array of arguments
 * @count: number of commands
 * Return: 0 on success, 1 on failure
 */
int simple_shell_loop(char **argv, int count)
{
	char *buff = NULL, **args = NULL;
	ssize_t val;

	if (prompt(&buf_es) == -1)
	{
		free_all(1, buff);
		return (1);
	}
	args = argument_separator(buff, " ;"), count++;
	if (arg[0] == NULL)
	{
		free_all(1, buf_es), free_arg(args);
		return (1);
	}
	if (args[0][0] != '/' && args[0][0] != '.')
	{
		val = check_builtin(args, buf_es, count);
		if (val == 0 || val == 2)
		{
			free_all(1, buf_es), free_arg(args), val == 0 ? (val = 0) : (val = 1);
			return (val);
		}
		if (!(handle_path(&args[0])))
		{
			printerror(argv, count, args), free_all(1, buff), free_arg(args);
			return (2);
		}
		else
		{
			exec(argv, args, buf_es, count), free_all(2, *args, buf_es), free_arg(args);
			return (0);
		}
	}
	if (exec(argv, args, buf_es, count) == 0)
	{
		free_all(1, buf_es), free_arg(args);
		return (2);
	}
	free_all(1, buf_es), free_arg(args);
	return (0);
}

/**
 * argument_separator - separates the arguments
 * @buf_es: buffer
 * @separator: separator
 * return: pointer to the array of arguments
 */
char **argument_separator(char *buf_es, char *separator)
{
	char **arr = NULL, *token;
	int b = 0, length;

	if (buf_es == NULL || separator == NULL)
		return (NULL);
	length = word_counter(buf_es, separator);
	arr = malloc(sizeof(char *) * (length + 1));
	if (arr == NULL)
		return (NULL);
	token = my_token(buf_es, separator);

	while (token != NULL)
	{
		if (token[0] == '\n')
			break;
		arr[b++] = token;
		token = my_token(NULL, separator);
	}
	return (arr);
}
