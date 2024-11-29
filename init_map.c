/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:11:56 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/11/29 17:21:07 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_struct(size_t *row, size_t *len_row, int fd)
{
	char	*buffer;
	int		flag;

	flag = 1;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		if (*row == 0)
			(*len_row) = check_token(buffer, ' ');
		else if ((*len_row) != check_token(buffer, ' '))
			flag = 0;
		(*row)++;
		free(buffer);
	}
	close(fd);
	return (flag);
}
void ft_datai_init(t_map **map)
{
	ft_memset((*map), 0 ,sizeof(t_map));
	
	
}

void	init_map(char *str, t_map **map)
{
	int	fd;
	size_t	row;
	size_t	len_row;

	row = 0;
	len_row = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
	if (count_struct(&row, &len_row, fd) != 0)
	{
		map = malloc(sizeof(t_map) * row * len_row);
		if (!map)
			exit(EXIT_FAILURE);
		(*map)->row = row;
		(*map)->len_row = len_row;

	}	
}


/*
- leer el mapa en char gigante split por espacio y luego comprobar que todas las lineas tenga el mismo numeor de columas 
- comprobar si son del mismo tamaño las mismas lineas 
- numeros no pueden dar overflow aka no tenga flow sean toys
- split por espacios por coma para color 


((t_node *[lenrow])map)[][];

*/