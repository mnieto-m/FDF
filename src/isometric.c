/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:25:55 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/02/11 20:52:34 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	*get_isometric(void)
{
	const double m[3][3] = {
		{(sqrt(3) / 2), 0, -(sqrt(3) / 2)},
		{1 / 2, 1, 1 / 2},
		{0, 0, 0}};
	return (m);
}

// double	*get_isometric(double xyz[3])
// {
// 	const double m[3][3] = {
// 		{(sqrt(3) / 2), 0, -(sqrt(3) / 2)},
// 		{1 / 2, 1, 1 / 2},
// 		{0, 0, 0}};
// 	return (matrix_mult(m, xyz));
// }

double *scale(int factor, double xyz[3])
{
	const m[3][3] = {
		{factor, 0, 0},
		{0, factor, 0},
		{0, 0, factor}
	};
	return (matrix_mult(m, xyz));
}



double *matrix_mult_isometric(t_map *map, double *trans)
{
	double *copy;
	double *iso;
	int i ;
	int j;
	
	copy = matrix_init();
	if(!copy)
		return(NULL);
		
	i = 0;
	while(i < map->row) //row count
	{
		j = 0;
		while(j < map->len_row) //column or row length count
		{
			copy[i * map->len_row + j] = trans[i * map->len_row + j];
		}
	}
	iso = get_isometric(); //no está malloqueada
	//malloc de copia
	matrix_mult_square(copy, iso, trans); 
	//free de copia
	matrix_free(copy);

	//lo mismo con la escala para tener la transformación final	
	
}