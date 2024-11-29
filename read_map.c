/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:00:27 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/11/29 17:00:32 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void read_map(char *str, t_map **map)
{
	char *buffer;
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		fail_read(str , map);
	while(1)
	{
		buffer = get_next_line(fd);
	}
}