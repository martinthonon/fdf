#include "fdf.h"



int ft_grid_size(int fd, t_grid *grid)
{
    char *gnl;
    char **split;
    int i;

    grid->width = 0;
    gnl = ft_get_next_line(fd);
    if (!gnl)
        return (1);
    while (gnl)
    {
        grid->length = 0;
        split = ft_split(gnl, ' ');
        if (!split)
            return (ft_free("%p", gnl) + 1);
        i = -1;
        while (split[++i])
        {
            if (split[i][0] != '\n')
                grid->length++;
        }
        grid->width++;
        ft_free("%p, %P", gnl, split);
        gnl = ft_get_next_line(fd);
    }
    return (ft_ret(NULL, fd, 0));
}

int ft_engine_init(char *str)
{
    t_grid grid;
    int fd;

    fd = open(str, O_RDONLY);
    if (fd < 0)
        return (1);
    if (ft_grid_size(fd, &grid))
        return (ft_ret(NULL, fd, 1));
    printf("length -> %d, width -> %d\n", grid.length, grid.width);

    return (0);
}