#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i += 1;
	return (i);
}

void	ft_putstr_fd(const char *string, int fd)
{
	if (string == NULL)
		return ;
	write(fd, string, ft_strlen(string));
}

int	ft_strncmp(const char *string_1, const char *string_2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	n -= 1;
	i = 0;
	while (i < n && string_1[i] == string_2[i] && string_1[i])
		i += 1;
	return ((unsigned char)string_1[i] - (unsigned char)string_2[i]);
}

void	ft_strcpy(const char *string_from, char *string_in)
{
	size_t	i;

	i = 0;
	while (string_from[i] != '\0')
	{
		string_in[i] = string_from[i];
		i += 1;
	}
	string_in[i] = '\0';
}

char	*ft_strjoin(char const *string_1, char const *string_2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (string_1 == NULL || string_2 == NULL)
		return (NULL);
	i = ft_strlen(string_1);
	j = ft_strlen(string_2);
	new = (char *)malloc(sizeof(char) * (i + j + 1));
	if (new == NULL)
		return (NULL);
	ft_strcpy(string_1, new);
	ft_strcpy(string_2, new + i);
	new[i + j] = '\0';
	return (new);
}
