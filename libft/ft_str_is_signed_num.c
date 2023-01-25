/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_signed_num.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthibaul <jthibaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 08:56:04 by jthibaul          #+#    #+#             */
/*   Updated: 2022/04/13 09:30:04 by jthibaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_signed_num(char *src)
{
	int	i;

	i = 0;
	if (src[0] == '-' || src[0] == '+')
		i++;
	while (src && src[i])
	{
		if (! (src[i] >= 'a' && src[i] <= 'z')
				|| (src[i] >= 'A' && src[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}