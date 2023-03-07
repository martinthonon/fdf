/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:10:17 by mathonon          #+#    #+#             */
/*   Updated: 2023/03/06 16:14:45 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_move(int input, t_fdf *fdf)
{
	if (input == key_w)
		fdf->move.y -= 20;
	else if (input == key_s)
		fdf->move.y += 20;
	else if (input == key_a)
		fdf->move.x -= 20;
	else if (input == key_d)
		fdf->move.x += 20;
	else if (input == key_enter)
		fdf->move.z += 20;
	else if (input == key_back)
		fdf->move.z -= 20;
	ft_fdf_draw(fdf);
}

void	ft_zoom(int input, t_fdf *fdf)
{
	if (input == key_plus)
	{
		fdf->grid.space.x += 1;
		fdf->grid.space.y += 1;
	}
	else if (input == key_min)
	{
		fdf->grid.space.x -= 1;
		fdf->grid.space.y -= 1;
	}
	ft_fdf_draw(fdf);
}

void	ft_rotation(int input, t_fdf *fdf)
{
	if (fdf->flag.rotation == true)
	{
		if (input == key_up)
			fdf->grid.angle.y -= 1;
		else if (input == key_down)
			fdf->grid.angle.y += 1;
		else if (input == key_left)
			fdf->grid.angle.x += 1;
		else if (input == key_right)
			fdf->grid.angle.x -= 1;
		ft_fdf_draw(fdf);
	}
}

void	ft_flag(int input, t_fdf *fdf)
{
	if (input == key_r)
	{
		if (fdf->flag.rotation == true)
			fdf->flag.rotation = false;
		else
			fdf->flag.rotation = true;
	}
}
