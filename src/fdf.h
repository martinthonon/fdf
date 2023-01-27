#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h> // ATTENTION !!!
# include <mlx.h>
# include <stdarg.h>
# include "../lib/libft/libft.h"

typedef struct	s_vars {
    void	*mlx;
    void	*win;
}               t_vars;

typedef struct s_axis  {

    int x;
    int y;
    int z;

}               t_axis;

typedef struct s_grid {

    int length;
    int width;
    int height;
}               t_grid;

enum {
    scroll_backward = 4,
    scroll_forward = 5,
    click_right = 1,
    key_plus = 69,
    key_min = 78,
    key_esc = 53,
    key_w = 13,
    key_s = 1,
    key_d = 2,
    key_a = 0
};

int main(int argc, char **argv);
int ft_ret(char *str, int fd, int ret);
int ft_free(const char *formats, ...);
//int ft_input(int key_code, t_vars *vars);
int ft_line_length(int fd);
int ft_windows_init(t_vars *vars);
int ft_engine_init(char *str);
int ft_file_checker(char *str);
#endif
