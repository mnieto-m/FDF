/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:02:10 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/08 15:54:16 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_print_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	fdf_exit_esc(t_map *map)
{
	if (map == NULL)
		exit(EXIT_FAILURE);
	if (map->mlx != NULL)
		fdf_tmlx_free(map);
	if (map || map != NULL)
		free(map);
	exit(EXIT_SUCCESS);
}

void	fdf_exit_error(char *str, t_map *map)
{
	if (map == NULL)
		exit(EXIT_FAILURE);
	if (map->mlx != NULL)
		fdf_tmlx_free(map);
	if (map || map != NULL)
		free(map);
	if (str)
		fdf_print_error(str);
	exit(EXIT_FAILURE);
}

void	fdf_tmlx_free(t_map *map)
{
	if (map->img != NULL)
		mlx_delete_image(map->mlx, map->img);
	if (map->mlx != NULL)
		mlx_terminate(map->mlx);
}
