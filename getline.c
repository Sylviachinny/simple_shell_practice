#include "getline.h"

/**
 * init_buffer - initialize buffer
 * @buf_es: buffer
 * @size: size of buffer
 * Return: void
 */
void init_buffer(char **buf_es, size_t *size)
{
	*buf_es = malloc(READ_SIZE);
	if (*buf_es == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	*size = READ_SIZE;
}

/**
 * read_into_buffer - read into buffer
 * @buf_es: buffer
 * @length: length of buffer
 * @stream: stream
 * Return: ssize_t
 */
ssize_t read_into_buffer(char *buf_es, size_t length, FILE *stream)
{
	ssize_t read;

	read = read(fileno(stream), buf_es, length);

	if (read == -1)
	{
		perror("read");
		return (-1);
	}
	return (read);
}

/**
 * expand_buffer - expand buffer
 * @buf_es: buffer
 * @length: length of buffer
 * Return: void
 */
void expand_buffer(char **buf_es, size_t *length)
{
	char *new_buf_es;

	new_buf_es = realloc(*buf_es, length + READ_SIZE_INCREMENT);

	if (new_buf_es == NULL)
	{
		perror("realloc");
		free(*buffer);
		exit(EXIT_FAILURE);
	}
	*buffer = new_buf_es;
	*length += READ_SIZE_INCREMENT;
}

/**
 * perform_getline - perform getline
 * @buf_es: buffer
 * @len: length of buffer
 * @index: index
 * @r: read
 * Return: ssize_t
 */
ssize_t perform_getline(char *buf_es, size_t len, size_t *index, ssize_t r)
{
	size_t char_read = 0;
	size_t total_r;

	total_r = r;
	*index = 0;

	while (*index < total_r && r != 0)
	{
		if (buf_es[*index] == '\n')
		{
			buf_es[*index] = '\0';
			return (char_read);
		}

		if (*index == len - 1)
		{
			expand_buffer(&buf_es, &len);
		}

		(*index)++;
		char_read++;
	}

	*index = 0;
	total_r = 0;

	return (char_read);
}

/**
 * my_getline - get line
 * @buf_es: buffer
 * @length: length of buffer
 * @stream: stream
 * Return: ssize_t
 */
ssize_t my_getline(char **buf_es, size_t *length, FILE *stream)
{
	static size_t index;
	ssize_t read, char_read = 0;

	if (buf_es == NULL || *length == 0)
	{
		init_buffer(buf_es, len);
	}

	fflush(stdout);
	read = read_into_buffer(*buffer, *length, stream);
	if (read == 0)
	{
		free(*buf_es);
		*buf_es = NULL;
		*length = 0;
		return (-1);
	}
	char_read = perform_getline(*buf_es, *length, &index, read);
	return (char_read);
}
