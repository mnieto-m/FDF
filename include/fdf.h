/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:05:57 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/27 19:48:06 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Libft/include/libft.h"
# include "MLX42/MLX42.h"
# include <math.h>

// agregar makefile carol

# define WIDTH 1080
# define HEIGHT 1920
# define INIT_SCALE 12

// TODO: poner los booleans bien
# define TRUE 0
# define FALSE 1
# define HEXADECIMAL "0123456789ABCDEF"
# define W_CENTER_DEFAULT 960.0
# define H_CENTER_DEFAULT 540.0

// struct mlx
typedef struct s_mini_mlx
{
	double		h_center_pt;
	double		w_center_pt;
	mlx_t		*mlx;
	void		*window;
	mlx_image_t	*img;
	void		*img_addr;

}				t_mlx;

typedef struct s_view
{
	double matrix_rot[9]; // on init it's an isometric
							// int scale;
							// int **translate;
}				t_view;

typedef struct s_node
{
	int			xyz[3];
	int			w_xyz[3];
	long		color;
}				t_node;

typedef struct s_map_mdata
{
	int			row;
	int			len_row;
	int max_value; // max_z
	int min_value; // min_z
	t_mlx		mlx;
	t_node *tab; // array of nodes
	t_view		view;
}				t_map;

// init map, read map
void			init_map_mlx(char *str, t_map *map);
int				read_map(char *str, t_map *map, int fd);

int				checkfile_fdf(char *str);
int				check_argv(int argc, char **argv);
int				ft_atoi_base(char *str, char *base_from);
void			ft_hook(void *param);
void			init_proyection(t_map *map);

// double			*matrix_pr_xy(t_map *map, double xyz[3]);
// double			*matrix_mult_square(t_map *map, double *m1, double *m2,
// double *rslt);
void			matrix_mult_pt(const int pt_o[3], int pt_rslt[3], double m[9]);
// double			*scale(t_map *map, int factor, double xyz[3]);
void			matrix_rot_isometric(t_view *view);
// double			*matrix_init(void);
// void			matrix_free(double *m);
// double			*matrix_mult_isometric(t_map *map, double *trans);

/* error ---------------------------------------------------- */
void			fdf_exit_error(char *str, t_map *map);
void			fdf_tmlx_free(t_mlx *mlx);
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

#endif

/* 3W test.c ./MLX42/build/libmlx42.a -IMLX42/include/MLX42 -ldl -lglfw
	-pthread
	-lm */