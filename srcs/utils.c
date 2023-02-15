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

long	ft_atol(char *nptr)
{
    char				op;
    long long			tmp;
    long long			res;

    op = 1;
    while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
        ++nptr;
    if (*nptr == '-' || *nptr == '+')
    {
        if (*nptr == '-')
            op = -1;
        ++nptr;
    }
    res = 0;
    while (*nptr >= '0' && *nptr <= '9')
    {
        tmp = res;
        res = res * 10 + *nptr - '0';
        if (res < tmp)
            return (-(op == 1));
        ++nptr;
    }
    return (res * op);
}