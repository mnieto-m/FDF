/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:19:20 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/07 20:25:20 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


void handle_move(t_map *map)
{
	(void)map;
	/* 	if (mlx_is_key_down(param, MLX_KEY_UP))
		???return();
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		????return();
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		????return();
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		????return(); */
}

void handle_zoom(double xdelta, double ydelta, void *data)
{
	t_map *map;
	map = data;
	printf("x:%f, y:%f\n", xdelta, ydelta);
	if (ydelta > 0)
		map->scale += 0.1;
	else
		map->scale -= 0.1;
	printf("map->scale:%f, y:%f\n", map->scale, ydelta);
	rescale(map,map->scale);//disminurir la escala ;

}

void ft_key_hook(void *data)
{
	t_map *map = data;
	printf("key hook\n");
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		fdf_exit_error(NULL,map);
	//handle_move(map);
	//dibujar
}


void fdf_loop(t_map *map)
{
	(void)map;
	printf("loop de renderizado\n");
	mlx_loop_hook(map->mlx, ft_key_hook, map);
	mlx_scroll_hook(map->mlx,(mlx_scrollfunc)handle_zoom, map);
	mlx_loop(map->mlx);
}  
