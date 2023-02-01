#include "fdf.h"

int ft_ret(char *str, int fd, int ret)
{
    if (str)
        write(1, str, ft_strlen(str));
    if (fd >= 0)
        close(fd);
    return (ret);
}

int ft_free(const char *formats, ...)
{
    va_list ap;
    int i;
    void **dptr;

    va_start(ap, formats);
    while (*formats)
    {
        if (*formats == '%')
        {
            ++formats;
            if (*formats == 'p')
                free(va_arg(ap, void *));
            else if (*formats == 'P')
            {
                dptr = va_arg(ap, void **);
                i = 0;
                while (dptr[i])
                    free(dptr[i++]);
                free(dptr);
            }
        }
            ++formats;
    }
    va_end(ap);
    return (0);
}

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
        return (ft_free("%p", gnl) + ft_ret(NULL, fd, -1));
    if (split[0][0] == '\n')
        return (ft_free("%p, %P", gnl, split) + ft_ret(NULL, fd, -1));
    i = 0;
    len = 0;
    while (split[i])
        if (split[i++][0] != '\n')
            ++len;
    printf("%d\n", len);
    return (ft_free("%p, %P", gnl, split) + len);
}

int ft_is_neg(char *str, int y)
{
    if (str[y] == '-')
    {
        if (!ft_isdigit(str[y + 1]))
            return (1);
    }
    else if (!ft_isdigit(str[y]))
        return (1);
    return (0);
}