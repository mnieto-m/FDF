/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:12:04 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/26 20:56:56 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	check_argv(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!checkfile_fdf(argv[1]))
			return (EXIT_SUCCESS);
	}
	else if (argc != 2)
	{
		ft_putstr_fd(strerror(EINVAL), 1);
		if (argc > 2)
			ft_putstr_fd(": Too many arguments", 1);
		else if (argc < 2)
			ft_putstr_fd(": To less arguments", 1);
		ft_putstr_fd("\nCorrect imput: ./fdf <file.fdf>", 1);
	}
	return (EXIT_FAILURE);
}
