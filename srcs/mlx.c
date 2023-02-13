#include "fdf.h"

int ft_close(t_fdf *fdf)
{
    mlx_destroy_window(fdf->vars.mlx, fdf->vars.win);
    exit(0);
}


int ft_keyboard(int input, t_fdf *fdf)
{
    if (input == key_esc)
        ft_close(fdf);
    else if (input == key_plus)
        fdf->pos.z += 20;
    else if (input == key_min)
        fdf->pos.z -= 20;
    else if (input == key_w)
        fdf->pos.y += 20;
    else if (input == key_s)
        fdf->pos.y -= 20;
    else if (input == key_d)
        fdf->pos.x += 20;
    else if (input == key_a)
        fdf->pos.x -= 20;
    else if (input == key_i)
    {
        fdf->proj.isometric = true;
        fdf->proj.cabinet = false;
    }
    else if (input == key_c)
    {
        fdf->proj.isometric = false;
        fdf->proj.cabinet = true;
    }
    return (ft_fdf_draw(fdf), 0);
}

int ft_mouse(int input, t_fdf *fdf)
{
    (void)fdf;
    if (input == scroll_forward || input == scroll_backward)
        printf("nothing here now\n");
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
