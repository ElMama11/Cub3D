/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthibaul <jthibaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:12:37 by jthibaul          #+#    #+#             */
/*   Updated: 2022/03/17 15:58:47 by jthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

double	atof2_for_norm(char *str, double nb, int sign)
{
	int	i;

	i = 1;
	str++;
	while (*str && ft_isdigit(*str))
	{
		nb = (nb * 10) + (*str - '0');
		i *= 10;
		str++;
	}
	nb = nb / i;
	return (nb * sign);
}

double	ft_atof(char *str)
{
	double			nb;
	long long		i;
	int				sign;

	sign = 1;
	nb = 0;
	i = 0;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		nb = (nb * 10) + (*str - '0');
		i++;
		str++;
	}
	i = 1;
	if (*str == '.')
	{
		return (atof2_for_norm(str, nb, sign));
	}
	return (nb * sign);
}
