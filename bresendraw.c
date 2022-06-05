/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresendraw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilfried <wilfried@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:53:03 by wgaspar           #+#    #+#             */
/*   Updated: 2022/06/06 01:42:43 by wilfried         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

s_infos	get_slope_director(s_infos data, int x1, int x2, int y1, int y2)
{
	data.dx = ft_abs(x2 - x1);
	data.dy = -ft_abs(y2 - y1);
	data.slope_director = 0;
	if (x1 < x2)
		data.x_increment = 1;
	else
		data.x_increment = -1;
	if (y1 < y2)
		data.y_increment = 1;
	else
		data.y_increment = -1;
	data.slope_error = data.dx + data.dy;
	return (data);
}

Vector	set_point(int x, int y, t_vars fdf)
{
	Vector	point;

	point.z = fdf.map[y][x];
	point.x = x * fdf.scale;
	point.y = y * fdf.scale;
	point.z *= fdf.scale / fdf.z_div;
	point.x -= (fdf.width * fdf.scale) / 2;
	point.y -= (fdf.height * fdf.scale) / 2;
	if (fdf.projection == 2)
		fdf.angle_z += 3.14159;
 	point = apply_rotation(point, &fdf);
 	if (fdf.projection == 1)
		Project_isometric(&point, &fdf);
	if (fdf.projection == 2)
		Project_perspective(&point, &fdf);
	if (fdf.projection == 3)
 	 	Project_oblique(&point, &fdf);
	return (point);
}

void	init_data(s_infos *data)
{
	data->slope_director = 0;
	data->slope_error = 0;
	data->dx = 0;
	data->dy = 0;
	data->x_increment = 0;
	data->y_increment = 0;
}

void	bresenham(int x1, int x2, int y1, int y2, t_vars *fdf)
{
	s_infos	data;
	Vector	pointA;
	Vector	pointB;
	int		color;

	init_data(&data);
	pointA = set_point(x1, y1, *fdf);
	pointB = set_point(x2, y2, *fdf);
 	x1 = pointA.x;
	y1 = pointA.y;
	x2 = pointB.x;
	y2 = pointB.y;
	data = get_slope_director(data, x1, x2, y1, y2);
//	color = 0x0076bfff;
//	color = 0x00f6da50;
	color = 0x0013DDA2;
	while (!(x1 == x2 && y1 == y2))
	{
		if (x1 < 1720 && x1 > 0 && y1 < 920 && y1 > 0)
			ft_mlx_pixel_put(fdf, x1, y1, color);
		data.slope_director = 2 * data.slope_error;
		if (data.slope_director >= data.dy) 
		{ 
			data.slope_error += data.dy; 
			x1 += data.x_increment; 
		}
		if (data.slope_director <= data.dx) 
		{ 
			data.slope_error += data.dx; 
			y1 += data.y_increment; 
		}
	}
}

void	ft_draw_wireframe(t_vars *fdf)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
 	//color_background(fdf, 0x00332417);
	//color_background(fdf, 0x00004D36);
	color_background(fdf, 0x00024431);
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				bresenham(x, x + 1, y, y, fdf);
			if (y < fdf->height - 1)
				bresenham(x, x, y, y + 1, fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img, 0, 0);
	print_menu(fdf);
}