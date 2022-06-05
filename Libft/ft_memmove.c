/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:18:39 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/01 17:23:41 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*udst;
	char	*usrc;
	int		i;

	udst = (char *)dst;
	usrc = (char *)src;
	i = 0;
	if (src >= dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			udst[len - 1] = usrc[len - 1];
			len--;
		}
	}
	return (dst);
}
