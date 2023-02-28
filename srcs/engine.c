#include "fdf.h"

void ft_draw_line(t_fdf *fdf)
{
    int n_node;

    n_node = fdf->grid.length * fdf->grid.width;
    mlx_clear_window(fdf->vars.mlx, fdf->vars.win);
    while (--n_node >= 0)
    {
        mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, fdf->pos[n_node].x, fdf->pos[n_node].y, 0xFF00);
    }
    free(fdf->pos);
}

int ft_put_dot(int x, int y, int n_node, t_fdf *fdf)
{
    int z;

    z = fdf->grid.input[n_node];
    printf("z->%d\n", n_node);
//    if (fdf->proj.cabinet == true)
//        ft_cabinet(fdf);
//    else
//        ft_ismoetric(fdf);
//    mlx_clear_window(fdf->vars.mlx, fdf->vars.win);

//    u=(x-z)/sqrt(2);
//    v=(x+2*y+z)/sqrt(6);
    fdf->pos->x = x * cos(fdf->grid.angle.x) + y * cos(fdf->grid.angle.x + 120) + z * cos(fdf->grid.angle.x - 120);
    fdf->pos->y = x * sin(fdf->grid.angle.y) + y * sin(fdf->grid.angle.y + 120) + z * sin(fdf->grid.angle.y - 120);

    fdf->pos->x += fdf->move.x + x;
    fdf->pos->y += fdf->move.y + y;
//
//    mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, fdf->pos->x, fdf->pos->y, 0xFF00);
    fdf->pos[n_node].x = fdf->pos->x;
    fdf->pos[n_node].y = fdf->pos->y;
    return 0;
}

int ft_fdf_draw(t_fdf *fdf)
{
    int n_node;
    int i;
    int j;
    int x;
    int y;

    y = 100;
    i = -1;
    n_node = fdf->grid.length * fdf->grid.width;
    fdf->pos = malloc(sizeof(t_axis) * n_node);
    if (!fdf->pos)
        return (1);
    while (++i < fdf->grid.width)
    {
        j = -1;
        x = 100;
        while (++j < fdf->grid.length)
        {
            ft_put_dot(x, y, --n_node, fdf);
            x += fdf->grid.space.x;
        }
        y += fdf->grid.space.y;
    }
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