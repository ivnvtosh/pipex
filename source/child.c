/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 20:01:04 by ccamie            #+#    #+#             */
/*   Updated: 2022/03/07 20:20:53 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**get_argv(char *command)
{
	char	**argv;

	argv = ft_split(command, 32);
	if (argv == NULL)
	{
		perror("argv = ft_split(command, 32)");
		exit(1);
	}
	return (argv);
}

static char	**get_path(char **envp)
{
	char	**path;

	while (*envp != NULL && ft_strncmp(*envp, "PATH", 4))
		envp++;
	if (*envp == NULL)
	{
		ft_putstr_fd("invalid envp\n", 2);
		exit(1);
	}
	path = ft_split(*envp + 5, ':');
	if (path == NULL)
	{
		perror("path = ft_split(*envp + 5, ':')");
		exit(1);
	}
	return (path);
}

static char	*filejoin(char *command, char *path)
{
	char	*temp;
	char	*file;

	temp = ft_strjoin(path, "/");
	if (temp == NULL)
	{
		perror("temp1 = ft_strjoin(*path++, \"/\")");
		exit(1);
	}
	file = ft_strjoin(temp, command);
	if (file == NULL)
	{
		perror("file = ft_strjoin(temp1, command)");
		exit(1);
	}
	free(temp);
	return (file);
}

static char	*get_file(char *command, char **envp)
{
	char	**path;
	int		i;
	char	*file;

	if (access(command, 0) == 0)
		return (command);
	path = get_path(envp);
	i = 0;
	file = NULL;
	while (access(file, 0) == -1 && path[i] != NULL)
	{
		free(file);
		file = filejoin(command, path[i++]);
	}
	if (access(file, 0) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	ft_free(path);
	return (file);
}

void	child(char *command, char **envp, int in, int out)
{
	char	**argv;
	char	*file;

	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	if (close(in) == -1)
	{
		perror("if (close(in) == -1)");
		exit(1);
	}
	if (close(out) == -1)
	{
		perror("if (close(out) == -1)");
		exit(1);
	}
	argv = get_argv(command);
	file = get_file(*argv, envp);
	execve(file, argv, envp);
	perror("execve(file, argv, envp)");
	exit(1);
}
