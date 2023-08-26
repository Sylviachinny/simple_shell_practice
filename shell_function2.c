#include "main.h"

/**
 * check_working_dir - checks the working directory
 * @pwd: present working directory
 * @path: path
 * Return: path
 */
char *check_working_dir(char **pwd, char **path)
{
	char *str = NULL;

	if (**path == ':')
	{
		str = malloc(sizeof(char) * (_strlen(*pwd) + _strlen(*path) + 1));
		if (str == NULL)
		{
			free_all(2, *pwd, *path);
			return (NULL);
		}
		_strcpy(str, *pwd), _strcat(str, *path);
	}
	else if (_strstr(*path, "::") != NULL)
	{
		str = path_convert(*pwd, *path);
		if (str == NULL)
		{
			free_all(2, *pwd, *path);
			return (NULL);
		}
	}
	else
	{
		str = malloc(sizeof(char) * (_strlen(*path) + 1));
		if (str == NULL)
		{
			free_all(2, *pwd, *path);
			return (NULL);
		}
		_strcpy(str, *path);
	}
	return (str);
}

/**
 * path_convert - converts the path
 * @pwd: presents the working directory
 * @path: path
 * Return: path
 */
char *path_convert(char *pwd, char *path)
{
	int index, k = 0, n = 0;
	char *str;

	if (pwd == NULL || path == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (_strlen(pwd) + _strlen(path) + 1));
	if (str == NULL)
		return (NULL);
	for (index = 0; path[index] != '\0'; index++)
	{
		if (path[index] == ':' && path[index + 1] == ':')
		{
			str[n++] = ':';
			while (path[k])
			{
				str[n] = pwd[k];
				n++, k++;
			}
			str[n] = ':';
			while (path[index] == ':')
				index++;
			index--;
		}
		else
			str[n] = str[index];
		index++;
		n++;
	}
	str[n] = '\0';
	return (str);
}
