#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "../libgnl/libgnl.h"

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_cmd
{
	char	**argv;
	char	*file;
}	t_cmd;

typedef struct s_data
{
	char	*in;
	char	*out;
	char	**envp;
	int		count;
	t_cmd	*cmd;
}	t_data;

void	terminate(char *string);

#endif
