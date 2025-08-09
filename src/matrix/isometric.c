/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:25:55 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/08/08 15:54:36 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	matrix_rot_isometric(t_view *view)
{
	view->matrix_rot[0] = -(sqrt(3) / 2);
	view->matrix_rot[1] = (sqrt(3) / 2);
	view->matrix_rot[2] = 0;
	view->matrix_rot[3] = 0.5;
	view->matrix_rot[4] = 0.5;
	view->matrix_rot[5] = -1;
	view->matrix_rot[6] = 0;
	view->matrix_rot[7] = 0;
	view->matrix_rot[8] = 0;
	return ;
}
