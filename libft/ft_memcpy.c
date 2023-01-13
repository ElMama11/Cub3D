/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:28:38 by mverger           #+#    #+#             */
/*   Updated: 2021/11/15 15:59:17 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *) src;
	b = (unsigned char *) dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*b++ = *a++;
		i++;
	}
	return (dst);
}

/*int	main(void)
{
	char *dst = NULL;
	char *src = NULL;
	printf("dst = %s\n", ft_memcpy(dst, src, 6));
	printf("dst = %s\n", memcpy(dst, src, 6));
	return (0);
}*/
