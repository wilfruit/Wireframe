/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilfried <wilfried@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:51:16 by wgaspar           #+#    #+#             */
/*   Updated: 2022/06/05 21:56:52 by wilfried         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include"get_next_line.h"

static void	wrong_file(char *argv)
{
	ft_putstr_fd(argv, 2);
	ft_putstr_fd(" : ", 2);
	ft_putstr_fd("File does not exist/is not readable\n", 2);
	exit(1);
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

int	main(int argc, char **argv)
{
	t_vars	*fdf;
	int	i;

	i = 0;
	if (argc != 2)
		return (1);
	fdf = (t_vars *)malloc(sizeof(t_vars));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1720, 920, "FDF");
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, 860, 460, 0x0000FF00);
	create_map(argv[1], fdf);
	ft_fill_map(argv[1], fdf);
	set_basic_values(fdf);
	ft_draw_wireframe(fdf);
	init_controls(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}