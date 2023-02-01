#include "fdf.h"



void ft_grid_size(int fd, int *length, int *width)
{
    char *gnl;
    char **split;

    *width = 0;
    gnl = ft_get_next_line(fd);
    while (gnl)
    {
        *length = 0;
        split = ft_split(gnl, ' ');
        while (*split)
        {
            if (**split != '\n')
                ++(*length);
            ++split;
        }
        ++(*width);
        gnl = ft_get_next_line(fd);
    }
}

int ft_engine_init(char *str, int *length, int *width)
{
    int fd;

    fd = open(str, O_RDONLY);
    if (fd < 0)
        return (1);
    ft_grid_size(fd, length, width);
    printf("length -> %d, width -> %d\n", *length, *width);

    return (0);
}