#include "fdf.h"

int ft_draw(t_fdf *fdf)
{
    int i;
    int y;

    fdf->input.fd = open(fdf->input.path, O_RDONLY);
    if (fd < 0)
        return (1);
    i = -1;
    while (++i < win_length)
    {
        y = -1;
        while (++y < win_width)
        {
            res = ft_atoi()
            if (!res)
                return (1);
            ft_put_node(res);
        }
    }

return (0);
}
int ft_engine_init(char *str, t_fdf *fdf)
{
    t_grid grid;
    int fd;
    fd = open(str, O_RDONLY);
    if (fd < 0)
        return (1);
    if (ft_grid_size(fd, &grid))
        return (ft_ret(NULL, fd, 1));
    else if (ft_resize(&grid))
        return (1);
    else if (ft_draw(&fdf))
        return (1);
//    else if (ft_node_init(str))
//        return (1);
//    printf("length -> %d, width -> %d\n", grid.length, grid.width);
//    for (int i = 0; i <= 200; ++i)
//        mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, i, 100, 0xFF00);


    return (0);
}