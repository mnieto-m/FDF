/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:49:11 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/27 19:59:57 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (check_argv(argc, argv))
		return (EXIT_FAILURE);
	init_map_mlx(argv[1], map);
	// Calcular la proyeccion de los puntos
	// init_proyection(map);
/* 	ft_print_img(map);
	ft_hook(map); */
	ft_free_screen(map);
	return (0);
}

/**
 * GENERICS:
 *  - para cada struct
 * 		- funcion para printear cada estructura (para hacer checks parciales)
 *  	- (en el caso de que haya variables malloqueadas) funcion para hacer free
 * - funcion de salida de error que haga el exit failure y llame al free (protegido)
 *
 * TENEMOS:
 * 	- Inicializado el mapa
 *  - Parseado el mapa
 *  - Inicializada la mlx
 * 
 * TODO:
 *  - Rellenar la mlx (revisar que hay que relenar?)
 *  - Bucle de renderizado que contendrá
 * 		- nota mental: init_projection(map) no existe, qué nombre habrá adquirido?
 * 		- Un primer calculo de la vista a mostrar (de primeras, puntos en planta)
 */