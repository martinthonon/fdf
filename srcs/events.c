#include "fdf.h"

int ft_close(t_fdf *fdf)
{
    mlx_destroy_window(fdf->vars.mlx, fdf->vars.win);
    exit(0);
}


int ft_keyboard(int input, t_fdf *fdf)
{
    if (input == key_w || input == key_s || input == key_a || input == key_d)
//      ft_motion();
        printf("key code %d\n", input);
    else if (input == key_plus || input == key_min)
//      ft_resize();
        printf("up and down\n");
    else if (input == key_esc)
        ft_close(fdf);
    return (0);
}

int ft_mouse(int input, t_fdf *fdf)
{
    if (input == scroll_forward || input == scroll_backward)
//        ft_outlook();
        printf("scroll\n");
    else if (input == click_left)
        printf("click %p %d\n", fdf, input);;
    return (0);
}

int ft_windows_init(t_fdf *fdf)
{
    printf("windows init\n");

    fdf->vars.mlx = mlx_init();
    fdf->vars.win = mlx_new_window(fdf->vars.mlx, win_length, win_width, "FDF");
    mlx_key_hook(fdf->vars.win, ft_keyboard, fdf);
    mlx_mouse_hook(fdf->vars.win, ft_mouse, fdf);
    mlx_hook(fdf->vars.win, 17, 1L<<0, ft_close, fdf);
    return (0);
}
