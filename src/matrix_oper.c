/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:24:40 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/26 21:35:36 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	*matrix_mult(t_map *map, double m[3][3], double pt[3])
{
	int		i;
	int		j;
	double	*rslt;

	rslt = ft_calloc(1, 3 * sizeof(double));
	if (!rslt)
		return (NULL);
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->len_row)
		{
			rslt[i] += m[i][j] * pt[j];
		}
	}
	return (rslt);
}
// esto esta mal ??!!!!!
double	*matrix_mult_square(t_map *map, double *m1, double *m2, double *rslt)
{
	int	i;
	int	j;
	int	k;

	// double	rslt[3][3];
	// rslt = ft_calloc(1, 3 * 3 * sizeof(double));
	// if (!rslt)
	// 	return (NULL);
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->len_row)
		{
			k = -1;
			// rslt[i][j] = 0;
			while (++k < 3)
			{
				rslt[i * map->len_row + j] += m1[i * map->len_row + j] * m2[j
					* map->len_row + i];
			}
		}
	}
	return (rslt);
}

// double	*matrix_mult_sq(double m1[3][3], double m2[3][3])
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	double	rslt[3][3];
// 	rslt = ft_calloc(1, 3 * 3 * sizeof(double));
// 	if (!rslt)
// 		return (NULL);
// 	i = -1;
// 	while (++i < 3)
// 	{
// 		j = -1;
// 		while (++j < 3)
// 		{
// 			k = -1;
// 			rslt[i][j] = 0;
// 			while (++k < 3)
// 			{
// 				rslt[i][j] += m1[i][k] * m2[k][j];
// 			}
// 		}
// 	}
// 	return (rslt);
// }

double	*xy_projection(t_map *map, double xyz[3])
{
	double	m[3][3];

	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 0;
	return (matrix_mult(map, m, xyz));
}

double	*matrix_init(void)
{
	double	*rslt;

	rslt = ft_calloc(1, 3 * 3 * sizeof(double *));
	if (!rslt)
		return (NULL);
	return (rslt);
}

void	matrix_free(double *m)
{
	if (m)
	{
		free(m);
		m = NULL;
	}
	return ;
}