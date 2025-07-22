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
void fdf_mlx_init(t_map *map)
{

	map->h_center_pt = H_CENTER_DEFAULT;
	map->w_center_pt = W_CENTER_DEFAULT;
	map->mlx = mlx_init(WIDTH,HEIGHT,"FDF",1) ;
	if(!map->mlx)
	{
		ft_putstr_fd((char* )mlx_strerror(mlx_errno),1);
		fdf_tmlx_free(map);
	}
	map->img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if(!map->img)
	{
		ft_putstr_fd((char* )mlx_strerror(mlx_errno),1);
		fdf_tmlx_free(map);
	}
	memset(map->img->pixels, 255, WIDTH * HEIGHT * sizeof(int32_t));

}
void	fdf_tmap_init(int row_count, int col_count, t_map *map)
{
	(map)->row = row_count;
	(map)->len_row = col_count;
	fdf_tview_init(&map->view);
}

void	fdf_tmap_free(t_map *map)
{

	if((map)->mlx != NULL)
		fdf_tmlx_free((map));
	free(map);
	map = NULL;
	exit(EXIT_FAILURE);
}

void	fdf_tmap_print(t_map *map)
{
	printf("tmap satus:\n");
	printf("\trow:\t\t%i\n", map->row);
	printf("\tlen_row:\t%i\n", map->len_row);
	printf("node array input:\n");
	fdf_tnodes_print_xyz(map->row, map->len_row, map->tab);
	printf("node array window\n");
	fdf_tnodes_print_w_xy(map->row, map->len_row, map->tab);
	fdf_tview_print(&map->view);
}
