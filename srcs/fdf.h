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
    float space;
}               t_grid;

typedef struct s_type {

    int isometric;
    int cabinet;

}               t_type;

typedef struct s_file {

    int fd;
    char *path;
}               t_file;

typedef struct s_fdf {

    t_axis pos;
    t_vars vars;
    t_grid grid;
    t_type proj;
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
};

enum mouse {
    click_left = 1,
    scroll_backward = 4,
    scroll_forward = 5,
};

enum window {
    win_length = 1500,
    win_width = 1000,
};

int main(int argc, char **argv);

int ft_ret(char *str, int fd, int ret);
int ft_free(const char *formats, ...);

int ft_windows_init(t_fdf *fdf);
void ft_move(int input, t_fdf *fdf);
void ft_zoom(int input, t_fdf *fdf);
void ft_type(int input, t_fdf *fdf);
void ft_mlx_mouse(int input, t_fdf *fdf);

int ft_file_checker(t_fdf *fdf);
int ft_is_neg(char *str, int j);
int ft_line_length(int fd);

int ft_engine_init(t_fdf *fdf);
int ft_grid_size(t_fdf *fdf);
int ft_fdf_draw(t_fdf *fdf);
int *ft_node_val(t_fdf *fdf);
int ft_resize(t_fdf *fdf);

#endif
