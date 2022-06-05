/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:07:01 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/02 19:18:37 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*nee == 0)
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		if (hay[i] == *nee)
		{
			j = 1;
			while (hay[i + j] && hay[i + j] == nee[j] && (i + j) < len)
				++j;
			if (nee[j] == 0)
				return ((char *)(hay + i));
		}
		i++;
	}
	return (NULL);
}
