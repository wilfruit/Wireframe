/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:46:18 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/07 11:38:55 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strndup(const char *src, size_t size)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	i = 0;
	while (i < size && src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_word_counter(const char *str, char c)
{
	int	wc;
	int	i;	

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			wc++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (wc);
}

int	ft_char_counter(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	**ft_core(char **ultab, int j, char const *s, char c)
{	
	unsigned int	i;

	i = 0;
	while (j < ft_word_counter(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		ultab[j] = ft_strndup(&s[i], ft_char_counter(&s[i], c));
		if (ultab[j] == NULL)
		{
			while (j >= 0)
			{
				free(ultab[j]);
				j--;
			}
			free(ultab);
			return (0);
		}
		i = i + ft_char_counter(&s[i], c);
		j++;
	}
	ultab[j] = 0;
	return (ultab);
}

char	**ft_split(char const *s, char c)
{
	int				j;
	char			**ultab;

	j = 0;
	if (!s)
		return (NULL);
	ultab = malloc(sizeof(char *) * (ft_word_counter(s, c) + 1));
	if (!ultab)
		return (NULL);
	ultab = ft_core(ultab, j, s, c);
	if (!ultab)
		return (NULL);
	return (ultab);
}
