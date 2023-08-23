#include "main.h"
/**
 * shell_exit - exits the shell
 * @exit_the_shell: string to compare with exit
 * @arg_es: arguments
 * Return: void
 */
void shell_exit(char *exit_the_shell, char *arg_es)
{
	int status;

	if (strcmp(exit_the_shell, "exit") == 0)
	{
		if (arg_es != NULL)
		{
			status = atoi(arg_es);
		}
		else
		{
			status = 0;
		}
		exit(status);
	}
}

/**
 * shell_env - prints the environment
 * Return: void
 */
void shell_env(void)
{
	int z = 0;

	while (environ[z] != NULL)
	{
		write(STDOUT_FILENO, environ[z], strlen(environ[z]));
		write(STDOUT_FILENO, "\n", 1);
		z++;
	}
}

/**
 * _setenv - sets an environment variable
 * @name: name of the variable
 * @value: value of the variable
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value)
{
	int length = 0;
	char *new_string = NULL;

	length = _strlen(name) + _strlen(value) + 2;
	new_string = malloc(sizeof(char) * length);

	if (new_string == NULL)
	{
		write(STDERR_FILENO, "Error: malloc failed\n", 21);
		return (-1);
	}

	_strcpy(new_string, name);
	_strcat(new_string, "=");
	_strcat(new_string, value);

	/*inilialze a new environment or modify existing one*/
	if (_putenv(new_string) != 0)
	{
		write(STDERR_FILENO, "Error: _putenv failed\n", 21);
		free(new_string);
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - unsets an environment variable
 * @name: name of the variable
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	int z, q, length = 0;
	int environ_len = 0, found = 0;
	char **new_environ = NULL;

	length = _strlen(name);
	while (environ[environ_len] != NULL)
		environ_len++;

	for (z = 0; environ[z] != NULL; z++)
	{
		if (strncmp(environ[z], name, length) == 0)
		{
			found = 1;
			free(environ[z]);
			for (q = z; environ[q] != NULL; q++)
				environ[q] = environ[q + 1];
			environ_len--;
			break;
		}
	}

	/*if not found return 0*/
	if (found == 0)
		return (0);
	new_environ = malloc(sizeof(char *) * (environ_len + 1));
	if (new_environ == NULL)
	{
		write(STDERR_FILENO, "Error: malloc- failed\n", 21);
		return (-1);
	}

	for (z = 0; environ[z] != NULL; z++)
		new_environ[z] = environ[z];
	new_environ[z] = NULL;

	free(environ);
	environ = new_environ;
	return (0);
}
