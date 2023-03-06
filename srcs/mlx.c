#include "fdf.h"

int ft_close(t_fdf *fdf)
{
    mlx_destroy_window(fdf->vars.mlx, fdf->vars.win);
    free(fdf->grid.input);
    exit(0);
}


int ft_keyboard(int input, t_fdf *fdf)
{
    if (input == key_w || input == key_s || input == key_a || input == key_d || input == key_enter || input == key_back)
        ft_move(input, fdf);
    else if (input == key_up || input == key_down || input == key_right || input == key_left)
        ft_rotation(input, fdf);
    else if (input == key_plus || input == key_min)
        ft_zoom(input, fdf);
    else if (input == key_i || input == key_c || input == key_r)
        ft_flag(input, fdf);
    else if (input == key_esc)
        ft_close(fdf);
    printf("%d\n", input);
    return (0);
}



int ft_windows_init(t_fdf *fdf)
{
    fdf->vars.mlx = mlx_init();
    fdf->vars.win = mlx_new_window(fdf->vars.mlx, win_length, win_width, "FDF");
    mlx_key_hook(fdf->vars.win, ft_keyboard, fdf);
    mlx_hook(fdf->vars.win, 17, 1L<<0, ft_close, fdf);
    return (0);
}
