/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilfried <wilfried@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:36:47 by wgaspar           #+#    #+#             */
/*   Updated: 2022/06/06 03:34:29 by wilfried         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

Vector	apply_rotation(Vector point, t_vars *fdf)
{
	int		temp_y;
	int		temp_x;
	Vector	r_point;

	//anglex
	temp_y = point.y;
	r_point.y = point.y * cos(fdf->angle_x) + point.z * sin(fdf->angle_x);
	r_point.z = -temp_y * sin(fdf->angle_x) + point.z * cos(fdf->angle_x);
	//angley
	temp_x = point.x;
	r_point.x = point.x * cos(fdf->angle_y) + r_point.z * sin(fdf->angle_y);
	r_point.z = -temp_x * sin(fdf->angle_y) + r_point.z * cos(fdf->angle_y);
	//anglez
	temp_x = point.x;
	r_point.x = r_point.x * cos(fdf->angle_z) - r_point.y * sin(fdf->angle_z);
	r_point.y = temp_x * sin(fdf->angle_z) + r_point.y * cos(fdf->angle_z);
	return (r_point);
}

void Project_perspective(Vector *Point, t_vars *fdf)
{
	float	temp_x;
	float	temp_y;
	float	temp_z;

	temp_x = Point->x;
	temp_y = Point->y;
	temp_z = -1 * Point->z;
	if(!Point->z)
		Point->z=1;

	Point->x = 1000 * Point->x / (Point->z - 600) + 860;
	Point->y = 1000 * Point->y / (Point->z - 600) + 460;
	Point->x += fdf->x_mov;
	Point->y += fdf->y_mov;
}

void Project_isometric(Vector *Point, t_vars *fdf)
{
	float	temp_x;

	temp_x = Point->x;

	Point->x = (Point->x - Point->y) * cos(0.523599) + 860;
	Point->y = -Point->z + (temp_x + Point->y) * sin(0.523599) + 460;

	Point->x += fdf->x_mov;
	Point->y += fdf->y_mov;
}

void Project_oblique(Vector *Point, t_vars *fdf)
{
	Point->x = Point->x + (0.5 * Point->z * cos(63.4)) + fdf->x_mov + 860;
	Point->y = Point->y + (0.5 * Point->z * sin(63.4)) + fdf->y_mov + 460;
}

/* void Project_stereo(Vector *Point, t_vars *fdf)
{
	Point->x = Point->x / (1 - Point->z) + fdf->x_mov + 860;
	Point->y = Point->y / (1 - Point->z) + fdf->y_mov + 460;
} */

void Project_stereo(Vector *Point, t_vars *fdf)
{
	int	d;

	d = sqrt((double)(Point->x * Point->x) + (Point->y * Point->y) + (Point->z * Point->z));
 	Point->x = (Point->x  * 300) / d + fdf->x_mov + 860;
	Point->y = (Point->y  * 300) / d + fdf->y_mov + 460;
}