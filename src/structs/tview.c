#include "../include/fdf.h"

void	fdf_tview_init(t_view *vw)
{
	matrix_rot_isometric(vw);
}


void fdf_tview_print(t_view *view)
{
	int i;
	int j;
	printf("view status:\n");
	printf("\trotation matrix:\n");
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			printf("\t\t(%f)", view->matrix_rot[(i * 3) + j]);
		printf("\n");
	}
}
