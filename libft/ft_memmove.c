/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:41:04 by mverger           #+#    #+#             */
/*   Updated: 2021/11/17 16:50:38 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *) src;
	d = (unsigned char *) dst;
	if (len == 0)
		return (dst);
	if (d > s)
	{
		len--;
		while (len > 0)
		{
			d[len] = s[len];
			len--;
		}
		d[0] = s[0];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/*int	main(void)
{
	char src[50] = "thanks to @apellicc for this test !\r\n";
	char dst[0xF0];
	
	printf("ft_memmove dst =%s\n", ft_memmove("", "" - 1, 0));
	//printf("memmove dst =%s\n", memmove("", "" - 1, 0));
	return (0);
}*/