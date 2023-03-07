/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:00:42 by mathonon          #+#    #+#             */
/*   Updated: 2023/03/07 16:24:11 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <stdarg.h>
# include "../lib/libft/libft.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_axis {
	int	x;
	int	y;
	int	z;
}				t_axis;

typedef struct s_grid {
	int		length;
	int		width;
	int		height;
	long	*input;
	t_axis	angle;
	t_axis	space;
}				t_grid;

typedef struct s_flag {
	int	rotation;
	int	angle;
	int	isometric;
	int	cabinet;

}				t_flag;

typedef struct s_file {
	int		fd;
	char	*path;
}				t_file;

typedef struct s_line {
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}				t_line;

typedef struct s_fdf {
	t_axis	*pos;
	t_axis	move;
	t_axis	origin;
	t_vars	vars;
	t_grid	grid;
	t_flag	flag;
	t_file	input;
	t_line	line;
}				t_fdf;

enum	e_boolean {
	false,
	true,
};

enum e_keyboard {
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
	key_enter = 36,
	key_back = 51,
};

enum	e_window{
	win_length = 1920,
	win_width = 1080,
};

int		main(int argc, char **argv);

int		ft_ret(char *str, int fd, int ret);
int		ft_free(const char *formats, ...);
long	ft_atol(char *nptr);
double	rad(int degree);

int		ft_windows_init(t_fdf *fdf);
void	ft_move(int input, t_fdf *fdf);
void	ft_rotation(int input, t_fdf *fdf);
void	ft_zoom(int input, t_fdf *fdf);
void	ft_flag(int input, t_fdf *fdf);

int		ft_file_checker(t_fdf *fdf);
int		ft_is_neg(char *str, int j);
int		ft_line_length(int fd);

int		ft_engine_init(t_fdf *fdf);
int		ft_grid_size(t_fdf *fdf);
int		ft_fdf_draw(t_fdf *fdf);
long	*ft_node_val(t_fdf *fdf);
void	ft_draw_line(t_fdf *fdf);
int		ft_isometric(int n_node, t_fdf *fdf);
int		ft_get_node(t_fdf *fdf);

#endif
