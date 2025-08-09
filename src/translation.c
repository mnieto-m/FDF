/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:38:01 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/09 11:41:45 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	find_max_min(t_map *map, t_temp *min, t_temp *max)
{
	int	idx;
	int	total_nodes;

	total_nodes = map->row * map->len_row;
	idx = -1;
	min->x = DBL_MAX;
	min->y = -DBL_MAX;
	max->x = -DBL_MAX;
	max->y = DBL_MAX;
	while (++idx < total_nodes)
	{
		if (map->tab[idx].w_xyz[0] < min->x)
			min->x = map->tab[idx].w_xyz[0];
		if (map->tab[idx].w_xyz[0] > max->x)
			max->x = map->tab[idx].w_xyz[0];
		if (map->tab[idx].w_xyz[1] > min->y)
			min->y = map->tab[idx].w_xyz[1];
		if (map->tab[idx].w_xyz[1] < max->y)
			max->y = map->tab[idx].w_xyz[1];
	}
}

t_temp	traslation_diff(t_map *map)
{
	t_temp	rst;
	t_temp	min;
	t_temp	max;

	find_max_min(map, &min, &max);
	rst.x = (max.x + min.x) / 2;
	rst.y = (max.y + min.y) / 2;
	rst.x = (double)W_CENTER_DEFAULT - rst.x;
	rst.y = (double)H_CENTER_DEFAULT - rst.y;
	return (rst);
}

void	fdf_traslation_view_pts(t_map *map)
{
	int		row;
	int		col;
	int		idx;
	t_temp	traslation;

	row = -1;
	traslation = traslation_diff(map);
	while (++row < map->row)
	{
		col = -1;
		while (++col < map->len_row)
		{
			idx = (row * map->len_row) + col;
			map->tab[idx].w_xyz[0] += traslation.x;
			map->tab[idx].w_xyz[1] += traslation.y;
		}
	}
}
