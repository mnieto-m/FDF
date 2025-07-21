/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:49:11 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/07/21 16:34:41 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * rows
 * tab es un un array unidireccional
 *
 */

void print_nodes(t_map *map)
{
	int i;
	int total = map->row * map->len_row;

	printf("=== Lista de nodos ===\n");
	for (i = 0; i < total; i++)
	{
		t_node node = map->tab[i];
		printf("Nodo [%d]:\n", i);
		printf("  xyz     = (%d, %d, %d)\n", node.xyz[0], node.xyz[1], node.xyz[2]);
		printf("  w_xyz   = (%d, %d, %d)\n", node.w_xyz[0], node.w_xyz[1], node.w_xyz[2]);
		printf("  color   = 0x%06lx\n", node.color);
	}
	printf("=======================\n");
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (check_argv(argc, argv))
		return (EXIT_FAILURE);
	
	init_map_mlx(argv[1], &map);
	//draw_map(map); esto hay que descomentarlo
	print_nodes(map);
	mlx_loop(map->mlx);
	//ft_hook(map);
	fdf_tmap_free(map);
	return (0);
}
/**
 * GENERICS:
 *  - para cada struct
 * 		- funcion para printear cada estructura (para hacer checks parciales)
 *  	- (en el caso de que haya variables malloqueadas) funcion para hacer free
 *
	- funcion de salida de error que haga el exit failure y llame al free (protegido)
 *
 * TENEMOS:
 * 	- Inicializado el mapa
 *  - Parseado el mapa
 *  - Inicializada la mlx
 *
 * TODO:
 *  - Rellenar la mlx (revisar que hay que relenar?)
 *  - Bucle de renderizado que contendrá
 * 		- nota mental: init_projection(map) no existe,
			qué nombre habrá adquirido?
 * 		- Un primer calculo de la vista a mostrar (de primeras,
			puntos en planta)
 */