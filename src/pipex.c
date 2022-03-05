#include "pipex.h"

t_data	parser(char **parameters, char **envp);
void	child(t_cmd cmd, char **envp, int in, int out);

void	child_one(t_data data, int fifo[2])
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
		child(data.cmd1, data.envp, fd, fifo[1]);
	}
}

void	child_two(t_data data, int fifo[2])
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
		fd = open(data.out, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
			terminate("outfile");
		if (close(fifo[1]) == -1)
			terminate("fifo[1]");
		child(data.cmd2, data.envp, fifo[0], fd);
	}
}

void	ft_free(char **pointer);

void	child_only(t_data data, int fifo[2])
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
		child(data.cmd2, data.envp, fifo[0], fd);
	}
}

static void	one(t_data data)
{
	int	cheak;	
	int	fd;
	int	fifo[2];

	fd = open(data.in, O_RDONLY);
	if (fd != -1)
	{
		if (close(fd) == -1)
			terminate("fifo[1]");
		return ;
	}
	fifo[0] = 0; 
	child_only(data, fifo);
	wait(&cheak);
	// if (cheak != 0)
	// 	terminate("child");
	ft_free(data.cmd1.argv);
	ft_free(data.cmd2.argv);
	free(data.cmd1.file);
	free(data.cmd2.file);
	exit(0);
}

void	pipex(char **parameters, char **envp)
{
	t_data	data;
	int		cheak;
	int		fifo[2];

	data = parser(parameters, envp);
	one(data);
	if (pipe(fifo) == -1)
		terminate("pipe");
	child_one(data, fifo);
	child_two(data, fifo);
	if (close(fifo[0]) == -1)
		terminate("fifo[0]");
	if (close(fifo[1]) == -1)
		terminate("fifo[1]");
	wait(&cheak);
	// if (cheak != 0)
	// 	terminate("child");
	wait(&cheak);
	// if (cheak != 0)
	// 	terminate("child");
	ft_free(data.cmd1.argv);
	ft_free(data.cmd2.argv);
	free(data.cmd1.file);
	free(data.cmd2.file);
}
