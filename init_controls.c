#include"fdf.h"

int		ft_close(void *param)
{
	(void)param;
	exit(0);
}

int     ft_switch_menu(int keycode, t_vars *fdf)
{
    if (keycode == 4 && fdf->menu_switch == 1)
        fdf->menu_switch -= 1;
    else if (keycode == 4 && fdf->menu_switch == 0)
        fdf->menu_switch += 1;
    mlx_destroy_image(fdf->mlx_ptr, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->mlx_ptr, 1720, 920);
	fdf->img.adr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp, \
	&fdf->img.line_len, &fdf->img.endian);
    ft_draw_wireframe(fdf);
    return (0);
}

int ft_restart_values(int keycode, t_vars *fdf)
{
    if (keycode != 15)
        return (0);
    if (fdf->height < 10 && fdf->width < 10)
        fdf->scale = 20;
    else if (fdf->height > 100 && fdf->width > 100)
        fdf->scale = 5;
    else
        fdf->scale = 10;
    fdf->angle_x = 0;
    fdf->angle_y = 0;
    fdf->angle_z = 0;
    fdf->z_div = 1.5;
    fdf->projection = 1;
    fdf->x_mov = 0;
    fdf->y_mov = 0;
    fdf->img.img = mlx_new_image(fdf->mlx_ptr, 1720, 920);
	fdf->img.adr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp, \
	&fdf->img.line_len, &fdf->img.endian);
    ft_draw_wireframe(fdf);
    return (0);
}

int key_press(int keycode, void *param)
{
    if (keycode == 10 || keycode == 18)
        ft_scale(keycode, param);
    if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
        ft_move(keycode, param);
    if (keycode == 0 || keycode == 2 || keycode == 13 || keycode == 7 || keycode == 12 || keycode == 14)
        ft_rotate(keycode, param);
    if (keycode == 35)
        ft_change_projection(keycode, param);
    if (keycode == 31 || keycode == 37)
        ft_zvar(keycode, param);
    if (keycode == 15)
        ft_restart_values(keycode, param);
    if (keycode == 53)
        ft_close(param);
    if (keycode == 4)
        ft_switch_menu(keycode, param);
    return (0);
}

void    init_controls(t_vars *fdf)
{
    mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, ft_close, fdf);
}
