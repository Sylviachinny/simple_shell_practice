#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * return: 0
 */
int main(void)
{
	char *prompt = "(SHELL)$ ";
	char *buffer = NULL;
	size_t size = 0;
	ssize_t num_input;
	char * arg_getline[] = {"/bin/ls", "-l", NULL};
	int execve_RV = 10;

	while (1)
	{

	printf("%s\n", prompt);
       	getline(&buffer, &size, stdin);
	num_input = getline(&buffer, &size, stdin);
	if (num_input == -1)
	{
		printf("let's exit====\n");
		break;
	}
	/*printf("buffer");*/

	printf("the start of calling execve\n");
	execve_RV = execve("/bin/ls", arg_getline, NULL);
	if (execve_RV == -1)
	{
		perror("ERROR OCCURED==");
		break;
	}
	printf("Execve has been called\n");
	}
	free(buffer);

	return (0);
}
