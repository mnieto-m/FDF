/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:49:11 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/02 22:17:22 by luciama2         ###   ########.fr       */
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
		printf("  w_xyz   = (%f, %f, %f)\n", node.w_xyz[0], node.w_xyz[1], node.w_xyz[2]);
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
	//print_nodes(map);
	fdf_mlx_init((map));
	//bucle de dibujado
	draw_map(map);
	fdf_loop(map);
	fdf_tmap_free(map);
	return (0);
}

/**
*TODO:
*	- HOOKS ESC
	- Cerrar ventana con la crucecita
	- COLORES
	- HOOK : ¿Rotacion?
	- HOOK : Zoom (escala)
	- HOOK : Pan/Move (trasladar)
*/
