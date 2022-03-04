#include "pipex.h"

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

void	child(t_cmd cmd, char **envp, int in, int out)
{
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	if (close(in) == -1)
		terminate("in");
	if (close(out) == -1)
		terminate("out");
	execve(cmd.file, cmd.argv, envp);
	terminate(cmd.argv[0]);
}
