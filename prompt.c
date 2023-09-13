#include "main.h"
#include "getline.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		return (1);
	}

	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	char *line;

	while ((line = my_getline(fd)) != NULL)
	{
		printf("%s", line); /*print each line*/
		free(line);  /*Don't forget to free the memory allocated by my_getline*/
	}

	close(fd); /*close the file descriptor when done*/
	return (0);
}
