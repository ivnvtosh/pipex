#include <stdlib.h>

void	ft_free(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i] != NULL)
		free(pointer[i++]);
	free(pointer);
}
