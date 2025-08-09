/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:49:11 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/09 11:21:44 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (check_argv(argc, argv))
		return (EXIT_FAILURE);
	init_map_mlx(argv[1], &map);
	fdf_mlx_init((map));
	draw_map(map);
	fdf_loop(map);
	fdf_exit_esc(map);
	return (0);
}
