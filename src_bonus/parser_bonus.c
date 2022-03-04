#include "pipex_bonus.h"

void	ft_free(char **pointer);

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

static t_cmd	*get_cmd(int count, char **command, char **paths)
{
	t_cmd	*cmd;
	int		i;

	cmd = (t_cmd *)malloc(count * sizeof(t_cmd));
	if (cmd == NULL)
		terminate("cmd");
	i = 0;
	while (i < count)
	{
		cmd[i].argv = ft_split(command[i], 32);
		if (cmd[i].argv == NULL)
			terminate("argv");
		cmd[i].file = search_path(cmd[i].argv[0], paths);
		if (cmd[i].argv == NULL)
			terminate("file");
		i += 1;
	}
	return (cmd);
}

t_data	parser(int count, char **parameters, char **envp)
{
	t_data	data;
	char	**paths;

	data.in = parameters[0];
	data.out = parameters[count - 1];
	data.envp = envp;
	paths = get_paths(envp);
	data.count = count - 2;
	data.cmd = get_cmd(data.count, &parameters[1], paths);
	ft_free(paths);
	return (data);
}
