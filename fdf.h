/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:05:57 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/11/29 17:23:57 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./Libft/libft.h"
/* # include <MLX42.h> */
// agregar makefile carol

# define WIDTH 1080
# define HEIGHT 1920

# define TRUE 0
# define FALSE 1

//struct mlx
/* typedef struct
{
	
} */

typedef struct snode
{
	int		value[3];
	int		print[2];
	int		color;
}			t_node;

typedef struct s_map_mdata
{
	size_t	row;
	size_t	len_row;
	size_t	max_value;
	size_t	min_value;
	t_node	*tab[];
}			t_map;

int			checkfile_fdf(char *str);
void		init_map(char *str, t_map **map);
int			check_argv(int argc, char **argv);
void		fail_read(char *str, t_map **map);

#endif

// 3W test.c ./MLX42/build/libmlx42.a -IMLX42/include/MLX42 -ldl -lglfw -pthread -lm