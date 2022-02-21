#include "fdf.h"

void   color_background(t_vars *fdf, int color)
{
    int i;
    int j;

    i = 0;

    while (i++ < 920)
    {
        j = 0;
        while (j++ < 1720)
            mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, i, j, color);
    }
}

void    print_menu(t_vars *fdf)
{
    if (fdf->menu_switch == 0)
    {
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 500, 0x00FFFFFF, "Controls");
	    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 530, 0x00FFFFFF, "Change Projection : P");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 560, 0x00FFFFFF, "Reset Parameters  : R");
	    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 590, 0x00FFFFFF, "Flatten -> O     Expand -> L");
	    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 650, 0x00FFFFFF, "Sixaxis Rotation : ");
	    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 680, 0x00FFFFFF, "X-Axis :     '+' -> Z     '-' -> X ");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 710, 0x00FFFFFF, "Y-Axis :     '+' -> D     '-' -> Q ");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 740, 0x00FFFFFF, "Z-Axis :     '+' -> E     '-' -> A ");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 800, 0x00FFFFFF, "ZOOM : ");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 830, 0x00FFFFFF, "'+' -> @     '-' -> &");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 890, 0x00FFFFFF, "MOVE : ");
        mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 920, 0x00FFFFFF, "Arrows");
    }
}