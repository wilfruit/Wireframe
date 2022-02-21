#include"fdf.h"

void    set_basic_values(t_vars *fdf)
{
    if (fdf->height < 10 && fdf->width < 10)
        fdf->scale = 20;
    else if (fdf->height > 100 && fdf->width > 100)
        fdf->scale = 5;
    else if (fdf-> height > 500 && fdf->width > 500)
        fdf->scale = 1;
    else
        fdf->scale = 10;
    fdf->angle_x = 0;
    fdf->angle_y = 0;
    fdf->angle_z = 0;
    fdf->z_div = 1.5;
    fdf->projection = 1;
    fdf->x_mov = 0;
    fdf->y_mov = 0;
    fdf->menu_switch = 0;
}