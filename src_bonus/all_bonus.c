#include "pipex_bonus.h"

void	child(t_cmd cmd, char **envp, int in, int out);

static void	child_first(t_cmd cmd, char **envp, char *in, int fifo[2])
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
		fd = open(in, O_RDONLY);
		if (fd == -1)
			terminate("infile");
		if (close(fifo[0]) == -1)
			terminate("fifo[0]");
		child(cmd, envp, fd, fifo[1]);
	}
}


static void	child_n(t_cmd cmd, char **envp, int in[2], int out[2])
{
	pid_t	childn;

	childn = fork();
	if (childn == -1)
	{
		terminate("childn");
	}
	if (childn == 0)
	{
		if (close(in[1]) == -1)
			terminate("fifo_in[0]");
		if (close(out[0]) == -1)
			terminate("fifo_out[1]");
		child(cmd, envp, in[0], out[1]);
	}
}

static void	child_last(t_cmd cmd, char **envp, int fifo[2], char *out)
{
	int		fd;
	pid_t	childlast;

	childlast = fork();
	if (childlast == -1)
	{
		terminate("childlast");
	}
	if (childlast == 0)
	{
		fd = open(out, O_WRONLY, O_TRUNC, O_CREAT, 0644);
		if (fd == -1)
			terminate("outfile");
		if (close(fifo[1]) == -1)
			terminate("fifo[1]");
		child(cmd, envp, fifo[0], fd);
	}
}

void	ft_close_fifo(int *fifo)
{
	if (close(fifo[0]) == -1)
		terminate("fifo[0]");
	if (close(fifo[1]) == -1)
		terminate("fifo[1]");
}

void	all(t_data data)
{
	int		cheak;
	int		fifo_one[2];
	int		fifo_two[2];
	int		i;

	if (pipe(fifo_one) == -1)
		terminate("pipe one");
	child_first(data.cmd[0], data.envp, data.in, fifo_one);
	i = 0;
	while (i < data.count - 2)
	{
		if (i % 2 == 0)
		{
			if (pipe(fifo_two) == -1)
				terminate("pipe two");
			child_n(data.cmd[i + 1], data.envp, fifo_one, fifo_two);
			ft_close_fifo(fifo_one);
		}
		else
		{
			if (pipe(fifo_one) == -1)
				terminate("pipe one");
			child_n(data.cmd[i + 1], data.envp, fifo_two, fifo_one);
			ft_close_fifo(fifo_two);
		}
		i += 1;
	}
	if (i % 2 == 0)
	{
		child_last(data.cmd[i + 1], data.envp, fifo_one, data.out);
		ft_close_fifo(fifo_one);
	}
	else
	{
		child_last(data.cmd[i + 1], data.envp, fifo_two, data.out);
		ft_close_fifo(fifo_two);
	}


	i = 0;
	while (i < data.count)
	{
		wait(&cheak);
		if (cheak != 0)
			terminate("child");
		i += 1;
	}
}
