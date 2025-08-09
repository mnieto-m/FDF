/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:06:14 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/08 16:07:05 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	ft_point_ini(t_temp *p, t_node p0)
{
	p->x = round(p0.w_xyz[0]);
	p->y = round(p0.w_xyz[1]);
}

int	pt_in_img(t_temp p)
{
	if (p.x < 0 || p.x >= WIDTH)
		return (0);
	if (p.y < 0 || p.y >= HEIGHT)
		return (0);
	return (1);
}

static void	ft_bresh_low(t_map *data, t_node p0, t_node p1)
{
	t_temp	d;
	t_temp	p;
	int		yi;
	int		diff;

	d.x = round(fabs(p1.w_xyz[0] - p0.w_xyz[0]));
	d.y = round(p1.w_xyz[1] - p0.w_xyz[1]);
	yi = d.y / fabs(d.y);
	d.y = fabs(d.y);
	diff = (2 * d.y) - d.x;
	ft_point_ini(&p, p0);
	while (p.x < round(p1.w_xyz[0]))
	{
		if (pt_in_img(p))
			mlx_put_pixel(data->img, p.x, p.y, 0);
		if (diff > 0)
		{
			p.y += yi;
			diff -= (2 * d.x);
		}
		diff += (2 * d.y);
		p.x += 1;
	}
}

static void	ft_bresh_high(t_map *data, t_node p0, t_node p1)
{
	t_temp	d;
	t_temp	p;
	int		xi;
	int		diff;

	d.x = round(p1.w_xyz[0] - p0.w_xyz[0]);
	d.y = round(fabs(p1.w_xyz[1] - p0.w_xyz[1]));
	xi = d.x / fabs(d.x);
	d.x = fabs(d.x);
	diff = (2 * d.x) - d.y;
	ft_point_ini(&p, p0);
	while (p.y < round(p1.w_xyz[1]))
	{
		if (pt_in_img(p))
			mlx_put_pixel(data->img, p.x, p.y, 0);
		if (diff > 0)
		{
			p.x += xi;
			diff -= (2 * d.y);
		}
		diff += (2 * d.x);
		p.y += 1;
	}
}

void	ft_bresenham(t_map *map, t_node p0, t_node p1)
{
	if (round(fabs(p1.w_xyz[1] - p0.w_xyz[1])) < round(fabs(p1.w_xyz[0]
				- p0.w_xyz[0])))
	{
		if (p0.w_xyz[0] > p1.w_xyz[0])
			ft_bresh_low(map, p1, p0);
		else
			ft_bresh_low(map, p0, p1);
	}
	else if (p0.w_xyz[1] > p1.w_xyz[1])
		ft_bresh_high(map, p1, p0);
	else
		ft_bresh_high(map, p0, p1);
}
