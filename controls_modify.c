#include"fdf.h"

int    ft_scale(int keycode, t_vars *fdf)
{
    if (keycode == 10)
    {
        fdf->scale += 3;
        fdf->img.img = mlx_new_image(fdf->mlx_ptr, 1720, 920);
    	fdf->img.adr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp, \
	    &fdf->img.line_len, &fdf->img.endian);
        ft_draw_wireframe(fdf);
    }
    if (keycode == 18)
    {
        fdf->img.img = mlx_new_image(fdf->mlx_ptr, 1720, 920);
    	fdf->img.adr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp, \
    	&fdf->img.line_len, &fdf->img.endian);
        fdf->scale -= 3;
        ft_draw_wireframe(fdf);
    }
    return (0);
}

int     ft_move(int keycode, t_vars *fdf)
{
    if (keycode == 123)
        fdf->x_mov -= 20;
    if (keycode == 124)
        fdf->x_mov += 20;
    if (keycode == 126)
        fdf->y_mov -= 20;
    if (keycode == 125)
        fdf->y_mov += 20;
    fdf->img.img = mlx_new_image(fdf->mlx_ptr, 1720, 920);
	fdf->img.adr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp, \
	&fdf->img.line_len, &fdf->img.endian);
    ft_draw_wireframe(fdf);
    return (0);
}

int     ft_rotate(int keycode, t_vars *fdf)
{
    if (keycode == 0)
        fdf->angle_y -= 0.05;
    if (keycode == 2)
        fdf->angle_y += 0.05;
    if (keycode == 13)
        fdf->angle_x += 0.20;
    if (keycode == 7)
        fdf->angle_x -= 0.20;
    if (keycode == 12)
        fdf->angle_z -= 0.20;
    if (keycode == 14)
        fdf->angle_z += 0.20;
    fdf->img.img = mlx_new_image(fdf->mlx_ptr, 1720, 920);
	fdf->img.adr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp, \
	&fdf->img.line_len, &fdf->img.endian);
    ft_draw_wireframe(fdf);
    return (0);
}

int ft_change_projection(int keycode, t_vars *fdf)
{
    if (keycode == 35 && fdf->projection == 3)
        fdf->projection = 1;
    else if (keycode == 35 && fdf->projection == 1)
        fdf->projection = 2;
    else if (keycode == 35 && fdf->projection == 2)
        fdf->projection = 3;
    fdf->img.img = mlx_new_image(fdf->mlx_ptr, 1720, 920);
	fdf->img.adr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp, \
	&fdf->img.line_len, &fdf->img.endian);
    ft_draw_wireframe(fdf);
    return (0);
}

int ft_zvar(int keycode, t_vars *fdf)
{
    if (keycode == 31)
        fdf->z_div += 0.1;
    if (keycode == 37)
        fdf->z_div -= 0.1;
    fdf->img.img = mlx_new_image(fdf->mlx_ptr, 1720, 920);
	fdf->img.adr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp, \
	&fdf->img.line_len, &fdf->img.endian);
    ft_draw_wireframe(fdf);
    return (0);
}
