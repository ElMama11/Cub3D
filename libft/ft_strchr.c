/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:03:19 by mverger           #+#    #+#             */
/*   Updated: 2021/11/15 15:51:40 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	to_find;

	to_find = (unsigned char)c;
	if (to_find == '\0')
	{
		while (to_find != *s)
		{
			s++;
		}
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if (to_find == *s)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", strchr("tripouille", 't' + 256));
	printf("%s\n", ft_strchr("tripouille", 't' + 256));
	return (0);
}*/