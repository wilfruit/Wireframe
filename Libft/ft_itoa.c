/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:06:08 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/01 17:18:56 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nsize(int a)
{
	int	size;

	size = 0;
	if (a == 0)
		return (1);
	if (a == -2147483648)
		return (11);
	if (a >= -2147483647 && a < 0)
	{
		a *= -1;
		size++;
	}
	while (a >= 1)
	{
		a = a / 10;
		size++;
	}
	return (size);
}

char	*ft_fill_string(char *s, int size, unsigned int value)
{
	int	i;

	i = 1;
	while (value >= 1)
	{
		s[size - i] = (char)(value % 10) + '0';
		value = value / 10;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	value;	
	int				i;
	int				size;

	i = 1;
	size = ft_nsize(n);
	value = 0;
	s = malloc(sizeof(char) * (ft_nsize(n) + 1));
	if (!s)
		return (NULL);
	if (n < 0)
		value = -n;
	else if (n > 0)
		value = n;
	else if (n == 0)
		s[0] = 48;
	s = ft_fill_string(s, size, value);
	if (n < 0)
		s[0] = '-';
	s[size] = '\0';
	return (s);
}
