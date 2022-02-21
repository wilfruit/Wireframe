#include "get_next_line.h"

size_t	ft_strlenmod(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchrmod(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlenmod(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_joinedmod(char *s1, char *s2, char *sjoined)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		sjoined[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		sjoined[i] = s2[j];
		i++;
		j++;
	}
	sjoined[i] = '\0';
	free (s1);
	return (sjoined);
}

char	*ft_strjoinmod(char *s1, char *s2)
{
	char	*sjoined;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	sjoined = malloc(sizeof(char) * (ft_strlenmod(s1) + ft_strlenmod(s2) + 1));
	if (!sjoined)
		return (NULL);
	return (sjoined = ft_joinedmod(s1, s2, sjoined));
}