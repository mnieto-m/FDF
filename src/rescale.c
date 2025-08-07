
#include "../include/fdf.h"

void rescale(t_map *map, double scale)
{
	int x;
	int y;
	int idx;
	
	printf("rescale\n");
	x = -1;
	while(++x < map->row)
	{
		y = -1;
		while(++y < map->len_row)
		{
			idx = (x * map->len_row) + y;
			mult_init_scale(&map->tab[idx],scale);
		}
	}
	memset(map->img->pixels, 255, WIDTH * HEIGHT * sizeof(int32_t));
	fdf_traslate_view_pts(map);
	draw_map(map);
}
