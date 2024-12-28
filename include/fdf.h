/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:05:57 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/28 18:11:36 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Libft/include/libft.h"
/* # include <MLX42.h> */
// agregar makefile carol

# define WIDTH 1080
# define HEIGHT 1920

# define TRUE 0
# define FALSE 1
# define HEXADECIMAL "0123456789ABCDEF"

//struct mlx
typedef struct s_mini_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img_addr;
}			t_mlx;

typedef struct s_node
{
	int		xyz[3];
	int		w_xyz[2];
	long	color;
}			t_node;

typedef struct s_map_mdata
{
	int	row;
	int	len_row;
	int	max_value;
	int	min_value;
	t_mlx	*mini_mlx;
	t_node	tab[];
}			t_map;

int			checkfile_fdf(char *str);
void		init_map(char *str,t_map *map);
int			check_argv(int argc, char **argv);
void		fail_read(char *str, t_map *map);
int		read_map(char *str, t_map *map , int fd);
int 	set_number(char *str, t_map *map);
int				ft_atoi_base(char *str, char *base_from);

#endif

// 3W test.c ./MLX42/build/libmlx42.a -IMLX42/include/MLX42 -ldl -lglfw -pthread -lm