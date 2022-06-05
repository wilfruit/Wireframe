/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:37:02 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/03 14:33:05 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (0);
	str = ft_strdup(s);
	i = 0;
	if (!str || !f || !s)
		return (NULL);
	while (str[i] && s[i])
	{
		str[i] = (*f)(i, str[i]);
		i++;
	}	
	return (str);
}
