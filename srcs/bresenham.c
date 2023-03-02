#include "fdf.h"
void ft_bresenham(int x1, int y1, int x2, int y2, t_fdf *fdf)
{

}

void ft_draw_line(t_fdf *fdf)
{
    int n_node;

    n_node = (fdf->grid.length * fdf->grid.width) - 1;
    while (n_node > 0)
    {
//        mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, fdf->pos[n_node].x, fdf->pos[n_node].y, 0xFF00);
        ft_bresenham(fdf->pos[n_node].x, fdf->pos[n_node].y, fdf->pos[n_node - 1].x, fdf->pos[n_node - 1].y, fdf);
        --n_node;
    }
    free(fdf->pos);
}


