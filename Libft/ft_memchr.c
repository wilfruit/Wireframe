/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:47:49 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/01 17:19:33 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*us;
	size_t				i;

	i = 0;
	us = (unsigned char *)s;
	while (n != 0)
	{
		if (us[i] == (unsigned char)c)
			return ((unsigned char *)us + i);
		i++;
		n--;
	}
	return (NULL);
}
