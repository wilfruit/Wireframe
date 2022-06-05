/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:20:20 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/02 19:15:43 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	maxsize;
	char	*str;

	i = 0;
	maxsize = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	i = ft_strlen(&s[start]);
	if (i < len)
		maxsize = i;
	else
		maxsize = len;
	str = (char *)malloc(sizeof(char) * (maxsize + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], maxsize + 1);
	return (str);
}
