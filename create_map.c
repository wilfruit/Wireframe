/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilfried <wilfried@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:51:16 by wgaspar           #+#    #+#             */
/*   Updated: 2022/06/06 02:29:49 by wilfried         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static void	wrong_file(char *argv)
{
	ft_putstr_fd(argv, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd("File does not exist/is not readable\n", 2);
	exit(1);
}

static void loop_wireframe(t_vars *fdf, int x, int y)
{
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
			{
				fdf->x1 = x;
				fdf->x2 = x + 1;
				fdf->y1 = y;
				fdf->y2 = y;
				bresenham(fdf);
			}
			if (y < fdf->height - 1)
			{
				fdf->x1 = x;
				fdf->x2 = x;
				fdf->y1 = y;
				fdf->y2 = y + 1;
				bresenham(fdf);
			}
			x++;
		}
		y++;
	}
}

void	ft_draw_wireframe(t_vars *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	color_background(fdf, 0x00024431);
	loop_wireframe(fdf, x, y);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img, 0, 0);
	print_menu(fdf);
}

int	ft_fill_map(char *argv, t_vars *fdf)
{
	int 	fd;
	char	**split;
	char	*str;

	fdf->y_map = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 1)
		return (0);
	while (fdf->y_map < fdf->height)
	{
		str = get_next_line(fd);
		split = ft_split(str, ' ');
		fdf->x_map = 0;
		while (split[fdf->x_map])
		{
			fdf->map[fdf->y_map][fdf->x_map] = ft_atoi(split[fdf->x_map]);
			fdf->x_map++;
		}
		free(split);
		free(str);
		fdf->y_map++;
	}
	return (0);
}

int **create_map(char *argv, t_vars *fdf)
{
	int		fd;
	char	*str = NULL;
	char	*buffer;

	fd = open(argv, O_RDWR);
	if (fd < 1)
		wrong_file(argv);
	while((buffer = get_next_line(fd)))
	{
		str = ft_strjoinmod(str, buffer);
		free(buffer);
	}
	free(buffer);
	close(fd);
	fdf->height = lines_counter(str);
	fdf->width = rows_counter(str);
	free(str);
	fdf->map = allocate_int_tab(fdf->width, fdf->height);
	if (!fdf->map)
		return (0);
	return (0);
}