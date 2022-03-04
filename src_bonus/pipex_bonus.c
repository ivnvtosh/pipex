#include "pipex_bonus.h"

t_data	parser(int count, char **parameters, char **envp);
void	one(t_data data);
void	two(t_data data);
void	all(t_data data);
void	ft_ft_free(int count, t_cmd *cmd);

void	pipex(int count, char **parameters, char **envp)
{
	t_data	data;

	data = parser(count, parameters, envp);
	if (data.count == 1)
		one(data);
	else if (data.count == 2)
		two(data);
	else if (data.count >= 3)
		all(data);
	ft_ft_free(data.count, data.cmd);
}
