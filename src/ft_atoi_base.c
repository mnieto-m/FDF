/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:52:27 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/05/26 21:12:44 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		ft_get_val(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base_from)
{
	int i;
	int nb;
	int power;
	int	base_len;

	nb = 0;
	power = 1;
	base_len = ft_strlen(base_from);
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (ft_get_val(str[i], base_from) < 0)
			return (0);
		nb += ft_get_val(str[i], base_from) * power;
		power *= base_len;
		i--;
	}
	return (nb);
}
