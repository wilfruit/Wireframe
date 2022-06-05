/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:47:03 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/03 14:38:48 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*udest;
	unsigned char	*usrc;
	size_t			i;

	i = 0;
	udest = (unsigned char *)dest;
	usrc = (unsigned char *)src;
	if (src == NULL && dest == NULL)
		return (dest);
	while (i < n)
	{
		udest[i] = usrc[i];
		i++;
	}
	return (dest);
}
