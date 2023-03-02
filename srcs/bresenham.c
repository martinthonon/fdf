#include "fdf.h"
void ft_bresenham(int x0, int y0, int x1, int y1, t_fdf *fdf)
{
    int dx;
    int dy;
    int x;
    int y;
    int p;

    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;
    p = 2 * dy - dx;
    while (x < x1)
    {
        if (p >= 0)
        {
            mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, x, y, 0xFFFFFF);
            ++y;
            p = p + 2 * dy - 2 * dx;
        } else {
            mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, x, y, 0xFFFFFF);
            p = p + 2 * dy;
            ++x;
        }
    }
}

void ft_draw_line2(t_fdf *fdf)
{
    int n_node;
    int node_up;
    int x1;
    int y1;

    n_node = fdf->grid.length * fdf->grid.width;
    node_up = fdf->grid.length + 1;
    while (--n_node > 0)
    {
        x1 = fdf->pos[n_node - node_up].x;
        y1 = fdf->pos[n_node - node_up].y;
//        ft_bresenham(fdf->pos[n_node].x, fdf->pos[n_node].y, x1, y1, fdf);

        mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, fdf->pos[n_node].x, fdf->pos[n_node].y, 0xFF00);
    }
}

void ft_draw_line(t_fdf *fdf)
{
    int n_node;
    int x1;
    int y1;

    n_node = fdf->grid.length * fdf->grid.width;
    x1 = fdf->pos[n_node - 2].x;
    y1 = fdf->pos[n_node - 2].y;
    while (--n_node >= 0)
    {

//       ft_bresenham(fdf->pos[n_node].x, fdf->pos[n_node].y, x1, y1, fdf);
//       if (n_node - 2 < 0)
//           break;
//        x1 = fdf->pos[n_node - 2].x;
//        y1 = fdf->pos[n_node - 2].y;

        mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, fdf->pos[n_node].x, fdf->pos[n_node].y, 0xFF00);
    }
    free(fdf->pos);
//    ft_draw_line2(fdf);
}


