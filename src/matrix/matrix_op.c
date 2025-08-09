/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:24:40 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/08 15:55:46 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	matrix_mult_pt(const int pt_o[3], double pt_rslt[3], double m[9])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		pt_rslt[i] = 0;
		while (++j < 3)
		{
			pt_rslt[i] += m[(i * 3) + j] * pt_o[j];
		}
	}
}

double	*matrix_mult_square(t_map *map, double *m1, double *m2, double *rslt)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->len_row)
		{
			k = -1;
			while (++k < 3)
			{
				rslt[i * map->len_row + j] += m1[i * map->len_row + j] * m2[j
					* map->len_row + i];
			}
		}
	}
	return (rslt);
}
