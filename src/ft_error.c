/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:02:10 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/26 20:58:03 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
/* 
static void ft_free_map(t_node *tab,t_map *map)
{
	int i;
	
	i = 0;
	
	while(i < ((map)->len_row * (map)->row))
	{
		if(&tab[i])
			free(&tab[i]);
	}
	free(map);
} */
void fail_read(char *str, t_map *map)
{
	free(map);
	perror(str);
	exit(EXIT_FAILURE);
}
void ft_error(t_map *map)
{
	free(map);
	exit(EXIT_FAILURE);
}

int ft_free_screen(t_map *map)
{
	if(map)
	{
		
		if(map->mlx->img)
			mlx_delete_image(map->mlx->mlx, map->mlx->img);
		if(map->mlx->mlx)
			mlx_terminate(map->mlx->mlx);
/* 		if(map->tab)
			ft_free_map(&(map->tab) ,&map); */
	}
	exit(EXIT_FAILURE);
}