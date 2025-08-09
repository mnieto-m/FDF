/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:27:18 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/09 11:40:26 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rescale(t_map *map, double scale)
{
	int	x;
	int	y;
	int	idx;

	x = -1;
	while (++x < map->row)
	{
		y = -1;
		while (++y < map->len_row)
		{
			idx = (x * map->len_row) + y;
			mult_init_scale(&map->tab[idx], scale);
		}
	}
	memset(map->img->pixels, 255, WIDTH * HEIGHT * sizeof(int32_t));
	fdf_traslation_view_pts(map);
	draw_map(map);
}
