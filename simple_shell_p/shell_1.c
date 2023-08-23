#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 *
 * return: 0 (success)
 */
int main(void)
{
	char *prompt = "(SHELL)>$  ";
	char *buf_es = NULL;
	size_t size = 10;
	ssize_t get_read;

	while (1)
	{
	printf("%s", prompt);
	
	printf("bonjour ");
	getline(&buf_es, &size, stdin);

	get_read = getline(&buf_es, &size, stdin);

		if (get_read == -1 || EOF)
		{
			perror("getline");
			break;
		}
		printf(buf_es);
	}


	free(buf_es);
	return (0);
}
