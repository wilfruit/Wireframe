/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilfried <wilfried@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:10:04 by wgaspar           #+#    #+#             */
/*   Updated: 2022/06/06 02:30:09 by wilfried         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_vars	*fdf;

	if (argc != 2)
		return (1);
	fdf = (t_vars *)malloc(sizeof(t_vars));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1720, 920, "FDF");
	fdf->img.img = mlx_new_image(fdf->mlx_ptr, 1720, 920);
	fdf->img.adr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp, \
	&fdf->img.line_len, &fdf->img.endian);
	create_map(argv[1], fdf);
	ft_fill_map(argv[1], fdf);
	set_basic_values(fdf);
	ft_draw_wireframe(fdf);
	init_controls(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
