/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tnode.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:03:33 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/09 12:18:20 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	fdf_tnode_init(int row, int col, char **inputs, t_map *map)
{
	int			idx;
	long long	color_comma_idx;
	int			z_flag;
	char		*comma_ptr;

	z_flag = 0;
	idx = (row * map->len_row) + col;
	map->tab[idx].xyz[0] = row;
	map->tab[idx].xyz[1] = col;
	map->tab[idx].xyz[2] = ft_atoi_signal(inputs[idx], &z_flag);
	if (z_flag == -1)
		fdf_exit_error(NULL, map);
	comma_ptr = ft_strchr(inputs[idx], ',');
	if (!comma_ptr)
		map->tab[idx].color = ft_atoi_base("0XFFFFFF", HEXADECIMAL);
	else
	{
		color_comma_idx = comma_ptr - inputs[idx];
		if (ft_strncmp(inputs[idx] + color_comma_idx + 1, "0X", 2) == 0)
			map->tab[idx].color = ft_atoi_base(inputs[idx] + color_comma_idx
					+ 1, HEXADECIMAL);
		else
			map->tab[idx].color = ft_atoi_base(inputs[idx] + color_comma_idx
					+ 1, hexadecimal);
	}
}
