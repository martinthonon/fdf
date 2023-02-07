#include "fdf.h"

int ft_resize(t_grid *grid)
{
    (void)grid;
//    if (grid->length >= win_length)
//        grid->length /= 1.5;
//    if (grid->width >= win_width)
//        grid->width /= 1.5;
    return 0;
}
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
            if (split[i][0] != '\n')
                grid->length++;
        grid->width++;
        ft_free("%p, %P", gnl, split);
        gnl = ft_get_next_line(fd);
    }
    return (ft_ret(NULL, fd, 0));
}