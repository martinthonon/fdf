#include "fdf.h"

void ft_move(int input, t_fdf *fdf)
{
    if (input == key_w)
        fdf->pos.y -= 20;
    else if (input == key_s)
        fdf->pos.y += 20;
    else if (input == key_a)
        fdf->pos.x -= 20;
    else if (input == key_d)
        fdf->pos.x += 20;
    ft_fdf_draw(fdf);
}

void ft_zoom(int input, t_fdf *fdf)
{
    if (input == key_plus)
        printf("zoom in\n");
    else if (input == key_min) //else would be more clean, but less readable
        printf("zoom out\n");
    ft_fdf_draw(fdf);
}

void ft_type(int input, t_fdf *fdf)
{
    if (input == key_i)
    {
        fdf->proj.isometric = true;
        fdf->proj.cabinet = false;
    }
    else if (input == key_c)
    {
        fdf->proj.isometric = false;
        fdf->proj.cabinet = true;
    }
    ft_fdf_draw(fdf);
}

void ft_mlx_mouse(int input, t_fdf *fdf)
{
    (void)input;
        ft_fdf_draw(fdf);
}