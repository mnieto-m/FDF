#include "../include/fdf.h"

/**
	{
		int			xyz[3];
		int			w_xyz[2];
		long		color;
	}
 *
 */

void	fdf_tnode_print(t_node node)
{
	printf("tnode status:\n");
	printf("(x,y,x):\t(%i,%i,%i)\n", node.xyz[0], node.xyz[1], node.xyz[2]);
	printf("win(x,y):\t(%i,%i,%i)\n", node.w_xyz[0], node.w_xyz[1]);
	printf("color:\t(%i)\n", node.color);
}

void	fdf_tnodes_print_xyz(int rows, int cols, t_node *nodes)
{
	int	x;
	int	y;
	int	idx;

	x = 0;
	while (x < rows)
	{
		while (y < cols)
		{
			idx =  (x * rows) + y;
			printf("\t(%i,%i,%i)", nodes[idx].xyz[0], nodes[idx].xyz[1], nodes[idx].xyz[2]);
			y++;
		}
		printf("\n");
		x++;
	}
}
