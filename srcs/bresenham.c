#include "fdf.h"
void ft_drawLine(int x1, int y1, int x2, int y2, t_fdf *fdf) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    if (dx > dy) {
        while (x1 != x2) {
            mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, x1, y1, 0x0000FF00);
            int e2 = err * 2;
            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    } else {
        while (y1 != y2) {
            mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, x1, y1, 0x0000FF00);
            int e2 = err * 2;
            if (e2 > -dx) {
                err -= dx;
                y1 += sy;
            }
            if (e2 < dy) {
                err += dy;
                x1 += sx;
            }
        }
    }
    mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, x2, y2, 0x0000FF00);
}

void ft_draw_line2(t_fdf *fdf)
{
    int node_up;
    int n_node;
    int i;
    int j;

    node_up = fdf->grid.length;
    n_node = (fdf->grid.length * fdf->grid.width) - 1;
    i = 0;
    while (++i <= fdf->grid.length)
    {
        j = 0;
        while (++j < fdf->grid.width)
        {
            ft_drawLine(fdf->pos[n_node].x, fdf->pos[n_node].y, fdf->pos[n_node - node_up].x, fdf->pos[n_node - node_up].y, fdf);
            --n_node;
        }
    }
    free(fdf->pos);
}

void ft_draw_line(t_fdf *fdf)
{
    int n_node;
    int i;
    int j;

    n_node = (fdf->grid.length * fdf->grid.width) - 1;
    i = 0;
    while (++i <= fdf->grid.width)
    {
        j = 0;
        while (++j < fdf->grid.length)
        {
            ft_drawLine(fdf->pos[n_node].x, fdf->pos[n_node].y, fdf->pos[n_node - 1].x, fdf->pos[n_node - 1].y, fdf);
            --n_node;
        }
        --n_node;
    }
    ft_draw_line2(fdf);
}