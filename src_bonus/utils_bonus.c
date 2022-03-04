#include "pipex_bonus.h"

void	ft_free(char **pointer);

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

void	ft_free(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i] != NULL)
		free(pointer[i++]);
	free(pointer);
}

void	ft_ft_free(int count, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_free(cmd[i].argv);
		free(cmd[i].file);
		i += 1;
	}
	free(cmd);
}
