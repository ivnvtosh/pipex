#include <stdlib.h>

size_t	ft_strlen(const char *string);

void	ft_strlcpy(const char *string_from, char *string_in, size_t length)
{
	size_t	i;

	if (length == 0)
		return ;
	length -= 1;
	i = 0;
	while (i < length && string_from[i] != '\0')
	{
		string_in[i] = string_from[i];
		i += 1;
	}
	string_in[i] = '\0';
}

char	*ft_substr(char const *string, size_t start, size_t length)
{
	char	*new;
	size_t	i;

	i = ft_strlen(string);
	if (i < length)
		length = i - start;
	if (start >= i)
		length = 0;
	new = (char *)malloc(sizeof(char) * (length + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(&string[start], new, length + 1);
	return (new);
}

static char	**ft_wordcount(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s != c)
			count++;
		while (*s != c && *s != '\0')
			s++;
		while (*s == c && *s != '\0')
			s++;
	}
	return ((char **)malloc(sizeof(char *) * (count + 1)));
}

static int	ft_function(char const *s, char c, char **p)
{
	int	slen;

	while (*s)
	{
		while (*s == c && *s != '\0')
			s++;
		slen = 0;
		while (s[slen] != c && s[slen] != '\0')
			slen++;
		if (slen != 0)
		{
			*p = ft_substr(s, 0, slen);
			if (*p == NULL)
				return (1);
			p++;
			s = s + slen;
		}
	}
	*p = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		e;

	if (s == NULL)
		return (NULL);
	p = ft_wordcount(s, c);
	if (p == NULL)
		return (NULL);
	e = ft_function(s, c, p);
	if (e == 1)
	{
		while (*p)
			free(*p++);
		free(p);
		return (NULL);
	}
	return (p);
}
