/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:27:09 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/09 11:41:06 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	mult_init_scale(t_node *node, double scale)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		node->w_xyz[i] *= scale;
	}
}

void	fdf_scale_view_pts(t_map *map)
{
	int	x;
	int	y;
	int	idx;

	map->scale = 1.0;
	x = -1;
	while (++x < map->row)
	{
		y = -1;
		while (++y < map->len_row)
		{
			idx = (x * map->len_row) + y;
			mult_init_scale(&map->tab[idx], INIT_SCALE);
		}
	}
}
