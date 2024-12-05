/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:49:11 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/05 17:53:35 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	
	if (check_argv(argc, argv))
		return(EXIT_FAILURE);
	init_map(argv[1], &map);
	
	return (0);
}
