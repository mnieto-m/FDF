/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:19:20 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/09 12:11:07 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	handle_zoom(double xdelta, double ydelta, void *data)
{
	t_map	*map;

	map = data;
	if (ydelta > 0 || xdelta > 0)
		map->scale += 0.05;
	else
		map->scale -= 0.05;
	rescale(map, map->scale);
}

void	ft_key_hook(void *data)
{
	t_map	*map;

	map = data;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		fdf_exit_esc(map);
	if (mlx_is_key_down(map->mlx, MLX_KEY_M))
	{
		map->scale -= 0.05;
		rescale(map, map->scale);
	}
	if (mlx_is_key_down(map->mlx, MLX_KEY_N))
	{
		map->scale += 0.05;
		rescale(map, map->scale);
	}
}

void	fdf_loop(t_map *map)
{
	mlx_loop_hook(map->mlx, ft_key_hook, map);
	mlx_scroll_hook(map->mlx, (mlx_scrollfunc)handle_zoom, map);
	mlx_loop(map->mlx);
}
