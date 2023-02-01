#include "fdf.h"



void ft_grid_size(int fd, t_grid *grid)
{
    char *gnl;
    char **split;

    grid->width = 0;
    gnl = ft_get_next_line(fd);
    while (gnl)
    {
        grid->length = 0;
        split = ft_split(gnl, ' ');
        while (*split)
        {
            if (**split != '\n')
                grid->length++;
            ++split;
        }
        grid->width++;
        gnl = ft_get_next_line(fd);
    }
}

int ft_engine_init(char *str)
{
    t_grid grid;
    int fd;

    fd = open(str, O_RDONLY);
    if (fd < 0)
        return (1);
    ft_grid_size(fd, &grid);
    printf("length -> %d, width -> %d\n", grid.length, grid.width);

    return (0);
}