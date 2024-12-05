/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:05:57 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/12/05 19:22:41 by mnieto-m         ###   ########.fr       */
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
	int		color;
}			t_node;

typedef struct s_map_mdata
{
	size_t	row;
	size_t	len_row;
	size_t	max_value;
	size_t	min_value;
	t_mlx	*mini_mlx;
	t_node	*tab[];
}			t_map;

int			checkfile_fdf(char *str);
void		init_map(char *str,t_map **map);
int			check_argv(int argc, char **argv);
void		fail_read(char *str, t_map **map);
int		read_map(char *str, t_map **map , int fd);
int 	set_number(char *str, t_map **map);
#endif

// 3W test.c ./MLX42/build/libmlx42.a -IMLX42/include/MLX42 -ldl -lglfw -pthread -lm