/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:07:34 by mverger           #+#    #+#             */
/*   Updated: 2021/11/20 14:11:55 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	unsigned char	*str;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (char)c;
		i++;
	}
	return (b);
}

/*int	main(void)
{
	char str[4] = "kslls";
	
	printf("ft_memset = %s\n", ft_memset(str, '0', 4));
	printf("memset = %s\n", memset(str, '0', 4));
	
	return (0);
}*/