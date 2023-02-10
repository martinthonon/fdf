#include "fdf.h"

int ft_fdf_draw(t_fdf *fdf)
{
    int i;
    int y;
    char **node;

    i = -1;
    while (++i < win_width)
    {
        y = -1;
        node = ft_node_val(fdf);
        printf("%d", node[i]);
        while (++y < win_length)
        {
            printf("cei est un test\n");
//            ft_put node();
        }
    }
    return (0);
}

int ft_engine_init(t_fdf *fdf)
{
    if (ft_grid_size(fdf))
        return (ft_ret(NULL, fdf->input.fd, 1));
    else if (ft_resize(fdf))
        return (1);
    else if (ft_fdf_draw(fdf))
        return (1);
    printf("1 -> fd : %d, path : %s\n", fdf->input.fd, fdf->input.path);
    printf("length -> %d, width -> %d\n", fdf->grid.length, fdf->grid.width);
    for (int i = 0; i <= 200; ++i)
        mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, i, 100, 0xFF00);
    return (0);
}