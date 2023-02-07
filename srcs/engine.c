#include "fdf.h"

//int ft_node_init(char *str)
//{
//    int fd;
//    int res;
//
//    fd = open(str, O_RDONLY);
//    if (fd < 0)
//        return (1);
//    while (grid->width >= 0)
//    {
//        while (grid->length >= 0)
//        {
//            res = ft_atoi()
//            if (!res)
//                return (1);
//            ft_put_node(res);
//            grid->lenght--;
//        }
//        grid->width--;
//    }
//
//
//}
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
//    else if (ft_node_init(str))
//        return (1);
    printf("length -> %d, width -> %d\n", grid.length, grid.width);
    for (int i = 0; i <= 200; ++i)
        mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, i, 100, 0xFF00);


    return (0);
}