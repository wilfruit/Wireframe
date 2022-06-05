/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:55:32 by wgaspar           #+#    #+#             */
/*   Updated: 2021/12/01 17:24:39 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	value;

	value = 0;
	if (n < 0)
	{
		value = -n;
		ft_putchar_fd('-', fd);
	}
	else
		value = n;
	if (value >= 10)
	{
		ft_putnbr_fd(value / 10, fd);
		ft_putchar_fd(value % 10 + 48, fd);
	}
	else
	{
		value = value + 48;
		ft_putchar_fd(value, fd);
	}
}
