#include "main.h"
#include "getline.h"

/**
 * printerror - prints error message
 * @av_es: name of the program
 * @count: number of commands entered
 * @arg_es: command entered
 * Return: void
 */
void printerror(char **av_es, int count, char **arg_es)
{
	write(STDERR_FILENO, av_es[0], _strlen(av_es[0]));
	write(STDERR_FILENO, ": ", 2);
	write_error_stderr(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, arg_es[0], _strlen(arg_es[0]));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * prompt - prompts the user for input
 * @buf_es: buffer to store input
 * Return: number of bytes read
 */
int prompt(char **buf_es)
{
	ssize_t nread = 0;
	size_t size = 0;
	int is_interactive = isatty(STDIN_FILENO);

	if (is_interactive != 0)
		write(STDOUT_FILENO, "my_shell$ ", 10);
	nread = my_getline(buf_es, &size, stdin)
		return (nread);
}

/**
 * handle_ctrl_c - handles ctrl + c signal
 * @sig: signal
 */
void handle_ctrl_c(int sig __attribute__((unused)))
{
	write(1, "\nmy_shell$ ", 12);
	signal(SIGINT, handle_ctrl_c);
}

/**
 * free_all - frees all memory
 * @n: number of arguments
 * Return: void
 */
void free_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *ptr;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		ptr = va_arg(args, char *);
		free(ptr);
	}
	va_end(args);
}

/**
 * free_arg - frees an arraynof strings
 * @arr: array of strings
 */
void free_arg(char **arr)
{
	free(arr);
}
