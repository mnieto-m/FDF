/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:20:52 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/09 11:20:53 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_map(t_map *map)
{
	int	x;
	int	y;
	int	idx;

	x = -1;
	y = -1;
	while (++x < map->row)
	{
		y = -1;
		while (++y < map->len_row)
		{
			idx = (x * map->len_row) + y;
			if (x < (map->row - 1))
				ft_bresenham(map, map->tab[idx], map->tab[idx + map->len_row]);
			if (y < (map->len_row - 1))
				ft_bresenham(map, map->tab[idx], map->tab[idx + 1]);
		}
	}
	mlx_image_to_window(map->mlx, map->img, 0, 0);
}
