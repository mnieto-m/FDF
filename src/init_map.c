/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:11:56 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/07/29 21:43:07 by mario            ###   ########.fr       */
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
	if(buffer == NULL)
		return(flag = FALSE);
	*len_row = 0;
	*row = 0;
	while (buffer)
	{
		if (*row == 0)
		{
			//printf( "COLUMNAS vacias:%ls\n",len_row);
			(*len_row) = check_token(buffer, ' ');
			//printf( "COLUMNAS check_token:%d\n",(check_token(buffer, ' ')));
		}
		else if ((*len_row) != check_token(buffer, ' '))
			flag = FALSE;
		//printf( "FILAS ACTUALES:%d\n",(*row));
		(*row)++;
		//printf("AUMENTO FILAS:%d\n",(*row));
		free(buffer);
		buffer = get_next_line(fd);
		//printf( "COLUMNAS FINALES:%d\n",(*len_row));
	}
	//printf( "FILAS FINALES:%d\n",(*row));
	//printf( "COLUMNAS FINALES:%d\n",(*len_row));
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
void mult_init_scale(t_node *node, int scale)
{
	int i;

	i = -1;
	while(++i < 3)
	{
		node->w_xyz[i] *= scale;
	}
	
}
void fdf_escale_view_pts(t_map *map)
{
	int x;
	int y;
	int idx;
	
	x = -1;
	while(++x < map->row)
	{
		y = -1;
		while(++y < map->len_row)
		{
			idx = (x * map->len_row) + y;
			mult_init_scale(&map->tab[idx],INIT_SCALE);
		}
	}
}
void find_max_min(t_map *map, t_temp *min, t_temp *max)
{
	int idx;
	int total_nodes;

	total_nodes = map->row * map->len_row;
	idx = -1;

	min->x = DBL_MAX;
	min->y = -DBL_MAX;
	max->x = -DBL_MAX;
	max->y = DBL_MAX;


	while (++idx < total_nodes)
	{
		if (map->tab[idx].w_xyz[0] < min->x)
			min->x = map->tab[idx].w_xyz[0];
		if (map->tab[idx].w_xyz[0] > max->x)
			max->x = map->tab[idx].w_xyz[0];

		if (map->tab[idx].w_xyz[1] > min->y)
			min->y = map->tab[idx].w_xyz[1];
		if (map->tab[idx].w_xyz[1] < max->y)
			max->y = map->tab[idx].w_xyz[1];

	}
}

t_temp traslation_diff(t_map *map)
{
	t_temp rst;
	t_temp min;
	t_temp max;
	
	find_max_min(map, &min, &max);
	rst.x = (max.x + min.x)/2;
	rst.y = (max.y + min.y)/2;
	//printf("x:%i,y:%i\n",map->row,map->len_row);
	//printf("x:%f,y:%f\n",rst.x,rst.y);

	rst.x = (double)W_CENTER_DEFAULT - rst.x;
	rst.y =(double) H_CENTER_DEFAULT - rst.y ;
	return(rst);	
}
void fdf_traslate_view_pts(t_map *map)
{
	int row;
	int col;
	int idx;
	t_temp traslation;
	
	row = -1;

	traslation = traslation_diff(map);
	//printf("row:%f,colum:%f\n",traslation.x,traslation.y);
	while(++row < map->row)
	{
		col = -1;
		while(++col < map->len_row)
		{
			idx = (row * map->len_row) + col;
			map->tab[idx].w_xyz[0] += traslation.x;
			map->tab[idx].w_xyz[1] += traslation.y;
		}
	}	
}
void 	init_map_mlx(char *str, t_map **map)
{
	int	fd;
	int	row;
	int	len_row;
	

	row = 0;
	len_row = 0;
	fd = open(str, O_RDONLY);
	if (fd < 1)
		fdf_print_error(str); // map en null
	// NOTE: len_row is col
	// NOTE: int *row can be directly &(map->row) (the same for col)
	if (count_struct(&row, &len_row, fd) != TRUE)
		fdf_exit_error(NULL, NULL); // map es null
	*map = ft_calloc(1, sizeof(t_map) + sizeof(t_node) * row * len_row);
	if (!*map)
		return ;
	fdf_tmap_init(row, len_row, *map);
	if (read_map(str, *map, fd) != TRUE)
		fdf_exit_error(NULL, *map);
	fdf_build_view_pts(*map);
	
	fdf_escale_view_pts(*map);
	//print_nodes(*map);
	fdf_traslate_view_pts(*map);

	// CHECK
	//fdf_tmap_print(*map);
}

/*
- leer el mapa en char gigante split por espacio y luego comprobar que todas las lineas tenga el mismo numeor de columas
- comprobar si son del mismo tamaño las mismas lineas
- numeros no pueden dar overflow aka no tenga flow sean toys
- split por espacios por coma para color
((t_node *[lenrow])map)[][];
*/