/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:00:27 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/05 19:23:01 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
char	*ft_strjoin_free(char *s1, char *s2)
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

int read_map(char *str, t_map **map, int fd)
{
	static char *buffer;
	char *aux;
	int flag;

	flag = TRUE;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		fail_read(str , map);
	aux = get_next_line(fd);
	while(aux)
	{
		buffer = ft_strjoin_free(buffer, aux);
		aux = get_next_line(fd);
	}
	if (!set_number(buffer, map))
		flag = FALSE;
	free(buffer);
	return(flag);
}


int set_number(char *str, t_map **map)
{
	int i;
	int flag ;

	i = 0;
	ft_split(str, ' ');
	ft_atoi_signal(str, &flag);

	return(i + 1);
	
}