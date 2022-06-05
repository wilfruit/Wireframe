/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:13:44 by wgaspar           #+#    #+#             */
/*   Updated: 2021/11/25 18:13:48 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	n;
	int	negative;

	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	negative = 1;
	if (*str == '-' || *str == '+')
	{	
		if (*str++ == '-')
			negative = -1 * negative;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + *str++ - '0';
	}
	n = n * negative;
	return (n);
}
