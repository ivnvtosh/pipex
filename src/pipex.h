#ifndef PIPEX_H
# define PIPEX_H

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
	t_cmd	cmd1;
	t_cmd	cmd2;
}	t_data;

void	terminate(char *string);

#endif
