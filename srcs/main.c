#include "fdf.h"

void ft_fdf_init(t_fdf *fdf, char *path)
{
    fdf->pos.x = 0;
    fdf->pos.y = 0;
    fdf->pos.z = 0;
    fdf->vars.mlx = NULL;
    fdf->vars.win = NULL;
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
            return (ft_ret("Input failed file checker\n", -1, 0));
        else if (ft_windows_init(&fdf))
            return (ft_ret("Windows cannot be init\n", -1, 0));
        else if (ft_engine_init(&fdf))
            return (ft_ret("Grid cannot be init\n", -1, 0));
    }
    else
        return (ft_ret("Wrong number of arguments\n", -1, 0));
    system("leaks fdf");
    mlx_loop(fdf.vars.mlx);
    return (0);
}