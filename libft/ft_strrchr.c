/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:35:34 by mverger           #+#    #+#             */
/*   Updated: 2021/11/17 17:06:00 by mverger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	to_find;

	to_find = (unsigned char)c;
	i = 0;
	while (s[i])
		i++;
	if (to_find == '\0')
	{
		while (to_find != *s)
			s++;
		return ((char *)s);
	}
	while (i > 0)
	{
		i--;
		if (to_find == s[i])
			return ((char *)&s[i]);
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", strrchr("bonjour", 's'));
	printf("%s\n", ft_strrchr("bonjour", 's'));
	return (0);
}*/