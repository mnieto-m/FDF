/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:00:27 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/08 16:01:19 by mnieto-m         ###   ########.fr       */
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
	str = (ft_calloc(sizeof(char), (l1 + l2 + 1)));
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

static void	set_value(char *str, t_map *map)
{
	int		i;
	int		row;
	int		col;
	char	**aux;

	aux = ft_split_str(str, "\n ");
	if (!aux)
		fdf_exit_error(NULL, map);
	row = -1;
	while (++row < map->row)
	{
		col = -1;
		while (++col < map->len_row)
		{
			fdf_tnode_init(row, col, aux, map);
		}
	}
	i = -1;
	while (aux[++i])
		free(aux[i]);
	free(aux);
}

int	read_map(char *str, t_map *map, int fd)
{
	static char	*buffer;
	char		*aux;
	int			flag;

	flag = TRUE;
	fd = open(str, O_RDONLY);
	if (fd < 1)
		fdf_exit_error(NULL, map);
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
