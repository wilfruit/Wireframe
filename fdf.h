/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilfried <wilfried@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:26:59 by wgaspar           #+#    #+#             */
/*   Updated: 2022/06/06 00:05:34 by wilfried         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


# include<unistd.h>
# include<string.h>
# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<mlx.h>
# include<fcntl.h>
# include"libft.h"

// Structure - MLX

typedef struct	s_imgs
{
	void	*img;
	char	*adr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_imgs;

typedef struct	s_vars {
	void	*mlx_ptr;
	void	*win_ptr;
	int		x_mov;
	int		y_mov;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	z_div;
	int		projection;
	int		scale;
	int		win_y;
	int		win_x;
	int		**map;
	int		height;
	int		width;
	int		x_map;
	int		y_map;
	int		color;
	int		menu_switch;
	t_imgs	img;
}				t_vars;


// Structure - Bresenham

typedef struct	t_infos
{
	int	slope_error;
	int	slope_director;
	int	dx;
	int	dy;
	int x_increment;
	int	y_increment;
}				s_infos;

// Structures - Vectors

typedef struct {
	float x;
	float y;
	float z;
}	Vector;

typedef struct {
	int x;
	int	y;
}	Vector_2D;

typedef struct {
	Vector	Local_xyz;
	Vector	World_xyz;
	Vector	View_xyz;
	Vector_2D Projection;
}	Vertices;

// Projection Functions

Vector	apply_rotation(Vector point, t_vars *fdf);
void	Project_perspective(Vector *Point, t_vars *fdf);
void 	Project_isometric(Vector *Point, t_vars *fdf);
void 	Project_oblique(Vector *Point, t_vars *fdf);
void 	Project_stereo(Vector *Point, t_vars *fdf);
void 	M3D_Init();

// Draw - Bresenham algorithm

void    set_basic_values(t_vars *fdf);
int		ft_abs(int n);
void	init_data(s_infos *data);
s_infos	get_slope_director(s_infos data, int x1, int x2, int y1, int y2);
void	mlx_pixel_put_invert(void *ptr, void *win_ptr, int x, int y, int color, int win_y);
void	bresenham(int x1, int x2, int y1, int y2, t_vars *fdf);
void	ft_draw_wireframe(t_vars *fdf);
void	ft_mlx_pixel_put(t_vars *fdf, int x, int y, int color);

// MLX - Colors

int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);
int		get_opposite_color(int color);
int		add_shade(double distance, int color);
void	color_background(t_vars *fdf, int color);

// MAPS - Utils

int 	**allocate_int_tab(int x, int y);
int 	lines_counter(char *file);
int  	rows_counter(char *file);
void    ft_print_tab(int **tab);

// GNL

char	*get_next_line(int fd);

// Key_controls

void    init_controls(t_vars *fdf);
int 	key_press(int keycode, void *param);
int		ft_scale(int keycode, t_vars *fdf);
int		ft_change_projection(int keycode, t_vars *fdf);
int 	ft_zvar(int keycode, t_vars *fdf);
int		ft_restart_values(int keycode, t_vars *fdf);
int     ft_switch_menu(int keycode, t_vars *fdf);
int		ft_close(void *param);
int     ft_move(int keycode, t_vars *fdf);
int     ft_rotate(int keycode, t_vars *fdf);
void    print_menu(t_vars *fdf);

#endif

