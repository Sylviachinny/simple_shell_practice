#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest_a: destination sting
 * @src: source string
 * Return: pointer to the resulting string destination
 */
char *_strcat(char *dest_a, const char *src)
{
	int e, length = _strlen(dest_a);

	for (e = 0; src[e] != '\0'; e++)
		dest_a[length + e] = src[e];
	dest_a[length + e] = src[e];
	return (dest_a);
}

/**
 * _putenv - adds or changes the value of an environment variables
 * @string: string of the form name=value
 * Return: 0 on success, 1 on failure
 */
int _putenv(char *string)
{
	int y;
	char *delimeter, **new_environ;

	delimeter = _strchr(string, '=');
	if (string == NULL || delimeter == NULL || delimeter == string)
	{
		write(STDERR_FILENO, "Error: invalid argument\n", 24);
		return (1);
	}
	for (y = 0; environ[y] != NULL; y++)
	{
		if (_strncmp(string, environ[y], delimeter - string + 1) == 0)
		{
			environ[y] = string;
			return (0);
		}
	}
	while (environ[y] != NULL)
		y++;
	new_environ = malloc(sizeof(char *) * (y + 2));
	if (new_environ == NULL)
	{
		perror("malloc");
		return (1);
	}
	for (y = 0; environ[y] != NULL; y++)
		new_environ[y] = environ[y];
	new_environ[y] = string;
	new_environ[y + 1] = NULL;
	environ = new_environ;
	return (0);
}

/**
 * _strcmp - function that compare two string
 * @s1: The first string to compare
 * @s2: The second string to compare
 * Return: s1 - s2
 */
int _strcmp(char *s1, char *s2)
{
	int e;

	for (e = 0; s1[e] && s2[e]; e++)
	{
		if (s1[e] != s2[e])
		{
			return (s1[e] - s2[e]);
		}
	}
	return (s1[e] - s2[e]);
}

/**
 * _strncmp - compare two strings
 * @s1_es: first string
 * @s2_es: Second string
 * @n: number of bytes to be compared
 * Return: difference between the two strings
 */
int _strncmp(const char *s1_es, const char *s2_es, size_t n)
{
	while (n > 0)
	{
		if (*s1_es == '\0' && *s2_es == '\0')
		{
			return (0);
		}
		else if (*s1_es == *s2_es)
		{
			s1_es++;
			s2_es++;
			n--;
		}
		else
		{
			return (*s1_es - *s2_es);
		}
	}
	return (0);
}

/**
 * _isspace - checks for white space characters
 * @c: character to be checked
 * Return: 1 if c is a white-space character, 0 otherwise
*/
int _isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r');
}
