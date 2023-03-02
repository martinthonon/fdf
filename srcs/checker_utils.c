#include "fdf.h"

int ft_line_length(int fd)
{
    char *gnl;
    char **split;
    int len;
    int i;

    gnl = ft_get_next_line(fd);
    if (!gnl)
        return (ft_ret(NULL, fd, 0));
    split = ft_split(gnl, ' ');
    if (!split)
        return (free(gnl), ft_ret(NULL, fd, -1));
    if (split[0][0] == '\n')
        return (ft_free("%p, %P", gnl, split) + ft_ret(NULL, fd, -1));
    i = 0;
    len = 0;
    while (split[i])
        if (split[i++][0] != '\n')
            ++len;
    return (ft_free("%p, %P", gnl, split) + len);
}

int ft_is_neg(char *str, int j)
{
    if (str[j] == '-')
    {
        if (!ft_isdigit(str[j + 1]))
            return (1);
    }
    else if (!ft_isdigit(str[j]))
        return (1);
    return (0);
}
