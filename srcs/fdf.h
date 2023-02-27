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

    float x;
    float y;
    float z;
}               t_axis;

typedef struct s_grid {

    int length;
    int width;
    int height;
    long *input;
    t_axis angle;
    t_axis space;
}               t_grid;

typedef struct s_flag {

    int rotation;
    int isometric;
    int cabinet;

}               t_flag;

typedef struct s_file {

    int fd;
    char *path;
}               t_file;

typedef struct s_fdf {

    t_axis pos;
    t_vars vars;
    t_grid grid;
    t_list *head;
    t_flag flag;
    t_file input;
}               t_fdf;

enum boolean {
    false,
    true,
};

enum keyboard {
    key_esc = 53,
    key_plus = 69,
    key_min = 78,
    key_w = 13,
    key_s = 1,
    key_d = 2,
    key_a = 0,
    key_i = 34,
    key_c = 8,
    key_r = 15,
    key_up = 126,
    key_down = 125,
    key_left = 123,
    key_right = 124,
};

enum window {
    win_length = 1920,
    win_width = 1080,
};

int main(int argc, char **argv);

int ft_ret(char *str, int fd, int ret);
int ft_free(const char *formats, ...);
long	ft_atol(char *nptr);

int ft_windows_init(t_fdf *fdf);
void ft_move(int input, t_fdf *fdf);
void ft_rotation(int input, t_fdf *fdf);
void ft_zoom(int input, t_fdf *fdf);
void ft_flag(int input, t_fdf *fdf);

int ft_file_checker(t_fdf *fdf);
int ft_is_neg(char *str, int j);
int ft_line_length(int fd);

int ft_engine_init(t_fdf *fdf);
int ft_grid_size(t_fdf *fdf);
int ft_fdf_draw(t_fdf *fdf);
long *ft_node_val(t_fdf *fdf);
//int ft_put_dot(int z, t_fdf *fdf);
int ft_put_dot(int x, int y, int z, t_fdf *fdf);
int ft_get_node(t_fdf *fdf);

#endif
