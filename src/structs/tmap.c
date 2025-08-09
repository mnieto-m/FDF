/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:01:42 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/08 16:04:07 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_mlx_init(t_map *map)
{
	map->h_center_pt = H_CENTER_DEFAULT;
	map->w_center_pt = W_CENTER_DEFAULT;
	map->mlx = mlx_init(WIDTH, HEIGHT, "FDF", 1);
	if (!map->mlx)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 1);
		fdf_tmlx_free(map);
	}
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->img)
	{
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 1);
		fdf_tmlx_free(map);
	}
	memset(map->img->pixels, 255, WIDTH * HEIGHT * sizeof(int32_t));
}

void	fdf_tmap_init(int row_count, int col_count, t_map *map)
{
	(map)->row = row_count;
	(map)->len_row = col_count;
	fdf_tview_init(&map->view);
}
