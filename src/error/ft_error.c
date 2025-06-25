/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:02:10 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/27 19:51:15 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*
static void	ft_free_map(t_node *tab,t_map *map)
{
	int	i;

	i = 0;
	while(i < ((map)->len_row * (map)->row))
	{
		if(&tab[i])
			free(&tab[i]);
	}
	free(map);
} */
// NOTE: can be static
void	fdf_print_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

// NOTE: delete
// void	fail_read(char *str, t_map *map)
// {
// 	if (map)
// 		free(map); // FREE t_node y t_mlx antes
// 	perror(str);
// 	exit(EXIT_FAILURE);
// }

void	fdf_exit_error(char *str, t_map *map)
{
	if (map)
		free(map); // FREE t_node y t_mlx antes
	if (str)
		fdf_print_error(str);
	exit(EXIT_FAILURE);
}

void	fdf_tmlx_free(t_mlx *mlx)
{
	if (mlx->img)
		mlx_delete_image(mlx->mlx, mlx->img);
	if (mlx->mlx)
		mlx_terminate(mlx->mlx);
}