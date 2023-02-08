#include "fdf.h"

int ft_len_check(char *str)
{
    int fd;
    int fl_len;
    int len;

    fd = open(str, O_RDONLY);
    if (fd < 0)
        return (1);
    len = ft_line_length(fd);
    if (len < 0)
        return (1);
    fl_len = len;
    while (len > 0)
    {
        if (fl_len != len)
            return (1);
        len = ft_line_length(fd);
    }
    if (len < 0)
        return (1);
    else
        return (ft_ret(NULL, fd, 0));
}

int ft_typo(int fd, int i, int y)
{
    char *gnl;
    char **split;

    gnl = ft_get_next_line(fd);
    if (!gnl)
        return (1);
    while (gnl)
    {
        split = ft_split(gnl, ' ');
        if (!split)
            return (ft_free("%p", gnl) + 1);
        i = -1;
        while (split[++i])
        {
            y = -1;
            while (split[i][++y])
                if (!ft_isdigit(split[i][y]) && split[i][y] != '\n' &&
                ft_is_neg(split[i], y))
                    return (ft_free("%p, %P", gnl, split) + 1);
        }
        ft_free("%p, %P", gnl, split);
        gnl = ft_get_next_line(fd);
    }
    return (ft_ret(NULL, fd, 0));
}

int ft_extension(char *path)
{
    char *cpy;
    cpy = ft_strrchr(path, '.');
    if (!cpy)
        return (1);
    if (ft_strncmp(cpy, ".fdf", 4))
        return (1);
    return (0);
}

int ft_file_checker(t_fdf *fdf)
{

    fdf->input.fd = open(fdf->input.path, O_RDONLY);
    if (fdf->input.fd < 0)
        return (ft_ret("File cannot be open\n", -1, 1));
    else if (ft_extension(fdf->input.path))
        return (ft_ret("wrong extension", fdf->input.fd, 1));
    else if (ft_typo(fdf->input.fd, 0, 0))
        return (ft_ret("empty file or incorrect typo\n", fdf->input.fd, 1));
    else if (ft_len_check(fdf->input.path))
        return (ft_ret("different line size\n", fdf->input.fd, 1));
    return (0);
}