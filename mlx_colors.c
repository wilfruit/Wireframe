/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:48:36 by wgaspar           #+#    #+#             */
/*   Updated: 2022/01/27 12:53:40 by wgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int get_b(int trgb)
{
	return ((trgb) & 0xFF);
}


int	get_opposite_color(int color)
{
	int	opposite_color;

	return (opposite_color = create_trgb(255, 255, 255, 255)) - color;
}

int	add_shade(double distance, int color);
{
	if (distance = 1)
		return ();

	else if (distance = 0.5)
		return ();

	else if (distance = 0.25)
		return ();

	else if (distance = 0)
		return (return(color));
}
