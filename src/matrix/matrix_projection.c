#include "../include/fdf.h"

// double	*matrix_pr_xy(t_map *map, double xyz[3])
// {
// 	double	m[3][3];

// 	m[0][0] = 1;
// 	m[0][1] = 0;
// 	m[0][2] = 0;
// 	m[1][0] = 0;
// 	m[1][1] = 1;
// 	m[1][2] = 0;
// 	m[2][0] = 0;
// 	m[2][1] = 0;
// 	m[2][2] = 0;
// 	return (matrix_mult(map, m, xyz));
// }

//NOTE: do projections is a very good way to add different views (top, elevation, side) without much code