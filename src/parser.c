#include "pipex.h"

static char	**get_paths(char **envp)
{
	char	**paths;

	while (*envp != NULL && ft_strncmp(*envp, "PATH", 4))
		envp++;
	if (*envp == NULL)
		terminate("invalid envp");
	paths = ft_split(*envp + 5, ':');
	if (paths == NULL)
		terminate("envp");
	return (paths);
}

static char	*search_path(char *bin, char **paths)
{
	char	*temp;
	char	*temp1;

	temp = NULL;
	while (access(temp, 0) == -1 && *paths != NULL)
	{
		free(temp);
		temp1 = ft_strjoin("/", bin);
		if (temp1 == NULL)
			return (NULL);
		temp = ft_strjoin(*paths++, temp1);
		if (temp == NULL)
			return (NULL);
		free(temp1);
	}
	if (*paths == NULL)
		return (NULL);
	return (temp);
}

static t_cmd	get_cmd(char *command, char **paths)
{
	t_cmd	cmd;

	cmd.argv = ft_split(command, 32);
	if (cmd.argv == NULL)
		terminate("argv");
	cmd.file = search_path(cmd.argv[0], paths);
	if (cmd.file == NULL)
	{
		ft_putstr_fd(cmd.argv[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(1);
	}
	return (cmd);
}

void	ft_free(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i] != NULL)
		free(pointer[i++]);
	free(pointer);
}

t_data	parser(char **parameters, char **envp)
{
	t_data	data;
	char	**paths;

	data.in = parameters[0];
	data.out = parameters[3];
	data.envp = envp;
	paths = get_paths(envp);
	data.cmd1 = get_cmd(parameters[1], paths);
	data.cmd2 = get_cmd(parameters[2], paths);
	ft_free(paths);
	return (data);
}
