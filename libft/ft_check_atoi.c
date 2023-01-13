/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palamede13 <palamede13@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:20:27 by jthibaul          #+#    #+#             */
/*   Updated: 2022/07/04 15:31:31 by palamede13       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	if return (1) str != nb */
int	check(char *str, int nb)
{
	int	i;
	int	temp;

	temp = nb;
	i = 1;
	while (temp > 9)
	{
		temp = temp % 10;
		i = i * 10;
	}
	while (*str && i > 0)
	{
		if (*str == ((nb / i) % 10) + '0')
			str++;
		else
			return (1);
		i = i / 10;
		str++;
	}
	return (0);
}

int	check_atoi(char *str, int nb)
{
	if (nb < 0)
	{
		if (*str != '-')
			return (1);
		else
		{
			str++;
			nb *= -1;
		}
	}
	if (check(str, nb))
		return (1);
	return (0);
}
