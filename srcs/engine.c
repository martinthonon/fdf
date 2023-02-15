#include "fdf.h"

int ft_put_dot(int z, t_fdf *fdf)
{
//    if (fdf->proj.cabinet == true)
//        ft_cabinet(fdf);
//    else
//        ft_ismoetric(fdf);
    static int xx = 10;
    static int yy = 10;
    int u;
    int v;
    int x = 50;
    int y = 50;

//    u=(x-z)/sqrt(2);
//    v=(x+2*y+z)/sqrt(6);
    u = x*cos(120) + y*cos(120) + z*cos(120);
    v = x*sin(120) + y*sin(120) + z*sin(120);
    u += fdf->pos.x;
    v += fdf->pos.y;
    mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, u + xx, v + yy, 0xFF00);
    xx += 10;
    yy += 10;
    return 0;
}

int ft_fdf_draw(t_fdf *fdf)
{
    int i;
    int y;
    long *nptr;
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
            printf("%ld ", nptr[y]);
            ft_put_dot(nptr[y], fdf);
        }
        printf("\n");
        free(nptr);
    }
    close(fdf->input.fd);
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
//    for (int i = 0; i <= 200; ++i)
//        mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, i, 100, 0xFF00);
    return (0);
}