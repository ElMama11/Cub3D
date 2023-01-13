/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:50:23 by mverger           #+#    #+#             */
/*   Updated: 2021/11/09 16:37:36 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_count;
	size_t	i;

	src_count = 0;
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
			src_count++;
		}
		dst[i] = '\0';
	}
	while (src[src_count])
		src_count++;
	return (src_count);
}

/*int	main(void)
{
	char	src[15] = "Marabout";
	char	dst[15] = "nop";

	printf("strlcpy return = %lu et dst = %s\n", strlcpy(dst, src, 0), dst);
	printf("ft_strlcpy return = %lu et dst = %s\n", ft_strlcpy(dst, src, 0), dst);
	return (0);
}*/
