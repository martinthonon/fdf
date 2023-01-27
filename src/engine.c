#include "fdf.h"



//void ft_grid_size(int fd)
//{
//    char *gnl;
//    char **split;
//    int length;
//    int height;
//    height = 0;
//    gnl = ft_get_next_line(fd);
//    while (gnl)
//    {
//        length = 0;
//        split = ft_split(gnl, ' ');
//        while (*split)
//        {
//            if (**split != '\n')
//                ++length;
//            ++split;
//        }
//        ++height;
//        gnl = ft_get_next_line(fd);
//    }
//}

int ft_engine_init(char *str)
{
    (void)str;
    int length = 0;
    int height = 0;

//    ft_grid_size(fd);
    printf("length : %d  height : %d\n", length, height);


    return (0);
}