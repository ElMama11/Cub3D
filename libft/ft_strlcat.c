/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:43:57 by mverger           #+#    #+#             */
/*   Updated: 2021/11/17 15:07:45 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	i;
	size_t	j;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	while (dst[i] && i < dstsize)
		i++;
	while (src[j] && i < dstsize - 1)
		dst[i++] = src[j++];
	if (dstsize != 0 && dstsize >= len_dst)
		dst[i] = '\0';
	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	else
		return (ft_strlen(src) + len_dst);
}

/*int	main(void)
{
	char str[15] = "bout";
	char dst[9] = "Mara";

	//printf("ft_strlcat return = %lu et dst = %s\n", ft_strlcat(dst, str, 9), dst);
	printf("strlcat return = %lu et dst = %s\n", strlcat(dst, str, 2), dst);
	return (0);
}*/
