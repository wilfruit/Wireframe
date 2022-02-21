/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilfried <wilfried@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:54:31 by wgaspar           #+#    #+#             */
/*   Updated: 2022/02/20 18:27:46 by wilfried         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	ft_abs(int n)
{
	if (n == 0)
		return (0);
	else if (n > 0)
		return (n);
	else
		return (-1 * n);
}

void	mlx_pixel_put_invert(void *ptr, void *win_ptr, int x, int y, int color, int win_y)
{
	mlx_pixel_put(ptr, win_ptr, x, ft_abs(y - win_y), color);
}