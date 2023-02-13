#include "fdf.h"

int ft_resize(t_fdf *fdf)
{
    (void)fdf;
//    if (grid->length >= win_length)
//        grid->length /= 1.5;
//    if (grid->width >= win_width)
//        grid->width /= 1.5;
    return 0;
}
int ft_grid_size(t_fdf *fdf)
{
    char *gnl;
    char **split;

    fdf->input.fd = open(fdf->input.path, O_RDONLY);
    if (fdf->input.fd < 0)
        return (1);
    fdf->grid.length = 0;
    gnl = ft_get_next_line(fdf->input.fd);
    if (!gnl)
        return (1);
    while (gnl)
    {
        fdf->grid.length = 0;
        split = ft_split(gnl, ' ');
        if (!split)
            return (ft_free("%p", gnl) + 1);
        while (split[++fdf->grid.length]) // fdf grid length instead of int i
            if (split[fdf->grid.length][0] != '\n')
                fdf->grid.length++;
        fdf->grid.width++;
        ft_free("%p, %P", gnl, split);
        gnl = ft_get_next_line(fdf->input.fd);
    }
    return (ft_ret(NULL, fdf->input.fd, 0));
}

int *ft_node_val(t_fdf *fdf)
{
    char *gnl;
    char **split;
    int *nptr;
    int i;

    gnl = ft_get_next_line(fdf->input.fd);
    if (!gnl)
        return (NULL);
    split = ft_split(gnl, ' ');
    if (!split)
        return (ft_free("%p", gnl), NULL);
    nptr = malloc(sizeof(int) * fdf->grid.length);
    if (!nptr)
        return (ft_free("%p, %P", gnl, split), NULL);
    i = -1;
    while (split[++i] && split[i][0] != '\n')
    {
        nptr[i] = ft_atoi(split[i]);
    }
    return (ft_free("%p, %P", gnl, split), nptr);
}


