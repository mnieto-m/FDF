/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:25:55 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/27 19:21:04 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	*get_isometric(void)
{
	const double m[3][3] = {
		{(sqrt(3) / 2), 0, -(sqrt(3) / 2)},
		{1 / 2, 1, 1 / 2},
		{0, 0, 0}};
		//TODO: hacer la multiplicacion aqui, no podemos devolver m si no está malloqueada
		(void)m;
	return (NULL);
}

// double	*get_isometric(double xyz[3])
// {
// 	const double m[3][3] = {
// 		{(sqrt(3) / 2), 0, -(sqrt(3) / 2)},
// 		{1 / 2, 1, 1 / 2},
// 		{0, 0, 0}};
// 	return (matrix_mult(m, xyz));
// }

double *scale(t_map *map, int factor, double xyz[3])
{
	double m[3][3];
	m[0][0] = (double)factor;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = (double)factor;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = (double)factor;

	return (matrix_mult(map, m, xyz));
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
	matrix_mult_square(map,copy, iso, trans); 
	//free de copia
	matrix_free(copy);

	//lo mismo con la escala para tener la transformación final	
	return(0);
}