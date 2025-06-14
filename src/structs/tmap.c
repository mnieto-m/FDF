#include "../include/fdf.h"

/**
 * {
		int			row;
		int			len_row;
		int			max_value;
		int			min_value;
		t_mlx		*mlx;
		t_node		tab[];
	}
 */

void	fdf_tmap_init(int row_count, int col_count, t_map *map)
{
	ft_memset(map, 0, sizeof(t_map));
	// INIT MLX
	map->mlx->h_center_pt = H_CENTER_DEFAULT;
	map->mlx->w_center_pt = W_CENTER_DEFAULT;
	map->mlx->mlx = mlx_init(WIDTH, HEIGHT, "FDF", 1);
	if (!map->mlx->mlx)
		return (fdf_exit_error(NULL, map));
	map->mlx->img = mlx_new_image(map->mlx->mlx, 256, 256);
	if (!map->mlx->img)
		return (fdf_exit_error(NULL, map));
	map->row = row_count;
	map->len_row = col_count;
}

void	fdf_tmap_free(t_map *map)
{
	if (map->mlx)
		return ; // fdf_tmlx_free(map->mlx); //TODO
}

void	fdf_tmap_print(t_map *map)
{
	printf("tmap satus:\n");
	printf("\trow:\t%i\n", map->row);
	printf("\tlen_row:\t%i\n", map->len_row);
	printf("\tmax_value:\t%i\n", map->max_value);
	printf("\tmin_value:\t%i\n", map->min_value);
	printf("node array input:");
	fdf_tnodes_print_xyz(map->row, map->len_row, map->tab);
	printf("node array window");
	fdf_tnodes_print_w_xy(map->row, map->len_row, map->tab);
}
