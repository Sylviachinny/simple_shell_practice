#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: string to be searched
 * @c: character to be located
 * Return: pointer to the first occurence of the character c in the string
 */
char *_strchr(const char *s, int c)
{
	int e;

	for (e = 0; s[e] != '\0'; e++)
	{
		if (s[e] == c)
			return ((char *)(s + e));
	}
	return (NULL);
}

/**
 * str_pointer_break - breakes a string into tokens
 * @str1: string to be tokenized
 * @str2: delimiter
 * Return: pointer to the first occurrence of the delimiter
 */
char *str_pointer_break(char *str1, const char *str2)
{
	int e, q;

	for (e = 0; str1[e] != '\0'; e++)
	{
		q = 0;
		while (str2[q] != '\0')
		{
			if (str1[e] == str2[q])
			{
				return (str1 + e);
			}
			q++;
		}
	}
	return (NULL);
}

/**
 * _getenv - gets an environment variable
 * @name: name of the environment variable
 * Return: pointer to the value of the environment variable
 * or NULL if there is no match
 */
char *_getenv(const char *name)
{
	char **env;
	char *env_name, *delimeter;
	size_t name_len;

	if (name == NULL || name[0] == '\0')
		return (NULL);
	for (env = environ; *env != NULL; env++)
	{
		env_name = *env;
		delimeter = _strchr(env_name, '=');

		if (delimeter != NULL)
		{
			name_len = (size_t)(delimeter - env_name);
			if (_strlen(name) == name_len && _strncmp(env_name, name, name_len) == 0)
			{
				return (delimeter + 1);
			}
		}
	}
	return (NULL);
}

/**
 * _strcpy - copies the string pointed to by src to dest
 * @dest: destination string
 * @src: source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int e;

	for (e = 0; src[e] != '\0'; e++)
		dest[e] = src[e];
	dest[e] = src[e];
	return (dest);
}

/**
 * _strlen - returns the length of string
 * @s: string to be  measured
 * Return: length of the string
 */
size_t _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}
