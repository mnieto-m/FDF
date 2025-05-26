/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:11:56 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/26 20:58:43 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
void ft_datai_init(t_map *map)
{
	ft_memset(map, 0 ,sizeof(t_map));
	map->mlx->h_center_pt = H_CENTER_DEFAULT;
	map->mlx->w_center_pt = W_CENTER_DEFAULT;
	map->mlx->mlx = mlx_init(WIDTH,HEIGHT,"FDF", 1);
	if(!map->mlx->mlx)
		ft_error(map);
	map->mlx->img = mlx_new_image(map->mlx->mlx, 256, 256);
	if(!map->mlx->img)
		ft_error(map);
		
}

void	init_map(char *str, t_map *map)
{
	int	fd;
	int	row;
	int	len_row;

	row = 0;
	len_row = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
	if (count_struct(&row, &len_row, fd) != TRUE)
		exit(EXIT_FAILURE);
	map = malloc(sizeof(t_map ) +  (row * len_row * sizeof(t_node)));
	if (!map)
		exit(EXIT_FAILURE);
	ft_datai_init(map);
	map->row = row;
	map->len_row = len_row;
	read_map(str, map, fd);
}


/*
- leer el mapa en char gigante split por espacio y luego comprobar que todas las lineas tenga el mismo numeor de columas 
- comprobar si son del mismo tamaño las mismas lineas 
- numeros no pueden dar overflow aka no tenga flow sean toys
- split por espacios por coma para color 


((t_node *[lenrow])map)[][];

*/