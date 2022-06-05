#include "fdf.h"

void	ft_mlx_pixel_put(t_vars *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->img.adr + (y * fdf->img.line_len + x * (fdf->img.bpp / 8));
	*(unsigned int*)dst = color;
}

void   color_background(t_vars *fdf, int color)
{
    int i;
    int j;

    i = 1;

    while (i < 1719)
    {
        j = 1;
        while (j < 919)
        {
            ft_mlx_pixel_put(fdf, i, j, color);
            j++;
        }
        i++;
    }
}

void    print_menu(t_vars *fdf)
{
    if (fdf->menu_switch == 0)
    {
	    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 720, 0x00D05008, "Change Projection : P");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 750, 0x00D05008, "Reset Parameters  : R");
	    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 780, 0x00D05008, "Flatten -> O     Expand -> L");
	    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 810, 0x00D05008, "Sixaxis Rotation : ");
	    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 840, 0x00D05008, "X-Axis :     '+' -> Z     '-' -> X ");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 870, 0x00D05008, "Y-Axis :     '+' -> D     '-' -> Q ");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 900, 0x00D05008, "Z-Axis :     '+' -> E     '-' -> A ");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 30, 0x00D05008, "ZOOM : ");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 60, 0x00D05008, "'+' -> @     '-' -> &");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 120, 0x00D05008, "MOVE : ");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 120, 150, 0x00D05008, "^");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 70, 190, 0x00D05008, "<");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 170, 190, 0x00D05008, ">");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 120, 230, 0x00D05008, "v");
    }
}