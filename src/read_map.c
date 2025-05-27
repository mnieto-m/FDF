/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:00:27 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/27 19:45:48 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	int		i;
	int		j;
	char	*str;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if ((l1 + l2) == 0)
		return (NULL);
	str = (malloc(sizeof(char) * (l1 + l2 + 1)));
	if (!str)
		return (NULL);
	str[l1 + l2] = '\0';
	i = -1;
	while (++i < (int)l1)
		str[i] = s1[i];
	free(s1);
	j = -1;
	while (++j < (int)l2)
		str[i++] = s2[j];
	free(s2);
	return (str);
}


/*void	set_value(char *str, t_map *map)
{
	int		value_x;
	int		value_y;
	int		value_z;
	long 	color;
	int		index;
	char	**aux;
	

	value_x = 0;
	value_z = 0;
	index = 0;
	aux = ft_split(str, ' ');
	while (value_x != (map)->row)
	{
		value_y = 0;
		index = value_x * (map)->len_row + value_y;
		while(value_y < (map)->len_row)
		{
			printf("perro\n");
			(map)->tab[index].xyz[0] = value_x;
			map->tab[index].xyz[1] = value_y;
			(map)->tab[index].xyz[2] = ft_atoi(aux[value_x]);
			if (ft_strchr(*aux,','))
			{
				color = ft_atoi_base(aux[value_x], HEXADECIMAL);
				printf("%zu", color);
			}
			else
			{
				color = ft_atoi_base("0xFFFFFF", HEXADECIMAL);
				printf("%zu", color);
			}
			value_y ++;
		}
		printf("\n");
		value_x++;
	}
}*/
static void set_value(char *str, t_map *map)
{
    int value_x = 0;
    int value_y = 0;
    int value_z = 0;
    long color = 0;
    int index = 0;
    char **aux;
    char **z_and_color;

    aux = ft_split(str, ' '); // Dividir la entrada en elementos separados por espacio
    if (!aux)
        return; // Manejar errores en caso de que ft_split falle

    // Usamos while para iterar sobre las filas y columnas
    while (value_x < map->row)
    {
        // Comenzar con la primera columna
        if (value_y < map->len_row)
        {
            index = value_x * map->len_row + value_y;

            // Dividir cada valor en coordenada Z y color si es necesario
            z_and_color = ft_split(aux[index], ','); // Accedemos al índice lineal
            value_z = ft_atoi(z_and_color[0]); // Obtener la coordenada Z

            if (z_and_color[1]) // Si hay un color explícito
                color = ft_atoi_base(z_and_color[1], HEXADECIMAL);
            else
                color = ft_atoi_base("0xFFFFFF", HEXADECIMAL); // Color por defecto

            // Liberar memoria del split intermedio
            free(z_and_color);

            // Asignar valores a la estructura
            map->tab[index].xyz[0] = value_x;
            map->tab[index].xyz[1] = value_y;
            map->tab[index].xyz[2] = value_z;
            map->tab[index].color = color;

            value_y++; // Avanzar a la siguiente columna
        }
        else
        {
            // Si llegamos al final de la fila, pasar a la siguiente
            value_y = 0;
            value_x++;
        }
    }

    // Liberar memoria de aux
    int i = 0;
    while (aux[i])
    {
        free(aux[i]);
        i++;
    }
    free(aux);
}


int	read_map(char *str, t_map *map, int fd)
{
	static char	*buffer;
	char		*aux;
	int			flag;

	flag = TRUE;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		fail_read(str, map);
	aux = get_next_line(fd);
	while (aux)
	{
		buffer = ft_strjoin_free(buffer, aux);
		aux = get_next_line(fd);
	}
	set_value(buffer, map);
	free(buffer);
	buffer = NULL;
	return (flag);
}

// repasar codigo no me acuerdo de nada :.....(
