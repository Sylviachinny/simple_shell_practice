#include "main.h"

/**
 * is_empty - checks if a string is empty
 * @str: string to check 
 * Return: true if empty, false if not
 */
bool is_empty(const char *str)
{
	while (*str != '\0')
	{
		if (!_isspace(*str))
		{
			return (false);
		}
		str++;
	}
	return (true);
}

/**
 * print_prompt - prints the prompt
 * @is_interactive: checks if the shell is interactive
 * Return: void
 */
void print_prompt(int is_interactive)
{
	if (isatty(is_interactive))
	{
		write(STDOUT_FILENO, "my_shell$ ", 10);
	}
}
