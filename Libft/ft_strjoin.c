/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:33:44 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/07 19:07:04 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_emptystring(size_t size)
{
	char	*str;

	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

char	*ft_joined(char const *s1, char const *s2, char *sjoined)
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
	return (sjoined);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*sjoined;

	if (!s1 || !s2)
		return (NULL);
	sjoined = ft_emptystring(ft_strlen(s1) + ft_strlen(s2));
	if (!sjoined)
		return (NULL);
	return (sjoined = ft_joined(s1, s2, sjoined));
}
