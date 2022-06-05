/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:09:29 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/01 17:25:57 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*cpy;
	int		len;

	len = ft_strlen(s);
	i = 0;
	cpy = malloc(sizeof(*cpy) * (ft_strlen(s) + 1));
	if (cpy == NULL)
		return (0);
	while (i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
