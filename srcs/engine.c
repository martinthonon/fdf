#include "fdf.h"


int ft_put_dot(int x, int y, int z, t_fdf *fdf)
{
//    if (fdf->proj.cabinet == true)
//        ft_cabinet(fdf);
//    else
//        ft_ismoetric(fdf);
    float u; //x
    float v; //y

    mlx_clear_window(fdf->vars.mlx, fdf->vars.win);

//    fdf->pos.x = cos(45)

//    u = cos(45) * (y - 1080 / 2) - cos(45) * (x - 1920 / 2);
//    v = -z * cos(45*2) + sin(45) * (x - 1920 / 2) + sin(45) * (y - 1080 / 2);
//    u=(x-z)/sqrt(2);
//    v=(x+2*y+z)/sqrt(6);
//    rtn.x = cos(deg_to_rad(angle)) * (y - fdf->map.size.y / 2) - cos(deg_to_rad(angle)) * (x - fdf->map.size.x / 2);
    u = x * cos(fdf->grid.angle.x) + y * cos(fdf->grid.angle.x + 30) + z * cos(fdf->grid.angle.x - 30);
    v = x * sin(fdf->grid.angle.y) + y * sin(fdf->grid.angle.y + 30) + z * sin(fdf->grid.angle.y - 30);


    u += fdf->pos.x;
    v += fdf->pos.y;

    mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, u + x, v + y, 0xFF00);
    return 0;
}

int ft_fdf_draw(t_fdf *fdf)
{
    int surface;
    int i;
    int j;
    int x;
    int y;

    y = 100;
    i = -1;
    surface = fdf->grid.length * fdf->grid.width;
    while (++i < fdf->grid.width)
    {
        j = -1;
        x = 100;
        while (++j < fdf->grid.length)
        {
            printf("%ld ", fdf->grid.input[surface]);
            ft_put_dot(x, y, fdf->grid.input[--surface], fdf);
            //x += 10;
            x += fdf->grid.space.x;
        }
        y += fdf->grid.space.y;
        printf("\n");
    }
    return (0);
}

int ft_engine_init(t_fdf *fdf)
{
    if (ft_grid_size(fdf))
        return (ft_ret(NULL, fdf->input.fd, 1));
    else if (ft_get_node(fdf)) //make malloc of len * height in fdf->gid.input
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