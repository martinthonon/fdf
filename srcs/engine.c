#include "fdf.h"

//int ft_put_dot(t_fdf *fdf)
//{
//    if (fdf->proj.cabinet == true)
//        ft_cabinet(fdf);
//    else
//
//
//}

int ft_fdf_draw(t_fdf *fdf)
{
    int i;
    int y;
    int *nptr;

    fdf->input.fd = open(fdf->input.path, O_RDONLY);
    if (fdf->input.fd < 0)
        return (1);
    i = -1;
    while (++i < fdf->grid.width)
    {
        y = -1;
        nptr = ft_node_val(fdf);
        if (!nptr)
            return (1);
        while (++y < fdf->grid.length)
        {
            printf("%d ", nptr[y]);
//            ft_put node();
        }
        printf("\n");
        free(nptr);
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