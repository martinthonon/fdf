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
//    if (vars)
//        printf("!");
    //(void)vars;
    if (input == key_w || input == key_s || input == key_a || input == key_d)
//      ft_motion();
        printf("key code %d\n", input);
    else if (input == key_plus || input == key_min)
//      ft_();
        printf("up and down\n");
    else if (input == key_esc)
        ft_close(vars);
    return (0);
}

int ft_mouse(int input, t_vars *vars)
{
//    (void)vars;
    if (input == scroll_forward || input == scroll_backward)
//        ft_outlook();
        printf("scroll\n");
    else if (input == click_left)
        printf("click %p\n", vars); // to print adress
    return (0);
}

int ft_windows_init(t_vars *vars)
{

    printf("windows init\n");

    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, 640, 480, "FDF 42");
    mlx_key_hook(vars->win, ft_keyboard, vars);
    mlx_mouse_hook(vars->win, ft_mouse, vars);
    return (0);
}
