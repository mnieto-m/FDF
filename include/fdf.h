/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:05:57 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/07/22 15:25:32 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Libft/include/libft.h"
# include "MLX42/MLX42.h"
# include <math.h>
# include <errno.h>



# define WIDTH 1920
# define HEIGHT 1080
# define INIT_SCALE 5

// TODO: poner los booleans bien
# define TRUE 0
# define FALSE 1
# define HEXADECIMAL "0123456789ABCDEF"
# define hexadecimal "0123456789abcdef"
# define W_CENTER_DEFAULT 960.0
# define H_CENTER_DEFAULT 540.0

// struct mlx

typedef struct s_view
{
	double matrix_rot[9]; // on init it's an isometric
							// int scale;
							// int **translate;
}				t_view;

typedef struct s_node
{
	int			xyz[3];
	double		w_xyz[3];
	long		color;
}				t_node;
typedef struct s_temp
{
	double x;
	double y;
}			t_temp;

typedef struct s_map_mdata
{
	int			row;
	int			len_row;
	double		h_center_pt;
	double		w_center_pt;
	void		*window;
	void		*img_addr;
	
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_view		view;
	t_node tab[]; // array of nodes
}				t_map;

// init map, read map
void			init_map_mlx(char *str, t_map **map);
int				read_map(char *str, t_map *map, int fd);

int				checkfile_fdf(char *str);
int				check_argv(int argc, char **argv);
long				ft_atoi_base(char *str, char *base_from);
void			ft_hook(t_map *map);
void			init_proyection(t_map *map);

// double			*matrix_pr_xy(t_map *map, double xyz[3]);
// double			*matrix_mult_square(t_map *map, double *m1, double *m2,
// double *rslt);
void			matrix_mult_pt(const int pt_o[3], double pt_rslt[3], double m[9]);
// double			*scale(t_map *map, int factor, double xyz[3]);
void			matrix_rot_isometric(t_view *view);
// double			*matrix_init(void);
// void			matrix_free(double *m);
// double			*matrix_mult_isometric(t_map *map, double *trans);

/* error ---------------------------------------------------- */
void			fdf_exit_error(char *str, t_map *map);
void	fdf_print_error(char *str);
void			fdf_tmlx_free(t_map *map);
// void			fail_read(char *str, t_map *map);

/* struct utils --------------------------------------------- */
void			fdf_tmap_init(int row_count, int col_count, t_map *map);
void			fdf_tmap_free(t_map *map);
void			fdf_tmap_print(t_map *map);
void			fdf_tnodes_print_xyz(int rows, int cols, t_node *node);
void			fdf_tnodes_print_w_xy(int rows, int cols, t_node *nodes);
void			fdf_tnode_init(int row, int col, char **input, t_map *map);
void			fdf_tview_init(t_view *vw);
void			fdf_tview_print(t_view *view);

void ft_bresenham(t_map *map, t_node p0, t_node p1 );
void fdf_mlx_init(t_map *map);
void draw_map(t_map *map);
#endif

/* 3W test.c ./MLX42/build/libmlx42.a -IMLX42/include/MLX42 -ldl -lglfw
	-pthread
	-lm */