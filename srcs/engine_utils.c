#include "fdf.h"

int ft_get_node(t_fdf *fdf)
{
    int i;
    int j;
    int n_node;
    long *nptr;

    fdf->input.fd = open(fdf->input.path, O_RDONLY);
    if (fdf->input.fd < 0)
        return(1);
    n_node = fdf->grid.length * fdf->grid.width;
    fdf->grid.input = malloc(sizeof(long) * n_node);
    if (!fdf->grid.input)
        return (1);
    i = -1;
    while (++i < fdf->grid.width)
    {
        j = -1;
        nptr = ft_node_val(fdf);
        if (!nptr)
            return (1);
        while (++j < fdf->grid.length)
            fdf->grid.input[--n_node] = nptr[j];
        free(nptr);
    }
    close(fdf->input.fd);
    return (0);
}
int ft_grid_size(t_fdf *fdf)
{
    char *gnl;
    char **split;
    int i;

    fdf->input.fd = open(fdf->input.path, O_RDONLY);
    if (fdf->input.fd < 0)
        return (1);
    gnl = ft_get_next_line(fdf->input.fd);
    if (!gnl)
        return (1);
    while (gnl)
    {
        fdf->grid.length = 0;
        split = ft_split(gnl, ' ');
        if (!split)
            return (free(gnl), 1);
        i = -1;
        while (split[++i]) // fdf grid length instead of int i
            if (split[i][0] != '\n')
                ++fdf->grid.length;
        ++fdf->grid.width;
        ft_free("%p, %P", gnl, split);
        gnl = ft_get_next_line(fdf->input.fd);
    }
    return (ft_ret(NULL, fdf->input.fd, 0));
}

long *ft_node_val(t_fdf *fdf)
{
    char *gnl;
    char **split;
    long *nptr;
    int i;

    gnl = ft_get_next_line(fdf->input.fd);
    if (!gnl)
        return (NULL);
    split = ft_split(gnl, ' ');
    if (!split)
        return (free(gnl), NULL);
    printf("--------------------------------------------%d\n", fdf->grid.length);
    nptr = malloc(sizeof(long) * fdf->grid.length);
    if (!nptr)
        return (ft_free("%p, %P", gnl, split), NULL);
    i = -1;
    while (split[++i] && split[i][0] != '\n')
    {
        nptr[i] = ft_atol(split[i]);
        printf("%ld|", nptr[i]);
        if (nptr[i] > INT_MAX || nptr[i] < INT_MIN)
            return (NULL);
    }
    printf("\n");
    return (ft_free("%p, %P", gnl, split), nptr);
}


