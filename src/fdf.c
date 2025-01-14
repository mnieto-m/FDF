/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:49:11 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/01/14 17:55:05 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	
	map = NULL;
	if (check_argv(argc, argv))
		return(EXIT_FAILURE);
	init_map(argv[1], map);
	ft_init_mlx();
	
	mlx_terminate(map->mini_mlx->mlx);
	free(map);
	
	return (0);
}
