/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresendraw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilfried <wilfried@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:53:03 by wgaspar           #+#    #+#             */
/*   Updated: 2022/06/06 02:38:43 by wilfried         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

s_infos	get_slope_director(s_infos data, t_vars *fdf)
{
	data.dx = ft_abs(fdf->x2 - fdf->x1);
	data.dy = -ft_abs(fdf->y2 - fdf->y1);
	data.slope_director = 0;
	if (fdf->x1 < fdf->x2)
		data.x_increment = 1;
	else
		data.x_increment = -1;
	if (fdf->y1 < fdf->y2)
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
	if (fdf.projection == 4)
		Project_stereo(&point, &fdf);
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

static void	draw_line(s_infos *data, t_vars *fdf)
{
	while (!(fdf->x1 == fdf->x2 && fdf->y1 == fdf->y2))
	{
		if (fdf->x1 < 1720 && fdf->x1 > 0 && fdf->y1 < 920 && fdf->y1 > 0)
			ft_mlx_pixel_put(fdf, fdf->x1, fdf->y1, 0x0013DDA2);
		data->slope_director = 2 * data->slope_error;
		if (data->slope_director >= data->dy) 
		{ 
			data->slope_error += data->dy; 
			fdf->x1 += data->x_increment; 
		}
		if (data->slope_director <= data->dx) 
		{ 
			data->slope_error += data->dx; 
			fdf->y1 += data->y_increment; 
		}
	}
}

void	bresenham(t_vars *fdf)
{
	s_infos	data;
	Vector	pointA;
	Vector	pointB;

	init_data(&data);
	pointA = set_point(fdf->x1, fdf->y1, *fdf);
	pointB = set_point(fdf->x2, fdf->y2, *fdf);
 	fdf->x1 = pointA.x;
	fdf->y1 = pointA.y;
	fdf->x2 = pointB.x;
	fdf->y2 = pointB.y;
	data = get_slope_director(data, fdf);
	draw_line(&data, fdf);
}