/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile_fdf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:59:01 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/11/08 18:05:32 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	checkfile_fdf(char *str)
{
	char *fdf;
	char *aux;
	size_t i;

	fdf = ".fdf";

	i = ft_strlen(str);
	aux = ft_strnstr(str, fdf, i);

	if (aux == &str[(i - 4)])
		return (EXIT_SUCCESS);
	ft_putstr_fd(strerror(EINVAL), 1);
	ft_putstr_fd("\nCorrect imput: ./fdf <file.fdf>", 1);
	return (EXIT_FAILURE);
}