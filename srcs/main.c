#include "fdf.h"

void ft_fdf_init(t_fdf *fdf, char *path)
{
    fdf->move.x = 0;
    fdf->move.y = 0;
    fdf->grid.length = 0;
    fdf->grid.width = 0;
    fdf->origin.x = 100;
    fdf->origin.y = 100;
    fdf->flag.angle = 20;
    fdf->grid.angle.x = 30;
    fdf->grid.angle.y = 30;
    fdf->grid.space.x = 10;
    fdf->grid.space.y = 10;
    fdf->flag.isometric = true;
    fdf->flag.cabinet = false;
    fdf->flag.rotation = false;
    fdf->input.fd = -1;
    fdf->input.path = path;
}
int main(int argc, char **argv)
{
    t_fdf fdf;

    if (argc == 2)
    {
        ft_fdf_init(&fdf, argv[1]);
        if (ft_file_checker(&fdf))
            return (write(1, "Input failed file checker\n", 27), 0);
        else if (ft_windows_init(&fdf))
            return (write(1, "Windows cannot be init\n", 24), 0);
        else if (ft_engine_init(&fdf))
            return (write(1, "Grid cannot be init\n", 21), 0);
    }
    else
        return (write(1, "Wrong number of arguments\n", 27), 0);
    mlx_loop(fdf.vars.mlx);
    return (0);
}