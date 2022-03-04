#include "pipex_bonus.h"

void	child(t_cmd cmd, char **envp, int in, int out);

static void	child_one(t_data data, int fifo[2])
{
	int		fd;
	pid_t	child1;

	child1 = fork();
	if (child1 == -1)
	{
		terminate("child1");
	}
	if (child1 == 0)
	{
		fd = open(data.in, O_RDONLY);
		if (fd == -1)
			terminate("infile");
		if (close(fifo[0]) == -1)
			terminate("fifo[0]");
		child(data.cmd[0], data.envp, fd, fifo[1]);
	}
}

static void	child_two(t_data data, int fifo[2])
{
	int		fd;
	pid_t	child2;

	child2 = fork();
	if (child2 == -1)
	{
		terminate("child2");
	}
	if (child2 == 0)
	{
		fd = open(data.out, O_WRONLY, O_TRUNC, O_CREAT, 0644);
		if (fd == -1)
			terminate("outfile");
		if (close(fifo[1]) == -1)
			terminate("fifo[1]");
		child(data.cmd[1], data.envp, fifo[0], fd);
	}
}

void	two(t_data data)
{
	int		cheak;
	int		fifo[2];

	if (pipe(fifo) == -1)
		terminate("pipe");
	child_one(data, fifo);
	child_two(data, fifo);
	if (close(fifo[0]) == -1)
		terminate("fifo[0]");
	if (close(fifo[1]) == -1)
		terminate("fifo[1]");
	wait(&cheak);
	if (cheak != 0)
		terminate("child");
	wait(&cheak);
	if (cheak != 0)
		terminate("child");
}
