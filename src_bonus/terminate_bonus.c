#include "pipex_bonus.h"

void	terminate(char *string)
{
	if (string == NULL)
	{
		exit(0);
	}
	else
	{
		perror(string);
		exit(1);
	}
}
