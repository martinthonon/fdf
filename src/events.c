#include "fdf.h"

int ft_close(t_vars *vars)
{
    printf("test\n");
    mlx_destroy_window(vars->mlx, vars->win);
    printf("test 1\n");
    exit(0);
    return (0);
}


int ft_keyboard(int input, t_vars *vars)
{
    if (input == key_w || input == key_s || input == key_a || input == key_d)
//      ft_motion();
        printf("key code %d\n", input);
    else if (input == key_plus || input == key_min)
//      ft_resize();
        printf("up and down\n");
    else if (input == key_esc)
        ft_close(vars);
    return (0);
}

int ft_mouse(int input, t_vars *vars) //int x, y
{
    if (input == scroll_forward || input == scroll_backward)
//        ft_outlook();
        printf("scroll\n");
    else if (input == click_left)
        printf("click %p %d\n", vars, input);;
    return (0);
}

int ft_windows_init(t_vars *vars)
{
    printf("windows init\n");

    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, 1700, 1000, "FDF 42");
    mlx_key_hook(vars->win, ft_keyboard, vars);
    mlx_mouse_hook(vars->win, ft_mouse, vars);
    mlx_hook(vars->win, 17, 1L<<0, ft_close, vars);
    return (0);
}
