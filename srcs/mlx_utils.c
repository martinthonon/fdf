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
        fdf->grid.space += 20;
    else if (input == key_min)
        fdf->grid.space -= 20;
}
void ft_rotation(int input, t_fdf *fdf)
{
    if (fdf->flag.rotation == true)
    {
        if (input == key_up)
            printf("rot up\n");
        else if (input == key_down)
            printf("rot down\n");
        else if (input == key_left)
            printf("rot left\n");
        else if (input == key_right)
            printf("rot right\n");
        ft_fdf_draw(fdf);
    }
}

void ft_flag(int input, t_fdf *fdf)
{
    if (input == key_r)
    {
        if (fdf->flag.rotation == true)
            fdf->flag.rotation = false;
        else
            fdf->flag.rotation = true;
    }
    else if (input == key_i)
    {
        fdf->flag.isometric = true;
        fdf->flag.cabinet = false;
        ft_fdf_draw(fdf);
    }
    else if (input == key_c)
    {
        fdf->flag.isometric = false;
        fdf->flag.cabinet = true;
        ft_fdf_draw(fdf);
    }
}