#include "fdf.h"

int ft_close(t_fdf *fdf)
{
    mlx_destroy_window(fdf->vars.mlx, fdf->vars.win);
    exit(0);
}


int ft_keyboard(int input, t_fdf *fdf)
{

    if (input == key_w || input == key_s || input == key_a || input == key_d)
        ft_move(input, fdf);
    else if (input == key_plus || input == key_min)
        ft_zoom(input, fdf);
    else if (input == key_i || input == key_c)
        ft_type(input, fdf);
    else if (input == key_esc)
        ft_close(fdf);
    return (0);
}

int ft_mouse(int input, t_fdf *fdf)
{
    if (input == scroll_forward)
    {
        printf("scroll forward\n"); //outlook
        ft_mlx_mouse(input, fdf);
//        ft_fdf_draw(fdf);
    }
    else if (input == scroll_backward)
    {
        printf("scroll backward\n");
        ft_fdf_draw(fdf);
    }
    return (0);
}

int ft_windows_init(t_fdf *fdf)
{
    fdf->vars.mlx = mlx_init();
    fdf->vars.win = mlx_new_window(fdf->vars.mlx, win_length, win_width, "FDF");
    mlx_key_hook(fdf->vars.win, ft_keyboard, fdf);
    mlx_mouse_hook(fdf->vars.win, ft_mouse, fdf);
    mlx_hook(fdf->vars.win, 17, 1L<<0, ft_close, fdf);
    return (0);
}
