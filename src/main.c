#include "pipex.h"

void	pipex(char **parameters, char **envp);

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (1);
	pipex(++argv, envp);
	return (0);
}
