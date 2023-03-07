/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathonon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:04:11 by mathonon          #+#    #+#             */
/*   Updated: 2023/03/07 15:53:25 by mathonon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham(t_axis *xy1, t_axis *xy2, t_fdf *fdf)
{
	fdf->line.dx = abs(xy2->x - xy1->x);
	fdf->line.dy = abs(xy2->y - xy1->y);
	fdf->line.sx = 1;
	if (xy1->x >= xy2->x)
		fdf->line.sx = -1;
	fdf->line.sy = 1;
	if (xy1->y >= xy2->y)
		fdf->line.sy = -1;
	fdf->line.err = fdf->line.dx - fdf->line.dy;
	while (xy1->x != xy2->x || xy1->y != xy2->y)
	{
		mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, xy1->x, xy1->y, 0x0000FF00);
		fdf->line.e2 = fdf->line.err * 2;
		if (fdf->line.e2 > -fdf->line.dy)
		{
			fdf->line.err -= fdf->line.dy;
			xy1->x += fdf->line.sx;
		}
		if (fdf->line.e2 < fdf->line.dx)
		{
			fdf->line.err += fdf->line.dx;
			xy1->y += fdf->line.sy;
		}
	}
	mlx_pixel_put(fdf->vars.mlx, fdf->vars.win, xy1->x, xy1->y, 0x0000FF00);
}

static void	ft_draw_line2(t_axis *xy1, t_axis *xy2, t_fdf *fdf)
{
	int	node_up;
	int	n_node;
	int	i;
	int	j;

	node_up = fdf->grid.length;
	n_node = (fdf->grid.length * fdf->grid.width) - 1;
	i = 0;
	while (++i <= fdf->grid.length)
	{
		j = 0;
		while (++j < fdf->grid.width)
		{
			xy1->x = fdf->pos[n_node].x;
			xy1->y = fdf->pos[n_node].y;
			xy2->x = fdf->pos[n_node - node_up].x;
			xy2->y = fdf->pos[n_node - node_up].y;
			ft_bresenham(xy1, xy2, fdf);
			--n_node;
		}
	}
	free(fdf->pos);
}

void	ft_draw_line(t_fdf *fdf)
{
	t_axis	xy1;
	t_axis	xy2;
	int		n_node;
	int		i;
	int		j;

	n_node = (fdf->grid.length * fdf->grid.width) - 1;
	i = 0;
	while (++i <= fdf->grid.width)
	{
		j = 0;
		while (++j < fdf->grid.length)
		{
			xy1.x = fdf->pos[n_node].x;
			xy1.y = fdf->pos[n_node].y;
			xy2.x = fdf->pos[n_node - 1].x;
			xy2.y = fdf->pos[n_node - 1].y;
			ft_bresenham(&xy1, &xy2, fdf);
			--n_node;
		}
		--n_node;
	}
	ft_draw_line2(&xy1, &xy2, fdf);
}
