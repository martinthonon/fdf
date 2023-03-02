#include "fdf.h"

int ft_isometric(int n_node, t_fdf *fdf)
{
    int x;
    int y;
    int z;

    x = fdf->origin.x;
    y = fdf->origin.y;
    z = fdf->grid.input[n_node];

//    x -= fdf->grid.length / 2;
//    y -= fdf->grid.width / 2;
//    fdf->pos->x = (x-z)/sqrt(2);
//    fdf->pos->y = (x+2*y+z)/sqrt(6);
    fdf->pos->x = x * cos(rad(fdf->grid.angle.x)) + y * cos(rad(fdf->grid.angle.x) + 120) + z * cos(rad(fdf->grid.angle.x) - 120);
    fdf->pos->y = x * sin(rad(fdf->grid.angle.y)) + y * sin(rad(fdf->grid.angle.y) + 120) + z * sin(rad(fdf->grid.angle.y) - 120);

//    fdf->pos->x = x * cos(rad(fdf->flag.angle)) + y * cos(rad(fdf->flag.angle) + 120) + z * cos(rad(fdf->flag.angle) + 120);
//    fdf->pos->y = x * sin(rad(fdf->flag.angle)) + y * sin(rad(fdf->flag.angle) - 120) + z * sin(rad(fdf->flag.angle) - 120);

//    fdf->pos->x = cos(rad(fdf->flag.angle)) * (y - fdf->grid.width / 2) - cos(rad(fdf->flag.angle)) * (x - fdf->grid.length / 2);
//    fdf->pos->y = -z * cos(rad(fdf->flag.angle * 2)) + sin(rad(fdf->flag.angle)) * (x - fdf->grid.length / 2) + sin(rad(fdf->flag.angle)) * (y - fdf->grid.width / 2);
    // only one angle but could be negatif
//    fdf->pos->x = cos(rad(fdf->grid.angle.x)) * (y - fdf->grid.width / 2) - cos(rad(fdf->grid.angle.x)) * (x - fdf->grid.length / 2);
//
//    fdf->pos->y = -z * cos(rad(fdf->grid.angle.y * 2)) + sin(rad(fdf->grid.angle.y)) * (x - fdf->grid.length / 2) + sin(rad(fdf->grid.angle.y)) * (y - fdf->grid.width / 2);

//    self.vPoint.X = (self.vPoint.X * cos(radians(self.ang)) - self.vPoint.Y * sin(radians(self.ang)))
//    self.vPoint.Y = (self.vPoint.X * sin(radians(self.ang)) + self.vPoint.Y * cos(radians(self.ang)))

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
        return (1);
    return (0);
}