#include "../include/fdf.h"


void draw_map(t_map *map)
{
	int	x;
	int	y;
	int idx;

	x = -1;
	y = -1;
	while(++x < map->row)
	{
		y= -1;
		while(++y < map->len_row)
		{
			idx = (x * map->len_row) + y;
			if (x < (map->row - 1))
					ft_bresenham(map, map->tab[idx], map->tab[idx + map->len_row]);//data->map_plot[i + 1][j]);
			if (y < (map->len_row - 1))
					ft_bresenham(map, map->tab[idx], map->tab[idx + 1]);//data->map_plot[i][j + 1]);
		}
	}
	mlx_image_to_window(map->mlx, map->img, 100, 100);
}
