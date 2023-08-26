#include "main.h"
#include "getline.h"

/**
 * main - main function
 * @argc_es: number of arguments
 * @av_es: arguments
 * @__attribute__((unused)): unused  variable
 * Return: 0 on success, 1 on failure
 */
int main(int argc_es, __attribute__((unused)), char **av_es)
{
	int count = 0, status, ret_val;
	pid_t child;

	signal(SIGINT, handle_ctrl_c);

	while (1)
	{
		ret_val = simple_shell_loop(av_es, count);
		if (ret_val == 2)
		{
			count++;
			child = fork();

			if (child == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			else if (child != 0)
			{
				wait(&status);
				return (127);
			}
			else
				continue;
		}
		if (ret_val != 0)
			break;
		count++;
	}
	return (0);
}
