/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:11:56 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/27 19:51:42 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief Reads the file on fd, and saves the nbr of rows and cols
 *
 * @param row
 * @param len_row
 * @param fd
 * @return int
 */
static int	count_struct(int *row, int *len_row, int fd)
{
	char	*buffer;
	int		flag;

	flag = TRUE;
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (*row == 0)
			(*len_row) = check_token(buffer, ' ');
		else if ((*len_row) != check_token(buffer, ' '))
			flag = FALSE;
		(*row)++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	return (flag);
}

static void	fdf_build_view_pts(t_map *map)
{
	int	x;
	int	y;
	int	idx;

	x = -1;
	while (++x < map->row)
	{
		y = -1;
		while (++y < map->len_row)
		{
			idx = (x * map->row) + y;
			matrix_mult_pt(map->tab[idx].xyz, map->tab[idx].w_xyz,
				map->view.matrix_rot);
		}
	}
}

void	init_map_mlx(char *str, t_map *map)
{
	int	fd;
	int	row;
	int	len_row;

	row = 0;
	len_row = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		fdf_exit_error(NULL, map); // map en null
	// NOTE: len_row is col
	// NOTE: int *row can be directly &(map->row) (the same for col)
	if (count_struct(&row, &len_row, fd) != TRUE)
		fdf_exit_error(NULL, map); // map es null
	fdf_tmap_init(row, len_row, map);
	if (read_map(str, map, fd) != TRUE)
		fdf_exit_error(NULL, map);
	fdf_build_view_pts(map);
	// CHECK
	fdf_tmap_print(map);
}

/*
- leer el mapa en char gigante split por espacio y luego comprobar que todas las lineas tenga el mismo numeor de columas
- comprobar si son del mismo tamaño las mismas lineas
- numeros no pueden dar overflow aka no tenga flow sean toys
- split por espacios por coma para color
((t_node *[lenrow])map)[][];
*/