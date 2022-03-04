#include "pipex_bonus.h"

void	pipex(int count, char **parameters, char **envp);

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 4)
		pipex(--argc, ++argv, envp);
	return (0);
}
