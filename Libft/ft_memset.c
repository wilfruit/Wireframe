/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:15:36 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/03 14:39:00 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bstr;	

	i = 0;
	bstr = b;
	while (i < len)
	{
		bstr[i] = c;
		i++;
	}
	return (bstr);
}
