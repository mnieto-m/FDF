/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:49:11 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/26 21:36:34 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"


int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (check_argv(argc, argv))
		return (EXIT_FAILURE);
	init_map(argv[1], map);
	// Calcular la proyeccion de los puntos
	// init_proyection(map);
/* 	ft_print_img(map);
	ft_hook(map); */
	ft_free_screen(map);
	return (0);
}
