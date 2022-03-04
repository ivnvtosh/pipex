#include "pipex_bonus.h"

void	child(t_cmd cmd, char **envp, int in, int out);

static void	child_one(t_data data)
{
	int		in;
	int		out;
	pid_t	child1;

	child1 = fork();
	if (child1 == -1)
	{
		terminate("child1");
	}
	if (child1 == 0)
	{
		in = open(data.in, O_RDONLY);
		if (in == -1)
			terminate("infile");
		out = open(data.out, O_WRONLY, O_TRUNC, O_CREAT, 0644);
		if (out == -1)
			terminate("outfile");
		child(data.cmd[0], data.envp, in, out);
	}
}

void	one(t_data data)
{
	int		cheak;

	child_one(data);
	wait(&cheak);
	if (cheak != 0)
		terminate("child");
}
