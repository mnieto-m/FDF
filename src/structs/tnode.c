#include "../include/fdf.h"

/**
	{
		int			xyz[3];
		int			w_xyz[2];
		long		color;
	}
 *
 */

void	fdf_tnodes_print_xyz(int rows, int cols, t_node *nodes)
{
	int		x;
	int		y;
	int		idx;
	t_node	pt;

	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			idx = (x * rows) + y;
			pt = nodes[idx];
			printf("\t\t(%i,%i,%i), %li", pt.xyz[0], pt.xyz[1], pt.xyz[2],
				pt.color);
			y++;
		}
		printf("\n");
		x++;
	}
}

void	fdf_tnodes_print_w_xy(int rows, int cols, t_node *nodes)
{
	int		x;
	int		y;
	int		idx;
	t_node	pt;

	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			idx = (x * rows) + y;
			pt = nodes[idx];
			printf("\t\t(%i,%i,%i)", pt.w_xyz[0], pt.w_xyz[1], pt.w_xyz[2]);
			y++;
		}
		printf("\n");
		x++;
	}
}

void	fdf_tnode_init(int row, int col, char **inputs, t_map *map)
{
	int			idx;
	long long	color_comma_idx;
	int			z_flag;

	z_flag = 0;
	idx = (row * map->row) + col;
	color_comma_idx = ft_strchr(inputs[idx], ',') - inputs[idx]; // avoid split
	map->tab[idx].xyz[0] = row;
	map->tab[idx].xyz[1] = col;
	map->tab[idx].xyz[2] = ft_atoi_signal(inputs[idx], &z_flag); // Z_SCALE
	if (z_flag == -1)
		fdf_exit_error(NULL, map);
	if (color_comma_idx <= 0) // no color
		map->tab[idx].color = ft_atoi_base("0xFFFFFF", HEXADECIMAL);
	else
		map->tab[idx].color = ft_atoi_base(inputs[idx] + color_comma_idx,
				HEXADECIMAL);
}
