/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:11:56 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/09 13:42:48 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	count_struct(int *row, int *len_row, int fd)
{
	char	*buffer;
	int		flag;

	flag = TRUE;
	buffer = get_next_line(fd);
	if (buffer == NULL)
		return (flag = FALSE);
	*len_row = 0;
	*row = 0;
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
			idx = (x * map->len_row) + y;
			matrix_mult_pt(map->tab[idx].xyz, map->tab[idx].w_xyz,
				map->view.matrix_rot);
		}
	}
}

void	init_map_mlx(char *str, t_map **map)
{
	int	fd;
	int	row;
	int	len_row;

	row = 0;
	len_row = 0;
	fd = open(str, O_RDONLY);
	if (fd < 1)
		fdf_print_error(str);
	if (count_struct(&row, &len_row, fd) != TRUE)
		fdf_exit_error("Invalid map", NULL);
	*map = ft_calloc(1, sizeof(t_map) + sizeof(t_node) * row * len_row);
	if (!*map)
		exit(EXIT_FAILURE);
	fdf_tmap_init(row, len_row, *map);
	if (read_map(str, *map, fd) != TRUE)
		fdf_exit_error(NULL, *map);
	fdf_build_view_pts(*map);
	fdf_scale_view_pts(*map);
	fdf_traslation_view_pts(*map);
}
