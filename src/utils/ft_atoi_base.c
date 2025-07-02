/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:52:27 by mnieto-m          #+#    #+#             */
/*   Updated: 2025/07/02 22:03:00 by mnieto-m         ###   ########.fr       */
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

long	ft_atoi_base(char *str, char *base_from)
{
	int i;
	long nb;
	int power;
	int	base_len;
	int hex_base;
	
	hex_base  = 0;
	nb = 0;
	power = 1;
	base_len = ft_strlen(base_from);
	if (ft_strncmp(str, "0X", 2) == 0 || ft_strncmp(str, "0x", 2) == 0)
		hex_base = 2;
	i = ft_strlen(str) - 1;
	while (i >= hex_base)
	{
		if (ft_get_val(str[i], base_from) < 0)
			return (0);
		nb += ft_get_val(str[i], base_from) * power;
		power *= base_len;
		i--;
	}
	return (nb);
}
