#include "fdf.h"

int ft_isometric(int n_node, t_fdf *fdf)
{
    int x;
    int y;
    int z;

    x = fdf->origin.x;
    y = fdf->origin.y;
    z = fdf->grid.input[n_node];
//    u=(x-z)/sqrt(2);
//    v=(x+2*y+z)/sqrt(6);
    fdf->pos->x = x * cos(fdf->grid.angle.x) + y * cos(fdf->grid.angle.x + 120) + z * cos(fdf->grid.angle.x - 120);
    fdf->pos->y = x * sin(fdf->grid.angle.y) + y * sin(fdf->grid.angle.y + 120) + z * sin(fdf->grid.angle.y - 120);
    fdf->pos->x += fdf->move.x + x;
    fdf->pos->y += fdf->move.y + y;
    fdf->pos[n_node].x = fdf->pos->x;
    fdf->pos[n_node].y = fdf->pos->y;
    return 0;
}

int ft_fdf_draw(t_fdf *fdf)
{
    int i;
    int j;
    int n_node;

    mlx_clear_window(fdf->vars.mlx, fdf->vars.win);
    n_node = fdf->grid.length * fdf->grid.width;
    fdf->pos = malloc(sizeof(t_axis) * n_node);
    if (!fdf->pos)
        return (1);
    i = -1;
    while (++i < fdf->grid.width)
    {
        j = -1;
        fdf->origin.x = 100;
        while (++j < fdf->grid.length)
        {
            ft_isometric( --n_node, fdf);
            fdf->origin.x += fdf->grid.space.x;
        }
        fdf->origin.y += fdf->grid.space.y;
    }
    fdf->origin.y = 100;
    ft_draw_line(fdf);
    return (0);
}

int ft_engine_init(t_fdf *fdf)
{
    if (ft_grid_size(fdf))
        return (ft_ret(NULL, fdf->input.fd, 1));
    else if (ft_get_node(fdf))
        return (ft_ret(NULL, fdf->input.fd, 1));
    else if (ft_fdf_draw(fdf))
    {
        printf("check\n");
        return (1);
    }
    printf("1 -> fd : %d, path : %s\n", fdf->input.fd, fdf->input.path);
    printf("length -> %d, width -> %d\n", fdf->grid.length, fdf->grid.width);
//    for (int i = 0; i <= 200; ++i)
//        mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, i, 100, 0xFF00);
    return (0);
}