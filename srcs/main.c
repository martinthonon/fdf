#include "fdf.h"

int main(int argc, char **argv)
{
    t_fdf fdf;

    if (argc != 2)
        return (ft_ret("Wrong number of arguments\n", -1, 0));
    else if (ft_file_checker(argv[1]))
        return (ft_ret("Input failed file checker\n", -1, 0));
    else if (ft_windows_init(&fdf))
        return (ft_ret("Windows cannot be init\n", -1, 0));
    else if (ft_engine_init(argv[1], &fdf))
        return (ft_ret("Grid cannot be init\n", -1, 0));
    system("leaks fdf");
    mlx_loop(fdf.vars.mlx);
    return (0);
}